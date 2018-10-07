#ifndef _manoverpanel_hpp
#define _manoverpanel_hpp

#include "manouver_requirer.hpp"

#include "component_execution_provider.hpp"
#include "component_serviceability_provider.hpp"

#include "gpioclass.hpp"

class Manoverpanel:
  public Component_Execution_Provider,
  public Component_Serviceability_Provider{

  public:
    void Initialize(void);
    void Execute(void);
    
    bool Serviceable(void);
    
    void Set_Manouver_Requirer(Manouver_Requirer::Manouver_Requirer* Requirer);
  private:
    Manouver_Requirer::Manouver_Requirer* MReq;
    
    GPIOClass* Recording_Request;
    GPIOClass* Telemetry_Request;
    
    bool Recording_Selection;
    bool Telemetry_Selection;
    
    bool Is_Serviceable;
    bool Permanent_Fault;
};

#endif