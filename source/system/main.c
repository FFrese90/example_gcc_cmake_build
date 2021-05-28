////////////////////////////////////////////////////////////////////////////////
/// \file    main.c
/// \date    18.12.2017
/// \author  Fabian Frese
/// \version 00.00.01
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

#include "Modul.h"

#include "Modul_MapOUT.h"
#include "Modul2_MapOUT.h"

/******************************************************************************/
/*** lokaler Bereich ***/
/******************************************************************************/

//------------------------------------------------------------------------------
// lokale Makro-Konstanten
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lokale Strukturen und Typen (struct, enum und typedef)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lokale Daten
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lokale Funktionsmakros
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lokale Funktions Prototypen
//------------------------------------------------------------------------------

void Test_CallBack(uint8_t _u8Value);

//------------------------------------------------------------------------------
// lokale Funktions Definitionen
//------------------------------------------------------------------------------


void Test_CallBack(uint8_t _u8Value)
{
  printf("Der Wert war: %d", _u8Value);
}

/******************************************************************************/
/*** Externer Bereich ***/
/******************************************************************************/

//------------------------------------------------------------------------------
// externe Daten
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// externe Funktionsdefinitionen
//------------------------------------------------------------------------------

// Doku siehe Header
int main(void)
{
  // Variablen
  uint16_t u16Test;

  uint16_t u16TestGlob_Val0 = 0;

  // Start Textausgabe
  printf("###################################\n");
  printf("# UnitTest                        #\n");
  printf("###################################\n");
  printf("\n");

  printf("###################################\n");
  printf("# INIT Module                     #\n");
  printf("###################################\n");
  printf("\n");

  uint16_t u16ResTest0;
  uint16_t u16ResTest0_Val0;
  uint16_t u16ResTest0_Val1;
  uint16_t u16ResTest0_Val2;

  // Sim Value
  uint16_t u16Modul2_Sim_Value0;

  u16ResTest0 = Modul_Init(&u16TestGlob_Val0);

  // Test Modul2 Init
  Modul2_MapOUT_Init(&u16Modul2_Sim_Value0);

  u16TestGlob_Val0 = 0xFFFF;
  
  u16ResTest0_Val0 = Modul_MapOUT_Value0();
  u16ResTest0_Val1 = Modul_MapOUT_Value1();
  u16ResTest0_Val2 = Modul_MapOUT_Value2();

  printf("Test Init 1:");
  if(u16ResTest0 == 0x0001)
  {
    printf("!!! PASS !!!\n");
  }
  else
  {
    printf("!!! FAIL !!!\n");
  }

  printf("Test Init 2:");
  if(u16ResTest0_Val0 == 0xFFFF)
  {
    printf("!!! PASS !!!\n");
  }
  else
  {
    printf("!!! FAIL !!!\n");
  }

  printf("Test Init 3:");
  if(u16ResTest0_Val1 == 1)
  {
    printf("!!! PASS !!!\n");
  }
  else
  {
    printf("!!! FAIL !!! IS: %d\n",u16ResTest0_Val1);
  }

  printf("Test Init 4:");
  if(u16ResTest0_Val2 == 2)
  {
    printf("!!! PASS !!!\n");
  }
  else
  {
    printf("!!! FAIL !!! IS: %d\n",u16ResTest0_Val2);
  }

  printf("\n");
  printf("###################################\n");
  printf("# TEST1  Module Func              #\n");
  printf("###################################\n");
  printf("\n");
  
  uint16_t u16ResTest1;

  u16ResTest1 = Modul_Func(1);

  printf("Test1 1:");
  if(u16ResTest1 == 0x0002)
  {
    printf("!!! PASS !!!\n");
  }
  else
  {
    printf("!!! FAIL !!!\n");
  }
  
  printf("\n");
  printf("###################################\n");
  printf("# TEST2  Module Run               #\n");
  printf("###################################\n");
  printf("\n");

  uint16_t u16RunCounter;
  uint16_t u16ResTest2_Val1;
  uint16_t u16ResTest2_Val2;

  printf("# TEST2  Module Run 1             #\n");
  for(u16RunCounter = 0; u16RunCounter< 30; u16RunCounter++)
  {
    Modul_work_100ms();
  }
  u16ResTest2_Val1 = Modul_MapOUT_State();
  if(u16ResTest2_Val1 == 0x02)
  {
    printf("!!! PASS !!!\n");
  }
  else
  {
    printf("!!! FAIL !!!\n");
  }

  printf("# TEST2  Module Run 2             #\n");
  for(u16RunCounter = 0; u16RunCounter< 100; u16RunCounter++)
  {
    Modul_work_100ms();
  }
  u16ResTest2_Val1 = Modul_MapOUT_State();
  if(u16ResTest2_Val1 == 0x03)
  {
    printf("!!! PASS !!!\n");
  }
  else
  {
    printf("!!! FAIL !!!\n");
  }

  printf("# TEST2  Module Run 3             #\n");
  for(u16RunCounter = 0; u16RunCounter< 1; u16RunCounter++)
  {
    u16Modul2_Sim_Value0 = 0x0001;
    Modul_work_100ms();
  }
  u16ResTest2_Val1 = Modul_MapOUT_State();
  if(u16ResTest2_Val1 == 0x01)
  {
    printf("!!! PASS !!!\n");
  }
  else
  {
    printf("!!! FAIL !!!\n");
  }

  u16ResTest2_Val1 = Modul_MapOUT_Value1();
  u16ResTest2_Val2 = Modul_MapOUT_Value2();
  
  printf("\n");
  printf("###################################\n");
  printf("# UnitTest  beendet               #\n");
  printf("###################################\n");
  printf("\n");
  printf("Enter Druecken zum beenden\n");
  getchar();

  return 0;
}
