
#include "Modul_MapOUT.h"

static uint16_t * pu16Value0;
static uint16_t * pu16Value1;
static uint16_t * pu16Value2;
static uint8_t *  pu8State;

uint16_t Modul_MapOUT_Init( uint16_t * _pu16Value0,
                            uint16_t * _pu16Value1,
                            uint16_t * _pu16Value2,
                            uint8_t * _pu8State)
{
  pu16Value0 = _pu16Value0;
  pu16Value1 = _pu16Value1;
  pu16Value2 = _pu16Value2;
  pu8State   = _pu8State;

  return 0x0001;
}

uint16_t Modul_MapOUT_Value0(void)
{
  return * pu16Value0;
}

uint16_t Modul_MapOUT_Value1(void)
{
  return * pu16Value1;
}

uint16_t Modul_MapOUT_Value2(void)
{
  return * pu16Value2;
}

uint8_t Modul_MapOUT_State(void)
{
  return * pu8State;
}