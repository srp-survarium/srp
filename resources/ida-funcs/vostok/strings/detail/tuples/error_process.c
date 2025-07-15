void __fastcall vostok::strings::detail::tuples::error_process(vostok::strings::detail::tuples *this, int a2)
{
  unsigned int v2; // edi
  unsigned int v3; // ecx
  int v4; // esi
  unsigned int i; // eax
  const char *strings[6]; // [esp+8h] [ebp-18h] BYREF

  v2 = *(_DWORD *)(a2 + 48);
  v3 = 0;
  v4 = -1;
  for ( i = 0; i < v2; ++i )
  {
    strings[i] = *(const char **)(a2 + 8 * i);
    if ( v4 == -1 )
    {
      v3 += *(_DWORD *)(a2 + 8 * i + 4);
      if ( v3 > 0x80000 )
        v4 = i;
    }
  }
  process_1(v2, (const unsigned int)strings);
}
