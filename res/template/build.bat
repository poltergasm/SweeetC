@echo off
setlocal

set CC=..\..\win64\tcc\tcc.exe
set SDL=..\..\win64\libs\SDL2-2.0.9
set TTF=..\..\win64\libs\SDL2_ttf-2.0.14
set MIXER=..\..\win64\libs\SDL2_mixer-2.0.4
set IMAGE=..\..\win64\libs\SDL2_image-2.0.4
set SWEET=..\..\src
set BIN=..\..\win64\bin

echo %CC%

set PATH=%PATH%;..\..\win64\tcc
set PATH=%PATH%;%BIN%
set PATH=%PATH%;%SDL%\lib
set PATH=%PATH%;%TTF%\lib
set PATH=%PATH%;%MIXER%\lib
set PATH=%PATH%;%IMAGE%\lib
set PATH=%PATH%;%SWEET%

windres game.rc -O coff -o game.res
%CC% -Wl,-subsystem,windows -DSDL_MAIN_HANDLED -I%SWEET% -I%SDL%\include -I%IMAGE%\include -I%MIXER%\include -I%TTF%\include -L%SDL%\lib -L%IMAGE%\lib -L%MIXER%\lib -L%TTF%\lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer game.c -o game.exe game.res
pause