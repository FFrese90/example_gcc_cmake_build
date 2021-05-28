mkdir bin
mkdir abs
gcc source\modul\Modul2_MapOUT.c -o bin\Modul2_MapOUT.o -c
gcc source\modul\Modul_MapOUT.c -o bin\Modul_MapOUT.o -c
gcc source\modul\Modul_MapIN.c -o bin\Modul_MapIN.o -c 
gcc source\modul\Modul.c -o bin\Modul.o -c
gcc -Isource\modul source\system\main.c -o abs\Applikation bin\Modul.o bin\Modul_MapOUT.o bin\Modul_MapIN.o bin\Modul2_MapOUT.o

pause 