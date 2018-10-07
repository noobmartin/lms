#include "indikatorpanel.hpp"

void Indikatorpanel::Initialize(void){
  Recording                   = false;
  Telemetry                   = false;
  Fault                       = false;
  Permanent_Indication_Fault  = false;
  
  Fault_Indication     = new GPIOClass("4");
  Recording_Indication = new GPIOClass("17");
  Telemetry_Indication = new GPIOClass("21");
  
  if(!Fault_Indication->export_gpio() | !Recording_Indication->export_gpio() | !Telemetry_Indication->export_gpio())
    Permanent_Indication_Fault = true;
  
  if(!Fault_Indication->setdir_gpio("out") | !Recording_Indication->setdir_gpio("out") | !Telemetry_Indication->setdir_gpio("out"))
    Permanent_Indication_Fault = true;
}

void Indikatorpanel::Execute(void){
  Is_Serviceable = true;
  
  // Update indicators and check if it was successful.
  if(!Fault_Indication->setval_gpiob(Fault) | !Recording_Indication->setval_gpiob(Recording) | !Telemetry_Indication->setval_gpiob(Telemetry))
    Is_Serviceable = false;
}

bool Indikatorpanel::Serviceable(void){
  if(Permanent_Indication_Fault)
    Is_Serviceable = false;
    
  return Is_Serviceable;
}

void Indikatorpanel::Indicate_Recording_State(const bool State){
  Recording = State;
}

void Indikatorpanel::Indicate_Telemetry_State(const bool State){
  Telemetry = State;
}

void Indikatorpanel::Indicate_Fault_State(const bool State){
  Fault = State;
}