@echo off
set "project_name="
set /p project_name="Enter project name: "

if NOT "%project_name%"=="" (
    mkdir ..\games\%project_name%
    copy ..\res\template\* ..\games\%project_name%\
)

if "%project_name%"=="" (
    echo No name specified. Aborting.
)
pause