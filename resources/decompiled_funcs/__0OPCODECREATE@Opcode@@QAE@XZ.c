void __usercall Opcode::OPCODECREATE::OPCODECREATE(Opcode::OPCODECREATE *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)(a2 + 8) = 0x7FFFFFFF;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 8) = 34;
  *(_DWORD *)(a2 + 4) = 1;
  *(_BYTE *)(a2 + 12) = 1;
  *(_BYTE *)(a2 + 13) = 1;
  *(_BYTE *)(a2 + 14) = 0;
  *(_BYTE *)(a2 + 15) = 0;
}
