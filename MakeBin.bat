@REM This batch file converts the .hex file generated when the Arduino IDE compiles your sketch into a .bin file you can put on the SD card for use by avr_boot

REM determine the correct Program Files location, under Windows 64bit this will be %PROGRAMFILES(x86)%, otherwise it will be %PROGRAMFILES%
set programFilesPath="%PROGRAMFILES%"
if "%PROGRAMFILES(x86)%" neq "" set programFilesPath="%PROGRAMFILES(x86)%"

REM set the path to both of the possible locations of avr-objcopy(Arduino IDE 1.6.2 moved the location)
path %programFilesPath%\arduino-nightly\hardware\tools\avr\bin\;%programFilesPath%\Arduino\hardware\tools\avr\bin\;%APPDATA%\Arduino15\packages\arduino\tools\avr-gcc\4.8.1-arduino2\bin;%PATH%

REM delete the last FIRMWARE.BIN file so I can be sure the new one was created successfully
del FIRMWARE.BIN

REM convert the .hex file to binary
avr-objcopy -I ihex -O binary *.hex FIRMWARE.BIN && (
  @echo avr-objcopy successful
) || (
  call :VERTSPACE
  @echo ERROR! avr-objcopy failed
  pause
  exit
)
@echo off
pause
exit
REM pause so that I can see if it was sucessful


REM create vertical space to separate items
:VERTSPACE
@echo(
@echo(
@echo(
@echo(
@echo(
@echo(
@echo(
@echo(
@GOTO :eof
