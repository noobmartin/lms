#include <cstdio>
#include <cstring>
#include <mntent.h>

#include "datastav.hpp"

void Datastav::Initialize(void){
  Is_Serviceable = false;
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
  
  FILE* mtab = setmntent("/etc/mtab", "r");
  mntent* entry;
    
  do{
    entry = getmntent(mtab);
    if(entry != NULL){
      if( strcmp(entry->mnt_dir, "/mnt/Datastav") == 0){
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