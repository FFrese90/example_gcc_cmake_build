@echo off

if exist build rmdir /s /q build
if exist doc rmdir /s /q doc
if exist output rmdir /s /q output

echo clean successful

:return
if [%1]==[] (
  :: wait for user input if no argument is supplied to the script
  echo.
  pause
)

exit /B %ERRORLEVEL%
