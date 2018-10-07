#ifndef _indikatorpanel_hpp
#define _indikatorpanel_hpp

#include "component_execution_provider.hpp"
#include "component_serviceability_provider.hpp"

#include "indicator_provider.hpp"

#include "gpioclass.hpp"

class Indikatorpanel:
  public Component_Execution_Provider,
  public Component_Serviceability_Provider,
  public Indicator_Provider::Indicator_Provider{

  public:
    void Initialize(void);
    void Execute(void);
    
    bool Serviceable(void);
    
    void Indicate_Recording_State(const bool State);
    void Indicate_Telemetry_State(const bool State);
    void Indicate_Fault_State(const bool State);
    
  private:
    bool Recording;
    bool Telemetry;
    bool Fault;
    
    bool Permanent_Indication_Fault;
    bool Is_Serviceable;
    
    GPIOClass* Fault_Indication;
    GPIOClass* Recording_Indication;
    GPIOClass* Telemetry_Indication;
};

#endif