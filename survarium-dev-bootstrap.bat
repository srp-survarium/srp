:: SPDX-License-Identifier: GPL-3.0-or-later
::
:: Bootstrap all required survarium servers
::

if not defined SRP_DIR  set "SRP_DIR=%~dp0"
if "%SRP_DIR:~-1%"=="\" set "SRP_DIR=%SRP_DIR:~0,-1%"

if not defined SURVARIUM_BIN      set     "SURVARIUM_BIN=D:\Projects\Survarium\binaries\win32"
if not defined IDA_HOME           set          "IDA_HOME=C:\Program Files\IDA Free 9.1"
if not defined SYS_INTERNALS_DIR  set "SYS_INTERNALS_DIR=C:\Program Files\SysinternalsSuite"


:: Normalize paths in environment variables
for %%I in ("%SRP_DIR%")            do set "SRP_DIR=%%~fI"
for %%I in ("%SURVARIUM_BIN%")      do set "SURVARIUM_BIN=%%~fI"
for %%I in ("%IDA_HOME%")           do set "IDA_HOME=%%~fI"
for %%I in ("%SYS_INTERNALS_DIR%")  do set "SYS_INTERNALS_DIR=%%~fI"

if exist "%SYS_INTERNALS_DIR%\" (
  start "" "%SYS_INTERNALS_DIR%\procexp64.exe"
)

tasklist /FI "IMAGENAME eq ida.exe" | find /I "ida.exe" >nul
if errorlevel 1 (
    start "" "%IDA_HOME%\ida.exe"
)

wt ^
new-tab -d "%SRP_DIR%"       --title "nvim"           powershell -NoExit -Command "nvim +Ex"                                                                           ; ^
new-tab -d "%SRP_DIR%"       --title "cargo build"    powershell -NoExit -Command "$c='cargo check'                                                  \; iex $c"        ; ^
new-tab -d "%SRP_DIR%"       --title "lobby server"   powershell -NoExit -Command "$c='cargo run --bin lobby-server'                                 \; iex $c"        ; ^
new-tab -d "%SRP_DIR%"       --title "match server"   powershell -NoExit -Command "$c='cargo run --bin match-server'                                 \; iex $c"        ; ^
new-tab -d "%SRP_DIR%"       --title "login server"   powershell -NoExit -Command "$c='cargo run --bin login-server'                                 \; iex $c"        ; ^
new-tab -d "%SRP_DIR%"       --title "browser server" powershell -NoExit -Command "$c='cargo run --bin browser-server'                               \; iex $c"        ; ^
new-tab -d "%SURVARIUM_BIN%" --title "survarium"      powershell -NoExit -Command "$c='.\survarium.exe -no_splash_screen -client=''127.0.0.1:1234''' \; Write-Host $c" ; ^
new-tab -d "%SRP_DIR%"       --title "notes"          powershell -NoExit -Command "nvim resources/notes/dev-notes.md"                                                  ; ^
focus-tab -t 0
