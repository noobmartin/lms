#ifndef _indicator_provider_hpp
#define _indicator_provider_hpp

namespace Indicator_Provider{
 
  enum Indication_State_Type{
    On,
    Off
  };
  
class Indicator_Provider{
  public:
    virtual void Indicate_Recording_State(const Indication_State_Type State);
    virtual void Indicate_Telemetry_State(const Indication_State_Type State);
    virtual void Indicate_Fault_State(const Indication_State_Type State);
};
  
}

#endif