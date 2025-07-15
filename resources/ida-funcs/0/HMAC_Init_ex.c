BOOL __usercall HMAC_Init_ex@<eax>(
        int a1@<edi>,
        env_md_ctx_st *p_o_ctx@<ebx>,
        hmac_ctx_st *ctx,
        const __m128i *key,
        signed int len,
        const env_md_st *md,
        engine_st *impl)
{
  const env_md_st *v7; // ebp
  int v8; // eax
  int v9; // eax
  unsigned int *p_key_length; // edi
  unsigned int v11; // edi
  int i; // eax
  int j; // eax
  _BYTE v15[128]; // [esp+18h] [ebp-84h]

  v7 = md;
  v8 = 0;
  if ( md )
  {
    v8 = 1;
    ctx->md = md;
  }
  else
  {
    v7 = ctx->md;
  }
  if ( key )
  {
    v9 = EVP_MD_block_size(v7);
    if ( v9 > 128 )
      OpenSSLDie(a1, (int)ctx, v9, ".\\crypto\\hmac\\hmac.c", 82, "j <= (int)sizeof(ctx->key)");
    if ( v9 >= len )
    {
      if ( (unsigned int)len > 0x80 )
        OpenSSLDie(len, (int)ctx, v9, ".\\crypto\\hmac\\hmac.c", 95, "len>=0 && len<=(int)sizeof(ctx->key)");
      memcpy((int)ctx->key, key, len);
      p_key_length = &ctx->key_length;
      ctx->key_length = len;
    }
    else
    {
      if ( !EVP_DigestInit_ex((engine_st *)&ctx->md_ctx, &ctx->md_ctx, v7, impl) )
        return 0;
      if ( !EVP_DigestUpdate(&ctx->md_ctx) )
        return 0;
      p_key_length = &ctx->key_length;
      if ( !EVP_DigestFinal_ex((int)&ctx->key_length, (int)&ctx->md_ctx, &ctx->md_ctx, ctx->key, &ctx->key_length) )
        return 0;
    }
    v11 = *p_key_length;
    if ( v11 != 128 )
      memset((int)&ctx->key[v11], 0, 128 - v11);
  }
  else if ( !v8 )
  {
    return EVP_MD_CTX_copy_ex((int)p_o_ctx, &ctx->md_ctx, &ctx->i_ctx) != 0;
  }
  for ( i = 0; i < 128; ++i )
    v15[i] = ctx->key[i] ^ 0x36;
  if ( !EVP_DigestInit_ex((engine_st *)&ctx->i_ctx, &ctx->i_ctx, v7, impl) )
    return 0;
  EVP_MD_block_size(v7);
  if ( !EVP_DigestUpdate(&ctx->i_ctx) )
    return 0;
  for ( j = 0; j < 128; ++j )
    v15[j] = ctx->key[j] ^ 0x5C;
  p_o_ctx = &ctx->o_ctx;
  if ( !EVP_DigestInit_ex((engine_st *)&ctx->o_ctx, &ctx->o_ctx, v7, impl) )
    return 0;
  EVP_MD_block_size(v7);
  if ( !EVP_DigestUpdate(&ctx->o_ctx) )
    return 0;
  return EVP_MD_CTX_copy_ex((int)p_o_ctx, &ctx->md_ctx, &ctx->i_ctx) != 0;
}
