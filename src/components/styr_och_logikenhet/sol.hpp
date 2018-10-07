#ifndef _sol_hpp
#define _sol_hpp

#include "component_execution_provider.hpp"
#include "component_serviceability_provider.hpp"

#include "indicator_provider.hpp"
#include "manouver_requirer.hpp"

#include "databussadapter.hpp"
#include "datastav.hpp"
#include "manoverpanel.hpp"
#include "indikatorpanel.hpp"
#include "telemetreringsmodul.hpp"

typedef enum{
  Unserviceable,
  Recording,
  Not_Recording
}Data_Recording_State_Type;

class Sol:
  public Component_Execution_Provider,
  public Component_Serviceability_Provider,
  public Manouver_Requirer::Manouver_Requirer{

  public:
    void Initialize(void);
    void Execute(void);
    
    bool Serviceable(void);
    
    void Recording_Pressed(void);
    void Telemetry_Pressed(void);
    
  private:
    Databussadapter     DBA;
    Datastav            DS;
    Manoverpanel        MP;
    Indikatorpanel      IP;
    Telemetreringsmodul TM;
    
    bool Recording_Toggle_Requested;
    bool Telemetry_Toggle_Requested;
    bool Fully_Serviceable;
    
    Data_Recording_State_Type Data_Recording_State;
    
    void Data_Recording_Function(void);
    void Telemetry_Function(void);
    
};

#endif