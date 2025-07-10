void __usercall vostok::fixed_string<16>::fixed_string<16>(vostok::fixed_string<16> *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_DWORD *)(a2 + 8) = a2 + 28;
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 12) = 0;
}
