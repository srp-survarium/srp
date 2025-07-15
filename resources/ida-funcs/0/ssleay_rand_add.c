void __usercall ssleay_rand_add(int a1@<edi>, int a2@<ebx>, char *buf, int num, long double add)
{
  BOOL v5; // ebx
  int v6; // edi
  int v7; // ecx
  bool v8; // cc
  int v9; // ebp
  int v10; // esi
  const env_md_st *v11; // eax
  int v12; // eax
  int v13; // edi
  int i; // eax
  char v15; // cl
  char v16; // cl
  BOOL v18; // [esp+4h] [ebp-48h]
  crypto_threadid_st id; // [esp+Ch] [ebp-40h] BYREF
  int v21; // [esp+14h] [ebp-38h]
  int v22; // [esp+18h] [ebp-34h]
  env_md_ctx_st ctx; // [esp+1Ch] [ebp-30h] BYREF
  int data; // [esp+34h] [ebp-18h] BYREF
  _DWORD v25[4]; // [esp+38h] [ebp-14h]

  if ( crypto_lock_rand )
  {
    CRYPTO_THREADID_current(&id);
    CRYPTO_lock(a1, a2, 5, 19, ".\\crypto\\rand\\md_rand.c", 218);
    v5 = CRYPTO_THREADID_cmp(&locking_threadid, &id) == 0;
    v18 = v5;
    CRYPTO_lock(a1, v5, 6, 19, ".\\crypto\\rand\\md_rand.c", 220);
    if ( v5 )
      goto LABEL_4;
  }
  else
  {
    v18 = 0;
    v5 = 0;
  }
  CRYPTO_lock(a1, v5, 9, 18, ".\\crypto\\rand\\md_rand.c", 225);
LABEL_4:
  v21 = md_count[0];
  v22 = md_count[1];
  data = *(_DWORD *)md;
  v6 = state_index;
  v7 = num + state_index;
  v8 = num + state_index < 1023;
  v25[0] = *(_DWORD *)&md[4];
  v25[1] = *(_DWORD *)&md[8];
  v25[2] = *(_DWORD *)&md[12];
  v25[3] = *(_DWORD *)&md[16];
  state_index += num;
  if ( v8 )
  {
    if ( state_num < 1023 && v7 > state_num )
      state_num = v7;
  }
  else
  {
    state_index = 1023
                * (((int)(((unsigned __int64)(2145384445LL * v7) >> 32) - v7) >> 9)
                 + ((unsigned int)(((unsigned __int64)(2145384445LL * v7) >> 32) - v7) >> 31))
                + v7;
    state_num = 1023;
  }
  md_count[1] += num / 20 + (num % 20 > 0);
  if ( !v5 )
    CRYPTO_lock(v6, 0, 10, 18, ".\\crypto\\rand\\md_rand.c", 257);
  EVP_MD_CTX_init(&ctx);
  if ( num > 0 )
  {
    v9 = num;
    id.ptr = (void *)((num - 1) / 0x14u + 1);
    do
    {
      v10 = v9;
      if ( v9 > 20 )
        v10 = 20;
      v11 = EVP_sha1();
      EVP_DigestInit_ex(&ctx, v11, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      if ( v10 + v6 - 1023 > 0 )
        EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      EVP_DigestFinal_ex(v6, &ctx, (unsigned __int8 *)&data, 0);
      ++v22;
      v12 = 0;
      buf += v10;
      if ( v10 > 0 )
      {
        do
        {
          state[v6++] ^= *((_BYTE *)&v25[-1] + v12);
          if ( v6 >= 1023 )
            v6 = 0;
          ++v12;
        }
        while ( v12 < v10 );
      }
      v9 -= 20;
      --id.ptr;
    }
    while ( id.ptr );
    v5 = v18;
  }
  EVP_MD_CTX_cleanup(v6, &ctx);
  v13 = a1;
  if ( !v5 )
    CRYPTO_lock(a1, 0, 9, 18, ".\\crypto\\rand\\md_rand.c", 308);
  for ( i = 0; i < 20; i += 5 )
  {
    md[i] ^= *((_BYTE *)&v25[-1] + i);
    v15 = *((_BYTE *)&data + i + 2);
    md[i + 1] ^= *((_BYTE *)&data + i + 1);
    md[i + 2] ^= v15;
    v16 = *((_BYTE *)v25 + i);
    md[i + 3] ^= *((_BYTE *)&data + i + 3);
    md[i + 4] ^= v16;
  }
  if ( entropy < 32.0 )
    entropy = entropy + add;
  if ( !v5 )
    CRYPTO_lock(v13, 0, 10, 18, ".\\crypto\\rand\\md_rand.c", 319);
}
