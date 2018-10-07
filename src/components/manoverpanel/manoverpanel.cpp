#include "manoverpanel.hpp"

void Manoverpanel::Initialize(void){
  MReq = 0;
  
  Recording_Selection        = false;
  Telemetry_Selection        = false;
  Permanent_Fault            = false;
  
  Recording_Request = new GPIOClass("22");
  Telemetry_Request = new GPIOClass("23");
  
  if(!Recording_Request->export_gpio() | !Telemetry_Request->export_gpio())
    Permanent_Fault = true;
  
  if(!Recording_Request->setdir_gpio("in") | !Telemetry_Request->setdir_gpio("in"))
    Permanent_Fault = true; 
}

void Manoverpanel::Execute(void){
  Is_Serviceable = true;
  
  bool Recording_Current_Value;
  bool Telemetry_Current_Value;
  
  // Read current values and check for errors.
  if(!Recording_Request->getval_gpio(Recording_Current_Value) | !Telemetry_Request->getval_gpio(Telemetry_Current_Value))
    Is_Serviceable = false;
  
  // Inform the requirer (callback) if buttons have been pressed.
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
  if(Permanent_Fault){
    Is_Serviceable = false;
  }

  return Is_Serviceable;
}

void Manoverpanel::Set_Manouver_Requirer(Manouver_Requirer::Manouver_Requirer* Requirer){
 MReq = Requirer; 
}