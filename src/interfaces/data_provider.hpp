#ifndef _data_provider_hpp
#define _data_provider_hpp

#include "data_entry_format.hpp"

class Data_Provider{
  public:
    virtual bool Get_Data(Data_Entry_Type* Data_Entry) = 0;
};

#endif