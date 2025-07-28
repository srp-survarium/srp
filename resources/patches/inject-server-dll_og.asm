; rip = 0x785d55

bits 32

cmp       byte [esp+24h],0
je        near 00000094h
mov       ecx,[esp+14h]
mov       eax,4F210h
push      ecx
push      eax
lea       esi,[esp+78h]
mov       [esp+78h],edi
call      0FF87C7DBh
mov       esi,[9CB990h]
add       esi,60h
call      dword [7F4088h]
cmp       [esi+20h],eax
jne       short 00000042h
lea       ecx,[esp+70h]
call      0FF87DCFBh
jmp       short 0000006Eh
mov       eax,2
call      0FFFA1B6Bh
mov       esi,[9CB990h]
lea       edx,[esp+70h]
add       esi,60h
push      edx
mov       ecx,esi
