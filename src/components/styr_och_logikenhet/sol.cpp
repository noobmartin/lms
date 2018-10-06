#include "sol.hpp"

#include <cstdio>

void Sol::Initialize(void){
  DBA.Initialize();
  DS.Initialize();
  MP.Initialize();
  MP.Set_Manouver_Requirer(this);
  IP.Initialize();
}

void Sol::Execute(void){
  DBA.Execute();
  DS.Execute();
  MP.Execute();
  IP.Execute();
}

bool Sol::Serviceable(void){
  if(DBA.Serviceable()){
    printf("DBA is serviceable\n");
  }
  else{
    printf("DBA is not serviceable\n");
  }
  if(DS.Serviceable()){
    printf("DS is serviceable\n");
  }
  else{
    printf("DS is not serviceable\n");
  }
  if(MP.Serviceable()){
    printf("MP is serviceable\n");
  }
  else{
    printf("MP is not serviceable\n");
  }
  if(IP.Serviceable()){
    printf("IP is serviceable\n");
  }
  else{
    printf("IP is not serviceable\n");
  }
  
  return (DBA.Serviceable() && DS.Serviceable() && MP.Serviceable() && IP.Serviceable() );
}

void Sol::Recording_Pressed(void){
  printf("SOL: Received recording pressed");
}

void Sol::Telemetry_Pressed(void){
  printf("SOL: Received telemetry pressed");
}