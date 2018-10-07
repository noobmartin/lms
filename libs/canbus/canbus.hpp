/*
 * Author: Alexander Rajula
 * E-mail: superrajula@gmail.com
 * Description:
 *   This class is an abstraction layer hiding the fact that communication
 *   is performed by using regular POSIX sockets.
 *
 * Kudos to:
 * 1) https://www.kernel.org/doc/Documentation/networking/can.txt
 * 2) SocketCAN - The official CAN API of the Linux kernel
 *	Marc Kleine-Budde, Pengutronix
 */

#ifndef _canbus_hpp_
#define _canbus_hpp_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>

#include <linux/can.h>
#include <linux/can/raw.h>
#include <linux/can/bcm.h>

namespace cannet{

#define MAX_BUSNAME_SIZE 	256
#define MAX_CYCLIC_TX_FRAMES	256

struct frame_list_node{
  can_frame* this_frame;
  frame_list_node* next_frame_list_node;
};

class canbus{
  private:
    int bus_socket;

    struct can_frame read_frame;
    struct can_filter receive_frame_filter;

    struct sockaddr_can addr;
    struct ifreq ifr;
    
    char busname[MAX_BUSNAME_SIZE];

    bool Success;
    bool Bus_Open;
  public:
    canbus();
    ~canbus();

    /* 
     * For the bind/connect operations to function, they will need a valid interface name.
     * This is the interface name which is output using the ifconfig command.
     */
    bool set_busname(const unsigned size, const char* busname);

    /* 
     * If you're not interested in listening to all the gossip on the bus, you may set a
     * frame filter, containing both CAN ID and CAD payload filter.
     */
    void set_receive_frame_filter(const unsigned int can_id, const unsigned int frame_mask);
   
    bool open_bus(void);
    bool close_bus(void);

    int receive(can_frame* frame);
    
    bool bus_is_open(void);
};

}

#endif
