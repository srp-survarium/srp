; rip = 0x747787

; This patch is broken!
; For some reason after sending a certain number of packages client just stops.
; This behavior doesn't happen in the original.
;
; The last message:
; recv: ClientMessage { sequence_id: 216, remote_sequence_id: 1, remote_ack_bits: 16384, kinds: [ClientPlayerUpdate { unknown: [154, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 148, 70, 0, 0] }, ClientPlayerUpdate { unknown: [153, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 144, 70, 0, 0] }, ClientPlayerUpdate { unknown: [152, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 139, 70, 0, 0] }, ClientPlayerUpdate { unknown: [151, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 138, 70, 0, 0] }, ClientPlayerUpdate { unknown: [150, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 133, 70, 0, 0] }] }


%macro nops 1
%rep %1
    nop
%endrep
%endmacro

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
push      0FFFFFFFh
