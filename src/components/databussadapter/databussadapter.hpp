#ifndef _databussadapter_hpp
#define _databussadapter_hpp

#include <net/if.h>
#include <netinet/in.h>

#include "component_execution_provider.hpp"
#include "component_serviceability_provider.hpp"
#include "data_provider.hpp"
#include "data_entry_format.hpp"

#include "canbus.hpp"
#include "lawicel-canusb.hpp"

class Databussadapter:
  public Component_Execution_Provider,
  public Component_Serviceability_Provider,
  public Data_Provider{

  public:
    void Initialize(void);
    void Execute(void);
    
    bool Serviceable(void);
    
    bool Get_Data(Data_Entry_Type* Data_Entry);
    
  private:
    bool   Is_Serviceable;
    struct ifreq ifr;
    int    sock;
    cannet::canbus Bus;
    canusb_devices::lawicel_canusb Adapter;
};

#endif
