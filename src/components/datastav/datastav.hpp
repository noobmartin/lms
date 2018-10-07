#ifndef _datastav_hpp
#define _datastav_hpp

#include <cstdio>

#include "component_execution_provider.hpp"
#include "component_serviceability_provider.hpp"

#include "data_requirer.hpp"

class Datastav:
  public Component_Execution_Provider,
  public Component_Serviceability_Provider,
  public Data_Requirer{

  public:
    void Initialize(void);
    void Execute(void);
    
    bool Serviceable(void);
    
    bool Create_Recording(void);
    void Put_Data(Data_Entry_Type& Data);
    bool Close_Recording(void);
    
  private:
    bool Is_Mounted(void);
    bool Is_Serviceable;
    bool Success;
    
    FILE* Recording_File;
};

#endif