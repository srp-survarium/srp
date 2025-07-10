int __cdecl ssleay_rand_bytes(unsigned __int8 *buf, int num)
{
  unsigned int v4; // edi
  long double add; // st7
  int v6; // esi
  void *v7; // esp
  int v8; // esi
  signed int v9; // eax
  bool v10; // cc
  int v11; // ebp
  unsigned int v12; // edi
  const env_md_st *v13; // eax
  signed int v14; // ecx
  int i; // eax
  int v16; // esi
  int v17; // esi
  int v18; // esi
  int v19; // esi
  const env_md_st *v20; // eax
  int v21; // [esp+18h] [ebp-40h]
  signed int v22; // [esp+1Ch] [ebp-3Ch]
  env_md_ctx_st ctx; // [esp+20h] [ebp-38h] BYREF
  _DWORD v24[2]; // [esp+38h] [ebp-20h] BYREF
  int data; // [esp+40h] [ebp-18h] BYREF
  int v26; // [esp+44h] [ebp-14h]
  int v27; // [esp+48h] [ebp-10h]
  _DWORD v28[2]; // [esp+4Ch] [ebp-Ch]

  if ( num <= 0 )
    return 1;
  EVP_MD_CTX_init(&ctx);
  v4 = 10 * ((num - 1) / 10 + 1);
  CRYPTO_lock(v4, 9, 18, ".\\crypto\\rand\\md_rand.c", 381);
  CRYPTO_lock(v4, 9, 19, ".\\crypto\\rand\\md_rand.c", 384);
  CRYPTO_THREADID_current(&locking_threadid);
  CRYPTO_lock(v4, 10, 19, ".\\crypto\\rand\\md_rand.c", 386);
  crypto_lock_rand = 1;
  if ( !initialized )
  {
    RAND_poll();
    initialized = 1;
  }
  if ( entropy < 32.0 )
  {
    v21 = 0;
    add = 0.0;
    entropy = entropy - (double)num;
    if ( entropy < 0.0 )
      entropy = 0.0;
  }
  else
  {
    add = 0.0;
    v21 = 1;
  }
  if ( !stirred_pool )
  {
    v6 = 52;
    while ( 1 )
    {
      v7 = alloca(8);
      ssleay_rand_add(v4, "....................", 20, add);
      if ( !--v6 )
        break;
      add = 0.0;
    }
    if ( v21 )
      stirred_pool = 1;
  }
  v24[0] = md_count[0];
  v24[1] = md_count[1];
  data = *(_DWORD *)md;
  v26 = *(_DWORD *)&md[4];
  v27 = *(_DWORD *)&md[8];
  v8 = state_index;
  v9 = v4 + state_index;
  v10 = (int)(v4 + state_index) <= state_num;
  v28[0] = *(_DWORD *)&md[12];
  v11 = state_num;
  v28[1] = *(_DWORD *)&md[16];
  state_index += v4;
  if ( !v10 )
    state_index = v9 % state_num;
  ++md_count[0];
  crypto_lock_rand = 0;
  CRYPTO_lock(v4, 10, 18, ".\\crypto\\rand\\md_rand.c", 460);
  do
  {
    if ( num < 10 )
    {
      v22 = num;
      v12 = num;
    }
    else
    {
      v12 = 10;
      v22 = 10;
    }
    num -= v12;
    v13 = EVP_sha1();
    EVP_DigestInit_ex(&ctx, v13, 0);
    EVP_DigestUpdate(&ctx, &data, 0x14u);
    EVP_DigestUpdate(&ctx, v24, 8u);
    EVP_DigestUpdate(&ctx, buf, v12);
    if ( v8 - v11 + 10 <= 0 )
    {
      EVP_DigestUpdate(&ctx, &state[v8], 0xAu);
    }
    else
    {
      EVP_DigestUpdate(&ctx, &state[v8], v11 - v8);
      EVP_DigestUpdate(&ctx, state, v8 - v11 + 10);
    }
    EVP_DigestFinal_ex(&ctx, (unsigned __int8 *)&data, 0);
    v14 = 0;
    for ( i = 2; i < 12; i += 5 )
    {
      state[v8] ^= *((_BYTE *)&data + v14);
      v16 = v8 + 1;
      if ( v16 >= v11 )
        v16 = 0;
      if ( v14 < v22 )
        *buf++ = *((_BYTE *)&v27 + v14 + 2);
      state[v16] ^= *((_BYTE *)&data + v14 + 1);
      v17 = v16 + 1;
      if ( v17 >= v11 )
        v17 = 0;
      if ( i - 1 < v22 )
        *buf++ = *((_BYTE *)&v27 + v14 + 3);
      state[v17] ^= *((_BYTE *)&data + v14 + 2);
      v18 = v17 + 1;
      if ( v18 >= v11 )
        v18 = 0;
      if ( i < v22 )
        *buf++ = *((_BYTE *)v28 + v14);
      state[v18] ^= *((_BYTE *)&data + v14 + 3);
      v19 = v18 + 1;
      if ( v19 >= v11 )
        v19 = 0;
      if ( i + 1 < v22 )
        *buf++ = *((_BYTE *)v28 + v14 + 1);
      state[v19] ^= *((_BYTE *)&v26 + v14);
      v8 = v19 + 1;
      if ( v8 >= v11 )
        v8 = 0;
      if ( i + 2 < v22 )
        *buf++ = *((_BYTE *)v28 + v14 + 2);
      v14 += 5;
    }
  }
  while ( num > 0 );
  v20 = EVP_sha1();
  EVP_DigestInit_ex(&ctx, v20, 0);
  EVP_DigestUpdate(&ctx, v24, 8u);
  EVP_DigestUpdate(&ctx, &data, 0x14u);
  CRYPTO_lock(v22, 9, 18, ".\\crypto\\rand\\md_rand.c", 512);
  EVP_DigestUpdate(&ctx, md, 0x14u);
  EVP_DigestFinal_ex(&ctx, md, 0);
  CRYPTO_lock(v22, 10, 18, ".\\crypto\\rand\\md_rand.c", 515);
  EVP_MD_CTX_cleanup(&ctx);
  if ( v21 )
    return 1;
  ERR_put_error(0x24u, 100, 100, ".\\crypto\\rand\\md_rand.c", 522);
  ERR_add_error_data(1, "You need to read the OpenSSL FAQ, http://www.openssl.org/support/faq.html");
  return 0;
}
