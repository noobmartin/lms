#include "indikatorpanel.hpp"

void Indikatorpanel::Initialize(void){
  Recording = false;
  Telemetry = false;
  Fault    = false;
}

void Indikatorpanel::Execute(void){
  
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