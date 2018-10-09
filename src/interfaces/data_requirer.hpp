#ifndef _data_requirer_hpp
#define _data_requirer_hpp

#include "data_entry_format.hpp"

class Data_Requirer{
  public:
    virtual bool Create_Recording(void) = 0;
    virtual void Put_Data(Data_Entry_Type& Data) = 0;
    virtual bool Close_Recording(void) = 0;
};

#endif