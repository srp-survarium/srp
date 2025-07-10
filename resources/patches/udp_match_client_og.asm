; rip = 0x747787

bits 32

je        short 007477C0h
mov       eax,[ebp+14h]
mov       ecx,[eax+2Ch]
mov       [ebp-2Ch],ecx
mov       edx,[ebp-2Ch]
imul      edx,6
mov       [ebp-34h],edx
mov       dword [ebp-30h],0FAh
mov       eax,[ebp-30h]
cmp       eax,[ebp-34h]
sbb       ecx,ecx
neg       ecx
neg       ecx
mov       edx,[ebp-30h]
sub       edx,[ebp-34h]
and       edx,ecx
mov       eax,[ebp-30h]
sub       eax,edx
mov       [ebp-78h],eax
jmp       short 007477C7h
mov       dword [ebp-78h],1F4h
push      969D2Ch
push      21h
mov       ecx,[ebp-78h]
push      ecx
push      1D4C0h
