ppmd_compressor_impl *__usercall ppmd_compressor_impl::ppmd_compressor_impl@<eax>(
        ppmd_compressor_impl *this@<ecx>,
        int a2@<esi>)
{
  unsigned int i; // eax
  unsigned int v3; // eax
  int v4; // edi
  char v5; // dl
  int v6; // ecx

  *(_DWORD *)a2 = &ppmd_compressor_impl::`vftable';
  ppmd_allocator::ppmd_allocator((ppmd_allocator *)this, (ppmd_allocator *)(a2 + 12));
  *(_DWORD *)(a2 + 7600) = 0;
  *(_BYTE *)(a2 + 4) = 1;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 7604) = 0;
  *(_DWORD *)(a2 + 7608) = 0;
  *(_DWORD *)(a2 + 7612) = 0;
  *(_DWORD *)(a2 + 7616) = 0;
  *(_DWORD *)(a2 + 7620) = 0;
  *(_DWORD *)(a2 + 7624) = 0;
  *(_BYTE *)(a2 + 3596) = 0;
  *(_BYTE *)(a2 + 3597) = 2;
  *(_DWORD *)(a2 + 3598) = &vostok::memory::s_CRT_arena[56169020];
  *(_DWORD *)(a2 + 3602) = &vostok::memory::s_CRT_arena[56169020];
  *(_BYTE *)(a2 + 3606) = (unsigned __int8)&vostok::memory::s_CRT_arena[56169020];
  memset(a2 + 3607, (unsigned __int8 *)6, 0xF5u);
  for ( i = 0; i < 5; ++i )
    *(_BYTE *)(a2 + i + 3852) = i;
  v3 = 5;
  v4 = 1;
  v5 = 5;
  v6 = 1;
  do
  {
    --v6;
    *(_BYTE *)(a2 + v3 + 3852) = v5;
    if ( !v6 )
    {
      v6 = ++v4;
      ++v5;
    }
    ++v3;
  }
  while ( v3 < 0x104 );
  *(_DWORD *)(a2 + 3588) = -2069057649;
  return (ppmd_compressor_impl *)a2;
}
