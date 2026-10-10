; SPDX-License-Identifier: GPL-3.0-or-later
; rip = 0x6f1e77

%macro nops 1
  %rep %1
    nop
  %endrep
%endmacro

bits 32

nops      6               ; add       ecx,1388h ; 5
mov       [esi+0C0h],ecx
jmp       000000CEh
push      96D1C8h
lea       ecx,[esp+10h]
call      0FF90F949h
mov       edx,[esi+0A8h]
mov       eax,[edx+3F4h]
nops      5               ; add       eax,1388h
mov       [esi+0C0h],eax
jmp       000000CEh
push      96D1DCh
lea       ecx,[esp+10h]
call      0FF90F949h
mov       ecx,[esi+0A8h]
mov       edx,[ecx+3F4h]
nops      6               ; add       edx,1388h
mov       [esi+0C0h],edx
jmp       short 000000CEh
push      96D1FCh
lea       ecx,[esp+10h]
call      0FF90F949h
mov       eax,[esi+0A8h]
mov       ecx,[eax+3F4h]
add       ecx,2710h
mov       [esi+0C0h],ecx
jmp       short 000000CEh
push      96D220h
jmp       short 000000C5h
push      96D22Ch
jmp       short 000000C5h
push      96D248h
lea       ecx,[esp+10h]
call      0FF90F949h
mov       edx,[esi+0A8h]
mov       eax,[edx+3F4h]
nops      5               ; add       eax,1388h
