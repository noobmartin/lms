#ifndef _component_execution_provider_hpp
#define _component_execution_provider_hpp

class Component_Execution_Provider{
  public:
    virtual void Initialize(void) = 0;
    virtual void Execute(void)    = 0;
  private:
};

#endif
