::
:: Generate COFF files for all classes in the executable
::

if not defined SRP_DIR        set      "SRP_DIR=E:\Projects\srp"
if not defined COFF_DIR       set     "COFF_DIR=%SRP_DIR%\..\vostok-coff-delinker"

if not defined GHIDRA_HOME    set  "GHIDRA_HOME=C:\Program Files\ghidra_11.4_PUBLIC"
if not defined PROJECTS_DIR   set "PROJECTS_DIR=D:\Projects\ghidra"
if not defined SCRIPTS_DIR    set  "SCRIPTS_DIR=%SRP_DIR%\resources\ghidra_scripts"
if not defined OUTPUT_DIR     set   "OUTPUT_DIR=%COFF_DIR%\target"

:: Normalize paths in environment variables
for %%I in ("%SRP_DIR%")      do set "SRP_DIR=%%~fI"
for %%I in ("%COFF_DIR%")     do set "COFF_DIR=%%~fI"

for %%I in ("%GHIDRA_HOME%")  do set "GHIDRA_HOME=%%~fI"
for %%I in ("%PROJECTS_DIR%") do set "PROJECTS_DIR=%%~fI"
for %%I in ("%SCRIPTS_DIR%")  do set "SCRIPTS_DIR=%%~fI"
for %%I in ("%OUTPUT_DIR%")   do set "OUTPUT_DIR=%%~fI"


if not defined PROCESS_ARGS   set "PROCESS_ARGS=-noanalysis -process survarium.exe"
if not defined CLASS_FILTER   set "CLASS_FILTER="

"%GHIDRA_HOME%\support\analyzeHeadless.bat" ^
  "%PROJECTS_DIR%" vostok                   ^
  %PROCESS_ARGS%                            ^
  -scriptPath "%SCRIPTS_DIR%"               ^
  -postScript DelinkProgram.java "%OUTPUT_DIR%" "%CLASS_FILTER%"
