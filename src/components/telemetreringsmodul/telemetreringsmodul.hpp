#ifndef _telemetreringsmodul_hpp
#define _telemetreringsmodul_hpp

#include "component_execution_provider.hpp"
#include "component_serviceability_provider.hpp"

class Telemetreringsmodul:
  public Component_Execution_Provider,
  public Component_Serviceability_Provider{

  public:
    void Initialize(void);
    void Execute(void);
    
    bool Serviceable(void);
    
};

#endif