void __cdecl CRYPTO_cfb128_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int len,
        const void *key,
        unsigned __int8 *ivec,
        unsigned int *num,
        int enc,
        void (__cdecl *block)(const unsigned __int8 *, unsigned __int8 *, const void *))
{
  unsigned int v8; // esi
  unsigned int i; // ebx
  int v10; // eax
  int v11; // ebp
  unsigned __int8 *v12; // eax
  unsigned int v13; // ecx
  unsigned __int8 *v14; // eax
  int v15; // esi
  unsigned int v16; // ebp
  const unsigned __int8 *v17; // ebx
  unsigned __int8 v18; // al
  int v19; // ebx
  unsigned __int8 *v20; // eax
  unsigned int v21; // ecx
  int v22; // esi
  bool v23; // zf
  int v24; // ebx
  int v25; // ecx
  unsigned __int8 *v26; // eax
  unsigned __int8 *v27; // edi
  unsigned __int8 v28; // cl
  unsigned int v29; // [esp+10h] [ebp-4h]
  unsigned int v30; // [esp+10h] [ebp-4h]
  int v31; // [esp+30h] [ebp+1Ch]
  int v32; // [esp+30h] [ebp+1Ch]

  v8 = *num;
  if ( !enc )
  {
    v16 = len;
    v17 = in;
    if ( v8 )
    {
      do
      {
        if ( !v16 )
          break;
        v18 = *v17;
        *out = *v17 ^ ivec[v8];
        ivec[v8] = v18;
        ++v17;
        --v16;
        v8 = ((_BYTE)v8 + 1) & 0xF;
        ++out;
      }
      while ( v8 );
      in = v17;
      len = v16;
    }
    if ( v16 >= 0x10 )
    {
      v32 = out - ivec;
      v30 = v16 >> 4;
      do
      {
        block(ivec, ivec, key);
        if ( v8 < 0x10 )
        {
          v19 = v17 - out;
          v20 = &ivec[v8];
          v21 = ((15 - v8) >> 2) + 1;
          do
          {
            v22 = *(_DWORD *)&v20[v32 + v19];
            *(_DWORD *)&v20[v32] = v22 ^ *(_DWORD *)v20;
            *(_DWORD *)v20 = v22;
            v20 += 4;
            --v21;
          }
          while ( v21 );
          v16 = len;
          v17 = in;
        }
        out += 16;
        v32 += 16;
        v16 -= 16;
        v17 += 16;
        v8 = 0;
        v23 = v30-- == 1;
        len = v16;
        in = v17;
      }
      while ( !v23 );
    }
    if ( v16 )
    {
      block(ivec, ivec, key);
      v24 = v17 - out;
      v25 = out - ivec;
      v26 = &ivec[v8];
      v8 += v16;
      while ( 1 )
      {
        v27 = &v26[v25];
        v28 = v26[v25 + v24];
        *v27 = v28 ^ *v26;
        --v16;
        *v26++ = v28;
        if ( !v16 )
          break;
        v25 = out - ivec;
      }
    }
    goto LABEL_30;
  }
  for ( i = len; v8; ++in )
  {
    if ( !i )
      break;
    ivec[v8] ^= *in;
    *out = ivec[v8];
    --i;
    v8 = ((_BYTE)v8 + 1) & 0xF;
    ++out;
  }
  if ( i >= 0x10 )
  {
    v31 = in - ivec;
    v29 = i >> 4;
    v10 = 16 * (i >> 4);
    v11 = out - ivec;
    out += v10;
    in += v10;
    do
    {
      block(ivec, ivec, key);
      if ( v8 < 0x10 )
      {
        v12 = &ivec[v8];
        v13 = ((15 - v8) >> 2) + 1;
        do
        {
          *(_DWORD *)v12 ^= *(_DWORD *)&v12[v31];
          *(_DWORD *)&v12[v11] = *(_DWORD *)v12;
          v12 += 4;
          --v13;
        }
        while ( v13 );
      }
      v31 += 16;
      i -= 16;
      v11 += 16;
      v8 = 0;
      --v29;
    }
    while ( v29 );
  }
  if ( !i )
  {
LABEL_30:
    *num = v8;
    return;
  }
  block(ivec, ivec, key);
  v14 = &ivec[v8];
  v15 = i + v8;
  do
  {
    *v14 ^= v14[in - ivec];
    --i;
    v14[out - ivec] = *v14;
    ++v14;
  }
  while ( i );
  *num = v15;
}
