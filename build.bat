@echo off

call set_env.bat

if not exist build mkdir build
pushd build

cmake -G "Ninja" ../source
if not %ERRORLEVEL% == 0 (
  call:return
)

cmake --build .
if not %ERRORLEVEL% == 0 (
  call:return
)



pause