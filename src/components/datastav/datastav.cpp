#include <cstdio>
#include <cstring>
#include <mntent.h>
#include <string>
#include <chrono>
#include <ctime>

#include "datastav.hpp"

const char* mtabs     = "/etc/mtab";
const char* locations = "/mnt/Datastav";

void Datastav::Initialize(void){
  Is_Serviceable = false;
  Recording_File = NULL;
}

void Datastav::Execute(void){
 
  if(Is_Mounted()){
    Is_Serviceable = true;
  }
  else{
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

void Datastav::Put_Data(const void* Data, unsigned int Data_Size){
  if(Recording_File != NULL){
    fwrite(Data, 1, Data_Size, Recording_File);
  }
}

bool Datastav::Create_Recording(void){
  if(Is_Serviceable){
    std::string Recording_Filename(locations);
    Recording_Filename.append("/");

    std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    Recording_Filename.append(std::ctime(&t));
    
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