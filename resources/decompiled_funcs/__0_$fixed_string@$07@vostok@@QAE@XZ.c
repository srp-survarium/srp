void __usercall vostok::fixed_string<8>::fixed_string<8>(vostok::fixed_string<8> *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_DWORD *)(a2 + 8) = a2 + 20;
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 12) = 0;
}
