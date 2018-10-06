#ifndef _component_serviceability_provider_hpp
#define _component_serviceability_provider_hpp

class Component_Serviceability_Provider{
  public:
    virtual bool Serviceable(void) = 0;
  private:
};

#endif
