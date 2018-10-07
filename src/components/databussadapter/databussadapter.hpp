#ifndef _databussadapter_hpp
#define _databussadapter_hpp

#include <net/if.h>
#include <netinet/in.h>

#include "component_execution_provider.hpp"
#include "component_serviceability_provider.hpp"
#include "data_provider.hpp"

#include "canbus.hpp"

class Databussadapter:
  public Component_Execution_Provider,
  public Component_Serviceability_Provider,
  public Data_Provider{

  public:
    void Initialize(void);
    void Execute(void);
    
    bool Serviceable(void);
    
    void Get_Data(const unsigned int Storage_Size, void* Storage, unsigned int* Transferred_Data, unsigned int* Frame_Identifier);
    
  private:
    bool   Is_Serviceable;
    struct ifreq ifr;
    int    sock;
    cannet::canbus Bus;
};

#endif
