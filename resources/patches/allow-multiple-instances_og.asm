; rip = 0x7aff90

bits 32

call      0FFF26490h
test      al,al
jne       short 00000011h
mov       eax,1
ret       10h
