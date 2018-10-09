#ifndef _data_entry_format_hpp
#define _data_entry_format_hpp

#include <cstdint>
#include <linux/can.h>

#pragma pack(push, 1)

// @TODO: Tycker inte om att slösa data såhär.
typedef struct{
  uint8_t  Year;
  uint8_t  Month;
  uint16_t  Day;
  uint8_t  Hour;
  uint8_t  Minute;
  uint8_t  Second;
  uint32_t Microseconds;
  can_frame Data;
}Data_Entry_Type;

#pragma pack(pop)

#endif