#include "indikatorpanel.hpp"

void Indikatorpanel::Initialize(void){
  Recording = false;
  Telemetry = false;
  Fault     = false;
  
  Fault_Indication = new GPIOClass("4");
  Recording_Indication = new GPIOClass("17");
  Telemetry_Indication = new GPIOClass("21");
  
  Fault_Indication->export_gpio();
  Recording_Indication->export_gpio();
  Telemetry_Indication->export_gpio();
  
  Fault_Indication->setdir_gpio("out");
  Recording_Indication->setdir_gpio("out");
  Telemetry_Indication->setdir_gpio("out");
}

void Indikatorpanel::Execute(void){
  Fault_Indication->setval_gpiob(Fault);
  Recording_Indication->setval_gpiob(Recording);
  Telemetry_Indication->setval_gpiob(Telemetry);
}

bool Indikatorpanel::Serviceable(void){
  return true;
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