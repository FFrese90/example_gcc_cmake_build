#ifndef ___MODULE_MAPOUT_H
#define ___MODULE_MAPOUT_H
#include <stdint.h>

uint16_t Modul_MapOUT_Init( uint16_t * _pu16Value0,
                            uint16_t * _pu16Value1,
                            uint16_t * _pu16Value2,
                            uint8_t * _pu8State);

uint16_t Modul_MapOUT_Value0(void);

uint16_t Modul_MapOUT_Value1(void);

uint16_t Modul_MapOUT_Value2(void);

uint8_t Modul_MapOUT_State(void);

#endif // ___MODULE_MAPOUT_H