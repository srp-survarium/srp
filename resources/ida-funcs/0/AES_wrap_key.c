int __cdecl AES_wrap_key(
        aes_key_st *key,
        const unsigned __int8 *iv,
        unsigned __int8 *out,
        const __m128i *in,
        unsigned int inlen)
{
  unsigned __int8 *v5; // edi
  unsigned int v6; // ebx
  const unsigned __int8 *v7; // eax
  int v8; // edx
  int *v9; // esi
  unsigned int v10; // edi
  int v11; // ecx
  int v12; // edx
  int v13; // edx
  int v15; // [esp+8h] [ebp-1Ch]
  unsigned __int8 v16[4]; // [esp+10h] [ebp-14h] BYREF
  int v17; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int v19; // [esp+1Ch] [ebp-8h]

  v5 = out;
  if ( (inlen & 7) != 0 || inlen < 8 )
    return -1;
  v6 = 1;
  memcpy((int)(out + 8), in, inlen);
  v7 = iv;
  if ( !iv )
    v7 = default_iv;
  v8 = *((_DWORD *)v7 + 1);
  *(_DWORD *)v16 = *(_DWORD *)v7;
  v17 = v8;
  v15 = 6;
  do
  {
    v9 = (int *)(v5 + 8);
    v10 = ((inlen - 1) >> 3) + 1;
    do
    {
      v11 = v9[1];
      v18 = *v9;
      v19 = v11;
      AES_encrypt(v16, v16, key);
      HIBYTE(v17) ^= v6;
      if ( v6 > 0xFF )
      {
        BYTE2(v17) ^= BYTE1(v6);
        BYTE1(v17) ^= BYTE2(v6);
        LOBYTE(v17) = HIBYTE(v6) ^ v17;
      }
      v12 = v19;
      *v9 = v18;
      v9[1] = v12;
      ++v6;
      v9 += 2;
      --v10;
    }
    while ( v10 );
    v5 = out;
    --v15;
  }
  while ( v15 );
  v13 = v17;
  *(_DWORD *)out = *(_DWORD *)v16;
  *((_DWORD *)out + 1) = v13;
  return inlen + 8;
}
