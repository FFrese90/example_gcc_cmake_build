
#include "Modul_MapIN.h"   // Der eigene Header

#include "Modul2_MapOUT.h"  // Output from Modul2


uint16_t Modul_MapIN_Init(void)
{
  // Noithing
  return 0x0001;
}


uint16_t MapIN_ButtonPressed(void)
{
  return Modul2_MapOUT_Value0();
}
