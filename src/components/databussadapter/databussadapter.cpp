#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <cstdio>

#include "databussadapter.hpp"

void Databussadapter::Initialize(void){
  Is_Serviceable = false;

  memset(&ifr, 0, sizeof(ifr));
  strcpy(ifr.ifr_name, "slcan0");
  sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
}

void Databussadapter::Execute(void){
  // Check if the slcan0 interface is up.
  if(ioctl(sock, SIOCGIFINDEX, &ifr) == 0){
    Is_Serviceable = true;
  }
  else{
    perror("SIOCGIFFLAGS");
    Is_Serviceable = false;
  }
}

bool Databussadapter::Serviceable(void){
  return Is_Serviceable;
}


int main(){
  Databussadapter DBA;
  DBA.Initialize();
  do{
    DBA.Execute();
    if(DBA.Serviceable()){
      printf("Serviceable\n");
    }
    else{
      printf("Not serviceable\n");
    }
    sleep(1);
  }while(1);
}

