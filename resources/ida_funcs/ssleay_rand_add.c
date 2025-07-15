void __usercall ssleay_rand_add(unsigned int a1@<edi>, char *buf, int num, long double add)
{
  BOOL v4; // ebx
  signed int v5; // edi
  int v6; // ecx
  bool v7; // cc
  int v8; // ebp
  signed int v9; // esi
  const env_md_st *v10; // eax
  signed int v11; // eax
  unsigned int v12; // edi
  int i; // eax
  char v14; // cl
  char v15; // cl
  BOOL v17; // [esp+4h] [ebp-48h]
  crypto_threadid_st id; // [esp+Ch] [ebp-40h] BYREF
  int v20; // [esp+14h] [ebp-38h] BYREF
  int v21; // [esp+18h] [ebp-34h]
  env_md_ctx_st ctx; // [esp+1Ch] [ebp-30h] BYREF
  int data; // [esp+34h] [ebp-18h] BYREF
  _DWORD v24[4]; // [esp+38h] [ebp-14h]

  if ( crypto_lock_rand )
  {
    CRYPTO_THREADID_current(&id);
    CRYPTO_lock(a1, 5, 19, ".\\crypto\\rand\\md_rand.c", 218);
    v4 = CRYPTO_THREADID_cmp(&locking_threadid, &id) == 0;
    v17 = v4;
    CRYPTO_lock(a1, 6, 19, ".\\crypto\\rand\\md_rand.c", 220);
    if ( v4 )
      goto LABEL_4;
  }
  else
  {
    v17 = 0;
    v4 = 0;
  }
  CRYPTO_lock(a1, 9, 18, ".\\crypto\\rand\\md_rand.c", 225);
LABEL_4:
  v20 = md_count[0];
  v21 = md_count[1];
  data = *(_DWORD *)md;
  v5 = state_index;
  v6 = num + state_index;
  v7 = num + state_index < 1023;
  v24[0] = *(_DWORD *)&md[4];
  v24[1] = *(_DWORD *)&md[8];
  v24[2] = *(_DWORD *)&md[12];
  v24[3] = *(_DWORD *)&md[16];
  state_index += num;
  if ( v7 )
  {
    if ( state_num < 1023 && v6 > state_num )
      state_num = v6;
  }
  else
  {
    state_index = 1023
                * (((int)(((unsigned __int64)(2145384445LL * v6) >> 32) - v6) >> 9)
                 + ((unsigned int)(((unsigned __int64)(2145384445LL * v6) >> 32) - v6) >> 31))
                + v6;
    state_num = 1023;
  }
  md_count[1] += num / 20 + (num % 20 > 0);
  if ( !v4 )
    CRYPTO_lock(v5, 10, 18, ".\\crypto\\rand\\md_rand.c", 257);
  EVP_MD_CTX_init(&ctx);
  if ( num > 0 )
  {
    v8 = num;
    id.ptr = (void *)((num - 1) / 0x14u + 1);
    do
    {
      v9 = v8;
      if ( v8 > 20 )
        v9 = 20;
      v10 = EVP_sha1();
      EVP_DigestInit_ex(&ctx, v10, 0);
      EVP_DigestUpdate(&ctx, &data, 0x14u);
      if ( v9 + v5 - 1023 <= 0 )
      {
        EVP_DigestUpdate(&ctx, &state[v5], v9);
      }
      else
      {
        EVP_DigestUpdate(&ctx, &state[v5], 1023 - v5);
        EVP_DigestUpdate(&ctx, state, v9 + v5 - 1023);
      }
      EVP_DigestUpdate(&ctx, buf, v9);
      EVP_DigestUpdate(&ctx, &v20, 8u);
      EVP_DigestFinal_ex(&ctx, (unsigned __int8 *)&data, 0);
      ++v21;
      v11 = 0;
      buf += v9;
      if ( v9 > 0 )
      {
        do
        {
          state[v5++] ^= *((_BYTE *)&v24[-1] + v11);
          if ( v5 >= 1023 )
            v5 = 0;
          ++v11;
        }
        while ( v11 < v9 );
      }
      v8 -= 20;
      --id.ptr;
    }
    while ( id.ptr );
    v4 = v17;
  }
  EVP_MD_CTX_cleanup(&ctx);
  v12 = a1;
  if ( !v4 )
    CRYPTO_lock(a1, 9, 18, ".\\crypto\\rand\\md_rand.c", 308);
  for ( i = 0; i < 20; i += 5 )
  {
    md[i] ^= *((_BYTE *)&v24[-1] + i);
    v14 = *((_BYTE *)&data + i + 2);
    md[i + 1] ^= *((_BYTE *)&data + i + 1);
    md[i + 2] ^= v14;
    v15 = *((_BYTE *)v24 + i);
    md[i + 3] ^= *((_BYTE *)&data + i + 3);
    md[i + 4] ^= v15;
  }
  if ( entropy < 32.0 )
    entropy = entropy + add;
  if ( !v4 )
    CRYPTO_lock(v12, 10, 18, ".\\crypto\\rand\\md_rand.c", 319);
}
