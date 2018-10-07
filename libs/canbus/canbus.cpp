/*
 * Author: Alexander Rajula
 * E-mail: superrajula@gmail.com
 * Descrpition:
 *   Implementation file for the canbus class.
 */

#include "canbus.hpp"

namespace cannet{

canbus::canbus(){
  bus_socket = 0x0;
  memset(&ifr, 0x0, sizeof(ifr));
  memset(&addr, 0x0, sizeof(addr));
  memset(&read_frame, 0x0, sizeof(read_frame));
  memset(&receive_frame_filter, 0x0, sizeof(receive_frame_filter));
  memset(busname, 0x0, MAX_BUSNAME_SIZE);
  Bus_Open = false;
}

canbus::~canbus(){

}

bool canbus::set_busname(const unsigned size, const char* given_busname){
  if( (given_busname == 0) || size < 1){
    perror("canbus::set_busname");
    Success = false;
  }
  else{
    memcpy(busname, given_busname, size);
    Success = true;
  }
  
  return Success;
}

void canbus::set_receive_frame_filter(const unsigned int can_id, const unsigned int frame_mask){
  receive_frame_filter.can_id = can_id;
  receive_frame_filter.can_mask = frame_mask;
  setsockopt(bus_socket, SOL_CAN_RAW, CAN_RAW_FILTER, &receive_frame_filter, sizeof(receive_frame_filter));
}

bool canbus::open_bus(void){
  if( (bus_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0){
    perror("canbus::open_bus");
    Success = false;
  }
  else{
    strcpy(ifr.ifr_name, busname);
    ioctl(bus_socket, SIOCGIFINDEX, &ifr);

    addr.can_ifindex = ifr.ifr_ifindex;
    addr.can_family = PF_CAN;

    if(bind(bus_socket, (struct sockaddr*)&addr, sizeof(addr)) < 0){
      perror("canbus::open_bus");
      Success = false;
    }
    else{
      Success = true;
      Bus_Open = true;
    }
  }
  
  return Success;
}

bool canbus::close_bus(void){
  if(close(bus_socket) == 0){
    Success = true;
    Bus_Open = false;
  }
  else{
    perror("canbus::close_bus");
    Success = false;
  }
  
  return Success;
}

int canbus::receive(const unsigned size, char* buf, unsigned int* can_id){
  int read_bytes = read(bus_socket, &read_frame, sizeof(read_frame));

  if(read_bytes < 0){
    perror("canbus::receive");
    return -1;
  }
  else{
    *can_id = read_frame.can_id;
    memcpy(buf, read_frame.data, read_frame.can_dlc);
  }

  return read_frame.can_dlc;
}

bool canbus::bus_is_open(void){
  return Bus_Open;
}

}
