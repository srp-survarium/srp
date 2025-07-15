unsigned int __usercall vostok::strings::detail::tuples::size@<eax>(
        vostok::strings::detail::tuples *this@<ecx>,
        unsigned int *a2@<eax>)
{
  unsigned int v2; // ebx
  unsigned int v3; // esi
  unsigned int *v4; // ecx
  unsigned int v5; // edx
  unsigned int v6; // edx
  int v7; // edi
  unsigned int v8; // ecx
  char *strings[6]; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int v11; // [esp+24h] [ebp-4h]

  v2 = a2[1];
  v3 = a2[12];
  v11 = v2;
  if ( v3 > 1 )
  {
    v4 = a2 + 3;
    v5 = v3 - 1;
    do
    {
      v2 += *v4;
      v4 += 2;
      --v5;
    }
    while ( v5 );
    v11 = v2;
  }
  if ( v2 > 0x80000 )
  {
    v6 = 0;
    v7 = -1;
    v8 = 0;
    if ( v3 )
    {
      do
      {
        strings[v8] = (char *)a2[2 * v8];
        if ( v7 == -1 )
        {
          v6 += a2[2 * v8 + 1];
          if ( v6 > 0x80000 )
            v7 = v8;
        }
        ++v8;
      }
      while ( v8 < v3 );
      v2 = v11;
    }
    process((char *)v7, v3, (const char **)strings);
  }
  return v2 + 1;
}
