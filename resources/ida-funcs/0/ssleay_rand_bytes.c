int __cdecl ssleay_rand_bytes(unsigned __int8 *buf, int num)
{
  unsigned __int8 *v2; // ebx
  int v4; // edi
  long double v5; // st7
  int v6; // esi
  void *v7; // esp
  int v8; // esi
  int v9; // eax
  bool v10; // cc
  int v11; // ebp
  int v12; // edi
  const env_md_st *v13; // eax
  int v14; // edi
  int v15; // ecx
  int i; // eax
  int v17; // esi
  int v18; // esi
  int v19; // esi
  int v20; // esi
  const env_md_st *v21; // eax
  int v22; // [esp+18h] [ebp-40h]
  int v23; // [esp+1Ch] [ebp-3Ch]
  env_md_ctx_st ctx; // [esp+20h] [ebp-38h] BYREF
  int v25; // [esp+38h] [ebp-20h]
  int v26; // [esp+3Ch] [ebp-1Ch]
  int data; // [esp+40h] [ebp-18h] BYREF
  int v28; // [esp+44h] [ebp-14h]
  int v29; // [esp+48h] [ebp-10h]
  _DWORD v30[2]; // [esp+4Ch] [ebp-Ch]

  v2 = buf;
  if ( num <= 0 )
    return 1;
  EVP_MD_CTX_init(&ctx);
  v4 = 10 * ((num - 1) / 10 + 1);
  CRYPTO_lock(v4, (int)buf, 9, 18, ".\\crypto\\rand\\md_rand.c", 381);
  CRYPTO_lock(v4, (int)buf, 9, 19, ".\\crypto\\rand\\md_rand.c", 384);
  CRYPTO_THREADID_current(&locking_threadid);
  CRYPTO_lock(v4, (int)buf, 10, 19, ".\\crypto\\rand\\md_rand.c", 386);
  crypto_lock_rand = 1;
  if ( !initialized )
  {
    RAND_poll((unsigned int)buf, v4, num);
    initialized = 1;
  }
  if ( entropy < 32.0 )
  {
    v22 = 0;
    v5 = 0.0;
    entropy = entropy - (double)num;
    if ( entropy < 0.0 )
      entropy = 0.0;
  }
  else
  {
    v5 = 0.0;
    v22 = 1;
  }
  if ( !stirred_pool )
  {
    v6 = 52;
    while ( 1 )
    {
      v7 = alloca(8);
      ssleay_rand_add(v4, (int)buf, "....................", 20, v5);
      if ( !--v6 )
        break;
      v5 = 0.0;
    }
    if ( v22 )
      stirred_pool = 1;
  }
  v25 = md_count[0];
  v26 = md_count[1];
  data = *(_DWORD *)md;
  v28 = *(_DWORD *)&md[4];
  v29 = *(_DWORD *)&md[8];
  v8 = state_index;
  v9 = v4 + state_index;
  v10 = v4 + state_index <= state_num;
  v30[0] = *(_DWORD *)&md[12];
  v11 = state_num;
  v30[1] = *(_DWORD *)&md[16];
  state_index += v4;
  if ( !v10 )
    state_index = v9 % state_num;
  ++md_count[0];
  crypto_lock_rand = 0;
  CRYPTO_lock(v4, (int)buf, 10, 18, ".\\crypto\\rand\\md_rand.c", 460);
  do
  {
    if ( num < 10 )
    {
      v23 = num;
      v12 = num;
    }
    else
    {
      v12 = 10;
      v23 = 10;
    }
    num -= v12;
    v13 = EVP_sha1();
    EVP_DigestInit_ex(&ctx, v13, 0);
    EVP_DigestUpdate(&ctx);
    EVP_DigestUpdate(&ctx);
    EVP_DigestUpdate(&ctx);
    v14 = v8 - v11 + 10;
    EVP_DigestUpdate(&ctx);
    if ( v14 > 0 )
      EVP_DigestUpdate(&ctx);
    EVP_DigestFinal_ex(v14, &ctx, (unsigned __int8 *)&data, 0);
    v15 = 0;
    for ( i = 2; i < 12; i += 5 )
    {
      state[v8] ^= *((_BYTE *)&data + v15);
      v17 = v8 + 1;
      if ( v17 >= v11 )
        v17 = 0;
      if ( v15 < v23 )
        *v2++ = *((_BYTE *)&v29 + v15 + 2);
      state[v17] ^= *((_BYTE *)&data + v15 + 1);
      v18 = v17 + 1;
      if ( v18 >= v11 )
        v18 = 0;
      if ( i - 1 < v23 )
        *v2++ = *((_BYTE *)&v29 + v15 + 3);
      state[v18] ^= *((_BYTE *)&data + v15 + 2);
      v19 = v18 + 1;
      if ( v19 >= v11 )
        v19 = 0;
      if ( i < v23 )
        *v2++ = *((_BYTE *)v30 + v15);
      state[v19] ^= *((_BYTE *)&data + v15 + 3);
      v20 = v19 + 1;
      if ( v20 >= v11 )
        v20 = 0;
      if ( i + 1 < v23 )
        *v2++ = *((_BYTE *)v30 + v15 + 1);
      state[v20] ^= *((_BYTE *)&v28 + v15);
      v8 = v20 + 1;
      if ( v8 >= v11 )
        v8 = 0;
      if ( i + 2 < v23 )
        *v2++ = *((_BYTE *)v30 + v15 + 2);
      v15 += 5;
    }
  }
  while ( num > 0 );
  v21 = EVP_sha1();
  EVP_DigestInit_ex(&ctx, v21, 0);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  CRYPTO_lock(v23, (int)v2, 9, 18, ".\\crypto\\rand\\md_rand.c", 512);
  EVP_DigestUpdate(&ctx);
  EVP_DigestFinal_ex(v23, &ctx, md, 0);
  CRYPTO_lock(v23, (int)v2, 10, 18, ".\\crypto\\rand\\md_rand.c", 515);
  EVP_MD_CTX_cleanup(v23, &ctx);
  if ( v22 )
    return 1;
  ERR_put_error((int)v2, 0x24u, 100, 100, ".\\crypto\\rand\\md_rand.c", 522);
  ERR_add_error_data(1, "You need to read the OpenSSL FAQ, http://www.openssl.org/support/faq.html");
  return 0;
}
