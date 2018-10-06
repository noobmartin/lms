#include "manoverpanel.hpp"

void Manoverpanel::Initialize(void){
  MReq = 0;
  
  Recording_Selection = false;
  Telemetry_Selection = false;
  
  Recording_Request = new GPIOClass("22");
  Telemetry_Request = new GPIOClass("23");
  
  Recording_Request->export_gpio();
  Telemetry_Request->export_gpio();
  
  Recording_Request->setdir_gpio("in");
  Telemetry_Request->setdir_gpio("in");
}

void Manoverpanel::Execute(void){
  bool Recording_Current_Value;
  bool Telemetry_Current_Value;
  
  Recording_Request->getval_gpio(Recording_Current_Value);
  Telemetry_Request->getval_gpio(Telemetry_Current_Value);
  
  if(Recording_Current_Value != Recording_Selection){
    MReq->Recording_Pressed();
    Recording_Selection = Recording_Current_Value;
  }
  
  if(Telemetry_Current_Value != Telemetry_Selection){
    MReq->Telemetry_Pressed();  
    Telemetry_Selection = Telemetry_Current_Value;
  }
  
}

bool Manoverpanel::Serviceable(void){
  return true;
}

void Manoverpanel::Set_Manouver_Requirer(Manouver_Requirer::Manouver_Requirer* Requirer){
 MReq = Requirer; 
}