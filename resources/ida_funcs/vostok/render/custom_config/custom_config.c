void __usercall vostok::render::custom_config::custom_config(vostok::render::custom_config *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_BYTE *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 9) = 1;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_WORD *)(a2 + 24) = 0;
  *(_WORD *)(a2 + 26) = 0;
  *(_DWORD *)(a2 + 28) = 0;
}
