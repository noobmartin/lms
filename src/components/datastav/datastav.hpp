#ifndef _datastav_hpp
#define _datastav_hpp

#include "component_execution_provider.hpp"
#include "component_serviceability_provider.hpp"

class Datastav:
  public Component_Execution_Provider,
  public Component_Serviceability_Provider{

  public:
    void Initialize(void);
    void Execute(void);
    
    bool Serviceable(void);
    
  private:
    bool Is_Mounted(void);
    bool Is_Serviceable;
    FILE* mtab;
    mntent* entry;
};

#endif