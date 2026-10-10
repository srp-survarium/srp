:: SPDX-License-Identifier: GPL-3.0-or-later
::
:: Generate COFF files for all classes in the executable
::

::
:: Repository paths can be overwritten in case they are defined in unrelated locations
::
if not defined SRP_DIR  set "SRP_DIR=%~dp0"
if "%SRP_DIR:~-1%"=="\" set "SRP_DIR=%SRP_DIR:~0,-1%"

if not defined COFF_DIR       set      "COFF_DIR=%SRP_DIR%\..\vostok-coff-delinker"
if not defined VOSTOK_DIR     set    "VOSTOK_DIR=%SRP_DIR%\..\vostok"
if not defined SURVARIUM_BIN  set "SURVARIUM_BIN=D:\Projects\Survarium\binaries\win32"


if not defined GHIDRA_HOME    set   "GHIDRA_HOME=C:\Program Files\ghidra_11.4_PUBLIC"
if not defined PROJECTS_DIR   set  "PROJECTS_DIR=%VOSTOK_DIR%\binaries\temp_ghidra_project"
if not defined SCRIPTS_DIR    set   "SCRIPTS_DIR=%SRP_DIR%\resources\ghidra_scripts"
if not defined OUTPUT_DIR     set    "OUTPUT_DIR=%COFF_DIR%\target"


:: Normalize paths in environment variables
for %%I in ("%GHIDRA_HOME%")  do set "GHIDRA_HOME=%%~fI"
for %%I in ("%PROJECTS_DIR%") do set "PROJECTS_DIR=%%~fI"
for %%I in ("%SCRIPTS_DIR%")  do set "SCRIPTS_DIR=%%~fI"
for %%I in ("%OUTPUT_DIR%")   do set "OUTPUT_DIR=%%~fI"


set "EXE_FILE=%SURVARIUM_BIN%\survarium.exe"
if not defined PROCESS_ARGS   set "PROCESS_ARGS=-import %EXE_FILE% -overwrite -deleteproject"
if not defined CLASS_FILTER   set "CLASS_FILTER="

if not exist "%PROJECTS_DIR%" (
    mkdir "%PROJECTS_DIR%"
)

"%GHIDRA_HOME%\support\analyzeHeadless.bat" ^
  "%PROJECTS_DIR%" vostok                   ^
  %PROCESS_ARGS%                            ^
  -scriptPath "%SCRIPTS_DIR%"               ^
  -postScript DelinkProgram.java "%OUTPUT_DIR%" "%CLASS_FILTER%"
