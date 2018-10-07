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
  
  Bus.set_busname(7, "slcan0");
}

void Databussadapter::Execute(void){
  // Check if the interface is up.
  if(ioctl(sock, SIOCGIFINDEX, &ifr) == 0){
    if(!Bus.bus_is_open()){
      Bus.open_bus();
    }
    
    Is_Serviceable = true;
  }
  else{
    if(Bus.bus_is_open()){
      Bus.close_bus();
    }
    
    Is_Serviceable = false;
  }
  
}

bool Databussadapter::Serviceable(void){
  return Is_Serviceable;
}

void Databussadapter::Get_Data(const unsigned int Storage_Size, void* Storage, unsigned int* Transferred_Data, unsigned int* Frame_Identifier){
  if(Is_Serviceable && Bus.bus_is_open()){
    unsigned int can_id;
    int Received_Bytes = Bus.receive(Storage_Size, (char*)Storage, Frame_Identifier);
    if(Received_Bytes > 0){
      *Transferred_Data = Received_Bytes;
    }
  }
}