
#include "Modul2_MapOUT.h"

static uint16_t * pu16Value0;

uint16_t Modul2_MapOUT_Init( uint16_t * _pu16Value0)
{
  pu16Value0 = _pu16Value0;

  return 0x0001;
}

uint16_t Modul2_MapOUT_Value0(void)
{
  return * pu16Value0;
}
