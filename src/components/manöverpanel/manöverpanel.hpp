#ifndef _manöverpanel_hpp
#define _manöverpanel_hpp

#include "component_execution_provider.hpp"
#include "component_serviceability_provider.hpp"

class Manöverpanel:
  public Component_Execution_Provider,
  public Component_Serviceability_Provider{

  public:
    void Initialize(void);
    void Execute(void);
    
    bool Serviceable(void);
    
};

#endif