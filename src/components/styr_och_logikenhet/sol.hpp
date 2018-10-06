#ifndef _sol_hpp
#define _sol_hpp

#include "component_execution_provider.hpp"
#include "component_serviceability_provider.hpp"

#include "indicator_provider.hpp"
#include "manouver_requirer.hpp"

#include "databussadapter.hpp"
#include "datastav.hpp"

class Sol:
  public Component_Execution_Provider,
  public Component_Serviceability_Provider{

  public:
    void Initialize(void);
    void Execute(void);
    
    bool Serviceable(void);
    
  private:
    Databussadapter DBA;
    Datastav        DS;
    
};

#endif