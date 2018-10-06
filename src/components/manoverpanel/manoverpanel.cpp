#include "manoverpanel.hpp"

void Manoverpanel::Initialize(void){
  MReq = 0;
}

void Manoverpanel::Execute(void){
  
}

bool Manoverpanel::Serviceable(void){
  return true;
}

void Manoverpanel::Set_Manouver_Requirer(Manouver_Requirer::Manouver_Requirer* Requirer){
 MReq = Requirer; 
}