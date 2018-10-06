#ifndef _manouver_requirer_hpp
#define _manouver_requirer_hpp

namespace Manouver_Requirer{
 
class Manouver_Requirer{
  public:
    virtual void Recording_Pressed(void) = 0;
    virtual void Telemetry_Pressed(void) = 0;
};
  
}

#endif
