void __cdecl process_1(unsigned int index, const unsigned int count)
{
  void *v2; // esp
  _BYTE *v3; // eax
  unsigned int v4; // esi
  char *v5; // ecx
  char v6; // dl
  char *i; // edi
  _BYTE *v8; // eax
  _BYTE v9[3]; // [esp+1h] [ebp-Bh] BYREF

  v2 = alloca(1028 * index + 1);
  v3 = v9;
  v4 = 0;
  if ( index )
  {
    while ( 1 )
    {
      v5 = *(char **)(count + 4 * v4);
      v6 = *v5;
      for ( i = v5 + 1024; *v5; ++v3 )
      {
        if ( v5 >= i )
          break;
        ++v5;
        *v3 = v6;
        v6 = *v5;
      }
      *v3 = 93;
      ++v4;
      ++v3;
      if ( v4 >= index )
        break;
      *v3 = 91;
      v8 = v3 + 1;
      *v8++ = 13;
      *v8 = 10;
      v3 = v8 + 1;
    }
  }
  *v3 = 0;
}
