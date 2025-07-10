void __usercall vostok::fixed_string<512>::fixed_string<512>(vostok::fixed_string<512> *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_DWORD *)(a2 + 8) = a2 + 524;
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 12) = 0;
}
