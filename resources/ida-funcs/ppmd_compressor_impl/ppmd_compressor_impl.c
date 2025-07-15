ppmd_compressor_impl *__usercall ppmd_compressor_impl::ppmd_compressor_impl@<eax>(
        ppmd_compressor_impl *this@<ecx>,
        int a2@<esi>)
{
  unsigned int v2; // ebx
  unsigned int v3; // ecx
  int v4; // edx
  char v5; // al
  int v6; // edi

  *(_DWORD *)a2 = &ppmd_compressor_impl::`vftable';
  ppmd_allocator::ppmd_allocator((ppmd_allocator *)this, (ppmd_allocator *)(a2 + 12));
  v2 = 0;
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
  *(_DWORD *)(a2 + 3598) = &s_ui_commands_allocator.m_buffer[52630180];
  *(_DWORD *)(a2 + 3602) = &s_ui_commands_allocator.m_buffer[52630180];
  *(_BYTE *)(a2 + 3606) = (unsigned __int8)&s_ui_commands_allocator.m_buffer[52630180];
  memset(a2 + 3607, 6, 0xF5u);
  v3 = 5;
  do
  {
    *(_BYTE *)(a2 + v2 + 3852) = v2;
    ++v2;
  }
  while ( v2 < 5 );
  v4 = 1;
  v5 = 5;
  v6 = 1;
  do
  {
    --v4;
    *(_BYTE *)(a2 + v3 + 3852) = v5;
    if ( !v4 )
    {
      v4 = ++v6;
      ++v5;
    }
    ++v3;
  }
  while ( v3 < 0x104 );
  *(_DWORD *)(a2 + 3588) = -2069057649;
  return (ppmd_compressor_impl *)a2;
}
