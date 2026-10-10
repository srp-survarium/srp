:: SPDX-License-Identifier: GPL-3.0-or-later
@echo off
setlocal

if not exist build mkdir build

cl /nologo /O2 /W4 /MT /DWIN32_LEAN_AND_MEAN /D_CRT_SECURE_NO_WARNINGS ^
  /LD /Fobuild\hit_report.obj /Febuild\srp_hit_report.dll hit_report.cpp ^
  /link /NOLOGO /OUT:build\srp_hit_report.dll kernel32.lib
if errorlevel 1 exit /b 1

cl /nologo /O2 /W4 /MT /DWIN32_LEAN_AND_MEAN /D_CRT_SECURE_NO_WARNINGS ^
  /Fobuild\loader.obj /Febuild\srp_hit_report_loader.exe loader.cpp ^
  /link /NOLOGO /OUT:build\srp_hit_report_loader.exe kernel32.lib
if errorlevel 1 exit /b 1

echo Built client hit-report patch in build\
