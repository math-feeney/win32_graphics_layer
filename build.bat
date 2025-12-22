@echo off
setlocal EnableDelayedExpansion

REM -MT(as opposed to -MD) is the specifier to tell the compiler to link statically against the C runtime library

REM === configuration ===
set COMP_FLAGS=/nologo /W4 /Od /Zi /MT
set LINK_FLAGS=/nologo /OPT:REF user32.lib gdi32.lib Winmm.lib

REM ensure build directory exists
IF NOT EXIST .\build mkdir .\build

REM === compile step ===
echo === Compiling translation units ===
set OBJS=

for %%f in (src\*.cpp) do (
    echo %%f
    cl %COMP_FLAGS% /c %%f /Iinclude /Fo:build\%%~nf.obj
    if errorlevel 1 exit /b 1
    set OBJS=!OBJS! build\%%~nf.obj
)

REM === link step ===
echo === Linking ===
cl %OBJS% /Fe:build\app.exe /link %LINK_FLAGS%
if errorlevel 1 exit /b 1

echo === Build successful ===


REM NOTE: can do this to examine stuff:  
REM         dumpbin /symbols build\somefile.obj
REM         dumpbin /imports build\app.exe
REM         dumpbin /headers build\app.exe


