
#include "Modul.h"
#include "Modul_MapOUT.h"
#include "Modul_MapIN.h"

#include <stdio.h>  
#include <stdint.h>

uint16_t u16ModGlob_Val1 = 0;
uint16_t u16ModGlob_Val2 = 0;

uint8_t  u8State = 0;

uint16_t Modul_Func(uint16_t _u8Data)
{
  return _u8Data + 1;
}

int Modul_Init(uint16_t * _pu16Value0)
{
  uint16_t ret = 0x0000;

  if (1 == 2)
  {
    return 0xFF00;
  }

  ret |= Modul_MapIN_Init();

  ret |= Modul_MapOUT_Init( _pu16Value0,
                            &u16ModGlob_Val1,
                            &u16ModGlob_Val2,
                            &u8State);
  
  u16ModGlob_Val1 = 1;
  u16ModGlob_Val2 = 2;

  return ret;
}

int Modul_work_100ms(void)
{
  uint16_t u16Timer_100ms = 0;

  switch(u8State)
  {
    default:
    case 0:
      if (u16Timer_100ms++ >= 30)
      {
        // Timer clearen
        u16Timer_100ms = 0;
        // Nextstate
        u8State = 1;
      }
      else
      {
        // Nichts
      }
      break;
    case 1:
      if (u16Timer_100ms++ >= 100)
      {
        // Timer clearen
        u16Timer_100ms = 0;
        // Nextstate
        u8State = 2;
      }
      else
      {
        // Nichts
      }
      break;
    case 2:
      if (MapIN_ButtonPressed())
      {
        // Nextstate
        u8State = 3;
      }
      else
      {
        // Nichts
      }
      break;
    case 3:
      // ENDE
      break;
  }

}