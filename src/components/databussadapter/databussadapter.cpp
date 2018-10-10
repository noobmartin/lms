#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <cstdio>
#include <chrono>
#include <time.h>

#include "databussadapter.hpp"

void Databussadapter::Initialize(void){
  Is_Serviceable = false;

  Adapter.auto_setup();
  
  memset(&ifr, 0, sizeof(ifr));
  strcpy(ifr.ifr_name, "slcan0");
  sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
  
  Bus.set_busname(7, "slcan0");
}

void Databussadapter::Execute(void){
  // @TODO: Re-write this logic to allow hot-plugging of CAN-USB adapter.
  
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

bool Databussadapter::Get_Data(Data_Entry_Type* Data){
  bool Success = false;
  
  if(Is_Serviceable && Bus.bus_is_open()){
    unsigned int can_id;
    int Received_Bytes = Bus.receive(&Data->Data);
    if(Received_Bytes > 0){
      std::chrono::system_clock::time_point timestamp = std::chrono::system_clock::now();
      time_t t = std::chrono::system_clock::to_time_t(timestamp);
      tm utc = *gmtime(&t);

      // Why not mix C and C++ for the fuck of it.
      struct timespec ts;
      timespec_get(&ts, TIME_UTC);
      
      Data->Year   = utc.tm_year; 
      Data->Month  = utc.tm_mon;
      Data->Day    = utc.tm_mday;
      Data->Hour   = utc.tm_hour;
      Data->Minute = utc.tm_min;
      Data->Second = utc.tm_sec;
      Data->Microseconds = ts.tv_nsec; 
      
      Success = true;
    }
  }
  
  return Success;
}