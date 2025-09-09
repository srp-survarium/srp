::
:: Generate COFF files for all classes in the executable
::

if not defined SRP_DIR        set "SRP_DIR=E:\Projects\srp"
if not defined COFF_DIR       set "COFF_DIR=E:\Projects\vostok-coff-delinker"

if not defined GHIDRA_HOME    set "GHIDRA_HOME=C:\Program Files\ghidra_11.4_PUBLIC"
if not defined PROJECTS_DIR   set "PROJECTS_DIR=D:\Projects\ghidra"
if not defined SCRIPTS_DIR    set "SCRIPTS_DIR=%SRP_DIR%\resources\ghidra_scripts"

if not defined PROCESS_ARGS   set "PROCESS_ARGS=-noanalysis -process survarium.exe"
if not defined OUTPUT_DIR     set "OUTPUT_DIR=%COFF_DIR%\target"
if not defined CLASS_FILTER   set "CLASS_FILTER="

"%GHIDRA_HOME%\support\analyzeHeadless.bat" ^
  "%PROJECTS_DIR%" vostok                   ^
  %PROCESS_ARGS%                            ^
  -scriptPath "%SCRIPTS_DIR%"               ^
  -postScript DelinkProgram.java "%OUTPUT_DIR%" "%CLASS_FILTER%"
