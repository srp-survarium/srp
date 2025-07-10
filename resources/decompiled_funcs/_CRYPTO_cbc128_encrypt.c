void __cdecl CRYPTO_cbc128_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int len,
        const void *key,
        unsigned __int8 *ivec,
        void (__cdecl *block)(const unsigned __int8 *, unsigned __int8 *, const void *))
{
  unsigned __int8 *v6; // eax
  unsigned int v7; // ebx
  unsigned __int8 *v10; // ebp
  int v11; // ebp
  const unsigned __int8 *v12; // eax
  int v13; // edx
  int v14; // ebx
  bool v15; // zf
  int v16; // edx
  unsigned int v17; // eax
  unsigned __int8 v18; // cl
  int v19; // ebp
  unsigned __int8 *v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // [esp+10h] [ebp-14h]

  v6 = ivec;
  v7 = len;
  v10 = ivec;
  if ( len >= 0x10 )
  {
    v22 = len >> 4;
    do
    {
      v11 = v10 - in;
      v12 = in;
      v13 = 4;
      do
      {
        v14 = *(_DWORD *)v12 ^ *(_DWORD *)&v12[v11];
        v12 += 4;
        --v13;
        *(_DWORD *)&v12[out - in - 4] = v14;
      }
      while ( v13 );
      block(out, out, key);
      v10 = out;
      v7 = len - 16;
      in += 16;
      out += 16;
      v15 = v22-- == 1;
      len -= 16;
    }
    while ( !v15 );
    v6 = ivec;
  }
  if ( v7 )
  {
    do
    {
      v16 = v10 - in;
      v17 = 0;
      while ( v17 < v7 )
      {
        out[v17] = in[v17] ^ in[v17 + v16];
        v7 = len;
        if ( v17 + 1 >= len )
        {
          ++v17;
          break;
        }
        out[v17 + 1] = in[v17 + 1] ^ v10[v17 + 1];
        if ( v17 + 2 >= len )
        {
          v17 += 2;
          break;
        }
        out[v17 + 2] = v10[v17 + 2] ^ in[v17 + 2];
        if ( v17 + 3 >= len )
        {
          v17 += 3;
          break;
        }
        v18 = in[v17 + 3] ^ v10[v17 + 3];
        v17 += 4;
        out[v17 - 1] = v18;
        if ( v17 >= 0x10 )
          goto LABEL_22;
        v16 = v10 - in;
      }
      if ( v17 < 0x10 )
      {
        v19 = v10 - out;
        v20 = &out[v17];
        v21 = 16 - v17;
        do
        {
          *v20 = v20[v19];
          ++v20;
          --v21;
        }
        while ( v21 );
      }
LABEL_22:
      block(out, out, key);
      v10 = out;
      if ( v7 <= 0x10 )
        break;
      v7 -= 16;
      in += 16;
      out += 16;
      len = v7;
    }
    while ( v7 );
    v6 = ivec;
  }
  *(_DWORD *)v6 = *(_DWORD *)v10;
  *((_DWORD *)v6 + 1) = *((_DWORD *)v10 + 1);
  *((_DWORD *)v6 + 2) = *((_DWORD *)v10 + 2);
  *((_DWORD *)v6 + 3) = *((_DWORD *)v10 + 3);
}
