#include "sol.hpp"

#include <cstdio>

void Sol::Initialize(void){
  DBA.Initialize();
  DS.Initialize();
}

void Sol::Execute(void){
  DBA.Execute();
  DS.Execute();
  
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
}

bool Sol::Serviceable(void){
  return (DBA.Serviceable() && DS.Serviceable() );
}