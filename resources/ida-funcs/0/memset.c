void __cdecl memset(int dst, int value, int count)
{
  int v3; // edx
  int v4; // eax
  _BYTE *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count )
  {
    LOBYTE(v4) = value;
    if ( (_BYTE)value || (unsigned int)count < 0x100 || !__sse2_available )
    {
      v5 = (_BYTE *)dst;
      if ( (unsigned int)count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = value;
          --v6;
        }
        while ( v6 );
      }
      v4 = 16843009 * (unsigned __int8)value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( !v8 || (memset32(v5, v4, v8), v5 += 4 * v8, v3) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 );
      }
    }
    else
    {
      _VEC_memzero(dst, value, count);
    }
  }
}
