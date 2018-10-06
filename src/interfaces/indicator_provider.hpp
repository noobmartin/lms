#ifndef _indicator_provider_hpp
#define _indicator_provider_hpp

namespace Indicator_Provider{

  
class Indicator_Provider{
  public:
    virtual void Indicate_Recording_State(const bool State) = 0;
    virtual void Indicate_Telemetry_State(const bool State) = 0;
    virtual void Indicate_Fault_State(const bool State) = 0;
};
  
}

#endif