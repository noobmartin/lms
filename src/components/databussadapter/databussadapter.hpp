#ifndef _databussadapter_hpp
#define _databussadapter_hpp

#include <net/if.h>
#include <netinet/in.h>

#include "component_execution_provider.hpp"
#include "component_serviceability_provider.hpp"

class Databussadapter:
  public Component_Execution_Provider,
  public Component_Serviceability_Provider{

  public:
    void Initialize(void);
    void Execute(void);
    
    bool Serviceable(void);
    
  private:
    bool Is_Serviceable;
    struct ifreq ifr;
    int sock;
};

#endif
