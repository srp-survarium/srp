int __cdecl EVP_DecodeBlock(unsigned __int8 *t, const unsigned __int8 *f, int n)
{
  const unsigned __int8 *v3; // edx
  int v4; // ebp
  char v6; // cl
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // al
  _BYTE *v11; // edx
  char v12; // bl
  int v13; // ecx
  int v14; // ebx
  int v15; // eax
  unsigned __int8 *v16; // esi
  int v17; // ecx
  int v18; // [esp+8h] [ebp-4h]
  int v19; // [esp+18h] [ebp+Ch]

  v3 = f;
  v4 = 0;
  v18 = 0;
  if ( data_ascii2bin[*f & 0x7F] == 0xE0 )
  {
    do
    {
      if ( n <= 0 )
        break;
      v6 = *++v3;
      --n;
    }
    while ( data_ascii2bin[v6 & 0x7F] == 0xE0 );
  }
  for ( ; n > 3; --n )
  {
    if ( (data_ascii2bin[v3[n - 1] & 0x7F] | 0x13) != 0xF3 )
      break;
  }
  if ( n % 4 )
    return -1;
  if ( n <= 0 )
    return v18;
  while ( 1 )
  {
    v9 = *v3;
    v10 = v3[1];
    v11 = v3 + 1;
    v12 = v11[1];
    v11 += 2;
    v19 = data_ascii2bin[v12 & 0x7F];
    v13 = data_ascii2bin[v9 & 0x7F];
    v14 = data_ascii2bin[*v11 & 0x7F];
    v15 = data_ascii2bin[v10 & 0x7F];
    v3 = v11 + 1;
    if ( (v13 & 0x80u) != 0 || (v15 & 0x80u) != 0 || (v19 & 0x80u) != 0 || (v14 & 0x80u) != 0 )
      break;
    v18 += 3;
    v16 = t + 1;
    v17 = v14 | ((v19 | ((v15 | (v13 << 6)) << 6)) << 6);
    *(v16 - 1) = BYTE2(v17);
    *v16++ = BYTE1(v17);
    *v16 = v17;
    v4 += 4;
    t = v16 + 1;
    if ( v4 >= n )
      return v18;
  }
  return -1;
}
