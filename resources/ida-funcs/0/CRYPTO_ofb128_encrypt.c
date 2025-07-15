void __cdecl CRYPTO_ofb128_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int len,
        const void *key,
        unsigned __int8 *ivec,
        unsigned int *num,
        void (__cdecl *block)(const unsigned __int8 *, unsigned __int8 *, const void *))
{
  unsigned int i; // esi
  unsigned int v9; // eax
  int v10; // ebp
  unsigned __int8 *v11; // eax
  unsigned int v12; // ecx
  int v13; // edx
  unsigned __int8 *v14; // eax
  unsigned int v15; // esi
  unsigned int v16; // [esp+10h] [ebp-4h]
  int v17; // [esp+20h] [ebp+Ch]

  for ( i = *num; i; ++in )
  {
    if ( !len )
      break;
    *out = *in ^ ivec[i];
    --len;
    i = ((_BYTE)i + 1) & 0xF;
    ++out;
  }
  if ( len >= 0x10 )
  {
    v17 = in - ivec;
    v16 = len >> 4;
    v9 = 16 * (len >> 4);
    v10 = out - ivec;
    out += v9;
    in += v9;
    do
    {
      block(ivec, ivec, key);
      if ( i < 0x10 )
      {
        v11 = &ivec[i];
        v12 = ((15 - i) >> 2) + 1;
        do
        {
          v13 = *(_DWORD *)v11 ^ *(_DWORD *)&v11[v17];
          v11 += 4;
          --v12;
          *(_DWORD *)&v11[v10 - 4] = v13;
        }
        while ( v12 );
      }
      v17 += 16;
      len -= 16;
      v10 += 16;
      i = 0;
      --v16;
    }
    while ( v16 );
  }
  if ( len )
  {
    block(ivec, ivec, key);
    v14 = &ivec[i];
    v15 = len + i;
    do
    {
      --len;
      v14[out - ivec] = *v14 ^ v14[in - ivec];
      ++v14;
    }
    while ( len );
    *num = v15;
  }
  else
  {
    *num = i;
  }
}
