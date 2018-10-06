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
  
  mtab = setmntent("/etc/mtab", "r");
    
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

int main(){
  Datastav D;
  D.Initialize();
  do{
    D.Execute();
    if(D.Serviceable()){
      printf("Serviceable\n");
    }
    else{
      printf("Not serviceable\n");
    }
  }while(1);
}