#include <cstdio>
#include <cstring>
#include <mntent.h>
#include <string>
#include <chrono>
#include <ctime>
#include <sys/mount.h>
#include <unistd.h>

#include "datastav.hpp"

const char* mtabs     = "/etc/mtab";
const char* locations = "/media/pi/DATASTAV";
const char* device    = "/dev/sda1";

void Datastav::Initialize(void){
  Is_Serviceable = false;
  Recording_File = NULL;
}

void Datastav::Execute(void){
 
  if(Is_Mounted()){
    Is_Serviceable = true;
  }
  else{
    //mount(device, locations, "vfat", 0, "");
    Is_Serviceable = false;    
  }

}

bool Datastav::Is_Mounted(void){
  bool Mounted = false;
  
  FILE* mtab = setmntent(mtabs, "r");
  mntent* entry;
    
  do{
    entry = getmntent(mtab);
    if(entry != NULL){
      if( strcmp(entry->mnt_dir, locations) == 0){
        Mounted = true;
      }
    }
  }while(entry != NULL);
  
  fclose(mtab);
  
  return Mounted;
}

bool Datastav::Serviceable(void){
  return Is_Serviceable;
}

void Datastav::Put_Data(Data_Entry_Type& Data){
  if(Recording_File != NULL){
    fwrite(&Data, 1, sizeof(Data_Entry_Type), Recording_File);
  }
}

bool Datastav::Create_Recording(void){
  if(Is_Serviceable){
    std::string Recording_Filename(locations);
    Recording_Filename.append("/");

    char time_string[100];
    std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    strftime(time_string, 100, "%Y%m%d%H%M%S", localtime(&t));

    Recording_Filename.append(time_string);
    
    Recording_File = fopen(Recording_Filename.c_str(), "a");
    if(Recording_File == NULL){
      perror("Datastav::Create_Recording");
      Success = false;
    }
    else{
      Success = true;
    }
  }
  else{
    Success = false; 
  }
  
  return Success;
}

bool Datastav::Close_Recording(void){
  if(Recording_File == NULL){
   Success = true; 
  }
  else{
    if(fclose(Recording_File) == 0){
      Success = true;
      Recording_File = NULL;
    }
    else{
      perror("Datastav::Close_Recording");
      Success = false;
    }
  }
  
  return Success;
}
