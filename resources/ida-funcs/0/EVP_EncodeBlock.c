int __cdecl EVP_EncodeBlock(unsigned __int8 *t, const unsigned __int8 *f, int dlen)
{
  int v4; // edi
  int i; // ebp
  int v7; // edx
  unsigned int v8; // edx
  unsigned __int8 *v9; // ecx
  _BYTE *v10; // ecx
  unsigned int v11; // edx
  unsigned __int8 *v12; // ecx
  unsigned __int8 *v13; // ecx
  unsigned __int8 v14; // dl
  int result; // eax

  v4 = dlen;
  for ( i = 0; v4 > 0; f += 3 )
  {
    v7 = *f;
    if ( v4 < 3 )
    {
      v11 = v7 << 16;
      if ( v4 == 2 )
        v11 |= f[1] << 8;
      *t = data_bin2ascii[(v11 >> 18) & 0x3F];
      v12 = t + 1;
      *v12 = data_bin2ascii[(v11 >> 12) & 0x3F];
      v13 = v12 + 1;
      if ( v4 == 1 )
        v14 = 61;
      else
        v14 = data_bin2ascii[(v11 >> 6) & 0x3F];
      *v13 = v14;
      v10 = v13 + 1;
      *v10 = 61;
    }
    else
    {
      v8 = f[2] | ((f[1] | (v7 << 8)) << 8);
      *t = data_bin2ascii[(v8 >> 18) & 0x3F];
      t[1] = data_bin2ascii[(v8 >> 12) & 0x3F];
      v9 = t + 2;
      *v9 = data_bin2ascii[(v8 >> 6) & 0x3F];
      v10 = v9 + 1;
      *v10 = data_bin2ascii[v8 & 0x3F];
    }
    v4 -= 3;
    t = v10 + 1;
    i += 4;
  }
  result = i;
  *t = 0;
  return result;
}
