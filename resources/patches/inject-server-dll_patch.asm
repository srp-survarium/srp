; SPDX-License-Identifier: GPL-3.0-or-later
; rip = 0x785d55

%macro nops 1
  %rep %1
    nop
  %endrep
%endmacro

bits 32

call store_server_path
  db        'E:\Projects\srp\target\i686-pc-windows-msvc\debug\match_server.dll', 0

store_server_path:
  call      dword [7F4044h] ; LoadLibraryA

wait_loop:
  push      120000
  call      dword [7F408Ch] ; Sleep
jmp wait_loop

nops 1
