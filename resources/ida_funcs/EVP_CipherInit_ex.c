int __cdecl EVP_CipherInit_ex(
        evp_cipher_ctx_st *ctx,
        const evp_cipher_st *cipher,
        engine_st *impl,
        const unsigned __int8 *key,
        unsigned __int8 *iv,
        int enc)
{
  int v6; // ebx
  evp_cipher_ctx_st *v7; // esi
  const evp_cipher_st *v8; // edi
  engine_st *cipher_engine; // ebx
  const evp_cipher_st *v11; // eax
  int ctx_size; // eax
  void *v13; // eax
  const evp_cipher_st *v14; // edx
  int block_size; // eax
  X509_name_st *issuer_name; // eax
  X509_name_st *v17; // eax
  const evp_cipher_st *v18; // ecx

  v6 = enc;
  if ( enc == -1 )
  {
    v7 = ctx;
    enc = ctx->encrypt;
    v6 = enc;
  }
  else
  {
    if ( enc )
    {
      enc = 1;
      v6 = 1;
    }
    v7 = ctx;
    ctx->encrypt = v6;
  }
  v8 = cipher;
  if ( !v7->engine || !v7->cipher || cipher && cipher->nid != v7->cipher->nid )
  {
    if ( cipher )
    {
      EVP_CIPHER_CTX_cleanup((unsigned int)cipher, v7);
      v7->encrypt = v6;
      cipher_engine = impl;
      if ( impl )
      {
        if ( !ENGINE_init((unsigned int)cipher, impl) )
        {
          ERR_put_error(6u, 123, 134, ".\\crypto\\evp\\evp_enc.c", 127);
          return 0;
        }
      }
      else
      {
        cipher_engine = ENGINE_get_cipher_engine(cipher->nid);
      }
      if ( cipher_engine )
      {
        v11 = ENGINE_get_cipher(cipher_engine, cipher->nid);
        if ( !v11 )
        {
          ERR_put_error(6u, 123, 134, ".\\crypto\\evp\\evp_enc.c", 144);
          return 0;
        }
        v8 = v11;
        v7->engine = cipher_engine;
      }
      else
      {
        v7->engine = 0;
      }
      v7->cipher = v8;
      ctx_size = v8->ctx_size;
      if ( ctx_size )
      {
        v13 = CRYPTO_malloc(ctx_size, ".\\crypto\\evp\\evp_enc.c", 161);
        v7->cipher_data = v13;
        if ( !v13 )
        {
          ERR_put_error(6u, 123, 65, ".\\crypto\\evp\\evp_enc.c", 164);
          return 0;
        }
      }
      else
      {
        v7->cipher_data = 0;
      }
      v14 = v7->cipher;
      v7->key_len = v8->key_len;
      v7->flags = 0;
      if ( (v14->flags & 0x40) != 0 && !EVP_CIPHER_CTX_ctrl(v7, 0, 0, 0) )
      {
        ERR_put_error(6u, 123, 134, ".\\crypto\\evp\\evp_enc.c", 178);
        return 0;
      }
      v6 = enc;
    }
    else if ( !v7->cipher )
    {
      ERR_put_error(6u, 123, 131, ".\\crypto\\evp\\evp_enc.c", 185);
      return 0;
    }
  }
  block_size = v7->cipher->block_size;
  if ( block_size != 1 && block_size != 8 && block_size != 16 )
    OpenSSLDie(
      (unsigned int)v8,
      (unsigned int)v7,
      ".\\crypto\\evp\\evp_enc.c",
      194,
      "ctx->cipher->block_size == 1 || ctx->cipher->block_size == 8 || ctx->cipher->block_size == 16");
  if ( (EVP_CIPHER_CTX_flags(v7) & 0x10) == 0 )
  {
    switch ( (unsigned int)&loc_F0007 & EVP_CIPHER_CTX_flags(v7) )
    {
      case 0u:
      case 1u:
        goto $LN9_34;
      case 2u:
        break;
      case 3u:
      case 4u:
        v7->num = 0;
        break;
      default:
        return 0;
    }
    if ( (int)X509_get_issuer_name((x509_st *)v7) > 16 )
      OpenSSLDie(
        (unsigned int)iv,
        (unsigned int)v7,
        ".\\crypto\\evp\\evp_enc.c",
        212,
        "EVP_CIPHER_CTX_iv_length(ctx) <= (int)sizeof(ctx->iv)");
    if ( iv )
    {
      issuer_name = X509_get_issuer_name((x509_st *)v7);
      memcpy(v7->oiv, iv, (unsigned int)issuer_name);
    }
    v17 = X509_get_issuer_name((x509_st *)v7);
    memcpy(v7->iv, v7->oiv, (unsigned int)v17);
  }
$LN9_34:
  if ( (key || (v7->cipher->flags & 0x20) != 0) && !v7->cipher->init(v7, key, iv, v6) )
    return 0;
  v18 = v7->cipher;
  v7->buf_len = 0;
  v7->final_used = 0;
  v7->block_mask = v18->block_size - 1;
  return 1;
}
