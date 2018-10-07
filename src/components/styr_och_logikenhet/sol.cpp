#include "sol.hpp"

#include <cstdio>

void Sol::Initialize(void){
  DBA.Initialize();
  DS.Initialize();
  MP.Initialize();
  MP.Set_Manouver_Requirer(this);
  IP.Initialize();
  TM.Initialize();
  
  Data_Recording_State = Unserviceable;
  Fully_Serviceable = false;
}

void Sol::Execute(void){
  DBA.Execute();
  DS.Execute();
  MP.Execute();
  IP.Execute();
  TM.Execute();
  
  Data_Recording_Function();
  Telemetry_Function();
  
  Fully_Serviceable = DBA.Serviceable() && DS.Serviceable() && MP.Serviceable() && IP.Serviceable() && TM.Serviceable();
  
  IP.Indicate_Fault_State(Fully_Serviceable);
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
  if(TM.Serviceable()){
    printf("TM is serviceable\n");
  }
  else{
    printf("TM is not serviceable\n");
  }
  
  return Fully_Serviceable;
}

void Sol::Recording_Pressed(void){
  Recording_Toggle_Requested = true;
}

void Sol::Telemetry_Pressed(void){
  Telemetry_Toggle_Requested = true;
}

void Sol::Data_Recording_Function(void){
  if(!DBA.Serviceable() && !DS.Serviceable()){
    Data_Recording_State = Unserviceable;
    DS.Close_Recording();
  }
  else{
    if(Data_Recording_State == Recording){
      IP.Indicate_Recording_State(true);
      
      // @TODO: Hämta data från DBA och tryck ner på DS.
      char Data[1024];
      unsigned int Retreived_Data = 0;
      unsigned int CAN_ID = 0;
      DBA.Get_Data(1024, Data, &Retreived_Data, &CAN_ID);
      DS.Put_Data(Data, Retreived_Data);
      
      if(Recording_Toggle_Requested){
        Data_Recording_State = Not_Recording;
        
        DS.Close_Recording();
      }
    }
    else if(Data_Recording_State == Not_Recording){
      IP.Indicate_Recording_State(false);
      if(Recording_Toggle_Requested){
        Data_Recording_State = Recording;
        
        DS.Create_Recording();
      }
    }
    
  }
}

void Sol::Telemetry_Function(void){
  
}