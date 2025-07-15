BOOL __usercall HMAC_Init_ex@<eax>(
        unsigned int a1@<edi>,
        hmac_ctx_st *ctx,
        unsigned __int8 *key,
        unsigned int len,
        const env_md_st *md,
        engine_st *impl)
{
  const env_md_st *v6; // ebp
  int v7; // eax
  int v8; // eax
  unsigned int *p_key_length; // edi
  unsigned int v10; // edi
  int i; // eax
  int j; // eax
  _BYTE v14[128]; // [esp+18h] [ebp-84h]

  v6 = md;
  v7 = 0;
  if ( md )
  {
    v7 = 1;
    ctx->md = md;
  }
  else
  {
    v6 = ctx->md;
  }
  if ( key )
  {
    v8 = EVP_MD_block_size(v6);
    if ( v8 > 128 )
      OpenSSLDie(a1, (unsigned int)ctx, ".\\crypto\\hmac\\hmac.c", 82, "j <= (int)sizeof(ctx->key)");
    if ( v8 >= (int)len )
    {
      if ( len > 0x80 )
        OpenSSLDie(len, (unsigned int)ctx, ".\\crypto\\hmac\\hmac.c", 95, "len>=0 && len<=(int)sizeof(ctx->key)");
      memcpy(ctx->key, key, len);
      p_key_length = &ctx->key_length;
      ctx->key_length = len;
    }
    else
    {
      if ( !EVP_DigestInit_ex(&ctx->md_ctx, v6, impl) )
        return 0;
      if ( !EVP_DigestUpdate(&ctx->md_ctx) )
        return 0;
      p_key_length = &ctx->key_length;
      if ( !EVP_DigestFinal_ex((unsigned int)&ctx->key_length, &ctx->md_ctx, ctx->key, &ctx->key_length) )
        return 0;
    }
    v10 = *p_key_length;
    if ( v10 != 128 )
      memset((int)&ctx->key[v10], 0, 128 - v10);
  }
  else if ( !v7 )
  {
    return EVP_MD_CTX_copy_ex(&ctx->md_ctx, &ctx->i_ctx) != 0;
  }
  for ( i = 0; i < 128; ++i )
    v14[i] = ctx->key[i] ^ 0x36;
  if ( !EVP_DigestInit_ex(&ctx->i_ctx, v6, impl) )
    return 0;
  EVP_MD_block_size(v6);
  if ( !EVP_DigestUpdate(&ctx->i_ctx) )
    return 0;
  for ( j = 0; j < 128; ++j )
    v14[j] = ctx->key[j] ^ 0x5C;
  if ( !EVP_DigestInit_ex(&ctx->o_ctx, v6, impl) )
    return 0;
  EVP_MD_block_size(v6);
  if ( !EVP_DigestUpdate(&ctx->o_ctx) )
    return 0;
  return EVP_MD_CTX_copy_ex(&ctx->md_ctx, &ctx->i_ctx) != 0;
}
