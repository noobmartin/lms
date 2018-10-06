#include "indikatorpanel.hpp"

Indikatorpanel::Indikatorpanel(void){
  Recording = false;
  Telemetry = false;
  Faulte    = false;
}

Indikatorpanel::~Indikatorpanel(void){
  
}

Indikatorpanel::Initialize(void){
  
}

Indikatorpanel::Execute(void){
  
}

bool Indikatorpanel::Serviceable(void){
  
}

void Indikatorpanel::Indicate_Recording_State(const Indication_State_Type State){
  switch(State){
   case On:
     Recording = true;
     break;
   case Off:
     Recording = false;
     break;
  }
}

void Indikatorpanel::Indicate_Telemetry_State(const Indication_State_Type State){
  switch(State){
    case On:
      Telemetry = true;
     break;
   case Off:
     Telemetry = false;
     break;
  }
}

void Indikatorpanel::Indicate_Fault_State(const Indication_State_Type State){
  switch(State){
   case On:
     Fault = true;
     break;
   case Off:
     Fault = false;
     break;
  }  
}