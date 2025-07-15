int __cdecl ssl3_change_cipher_state(ssl_st *s, int which)
{
  ssl3_state_st *s3; // eax
  engine_st *new_hash; // ebx
  const ssl_comp_st *new_compression; // eax
  comp_method_st *method; // ebp
  evp_cipher_ctx_st *v6; // eax
  comp_ctx_st *v7; // eax
  unsigned __int8 *read_sequence; // eax
  unsigned __int8 *read_mac_secret; // eax
  evp_cipher_ctx_st *v10; // eax
  comp_ctx_st *v11; // eax
  unsigned __int8 *write_sequence; // eax
  unsigned __int8 *key_block; // ebp
  int v14; // ebx
  int v15; // edi
  const ssl_cipher_st *new_cipher; // edx
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  engine_st *v20; // ebx
  int v21; // ecx
  const __m128i *v22; // edx
  char *v23; // ecx
  ssl3_state_st *v24; // eax
  unsigned __int8 *server_random; // edx
  int v26; // ecx
  int v27; // ecx
  const __m128i *v28; // edx
  const env_md_st *v30; // eax
  const env_md_st *v31; // eax
  int v32; // [esp+10h] [ebp-70h]
  const __m128i *v33; // [esp+10h] [ebp-70h]
  engine_st *e; // [esp+14h] [ebp-6Ch]
  evp_cipher_ctx_st *enc_read_ctx; // [esp+18h] [ebp-68h]
  int v36; // [esp+1Ch] [ebp-64h]
  const __m128i *src; // [esp+20h] [ebp-60h]
  unsigned __int8 *dst; // [esp+24h] [ebp-5Ch]
  int v39; // [esp+28h] [ebp-58h]
  unsigned int count; // [esp+2Ch] [ebp-54h]
  int v41; // [esp+30h] [ebp-50h]
  env_md_ctx_st ctx; // [esp+34h] [ebp-4Ch] BYREF
  unsigned __int8 v43[16]; // [esp+4Ch] [ebp-34h] BYREF
  unsigned __int8 v44[32]; // [esp+5Ch] [ebp-24h] BYREF

  s3 = s->s3;
  new_hash = (engine_st *)s3->tmp.new_hash;
  v32 = 0;
  v36 = s3->tmp.new_cipher->algo_strength & 2;
  e = (engine_st *)s3->tmp.new_sym_enc;
  if ( !new_hash )
    OpenSSLDie(0, (int)s, 0, ".\\ssl\\s3_enc.c", 235, "m");
  new_compression = s->s3->tmp.new_compression;
  if ( new_compression )
    method = new_compression->method;
  else
    method = 0;
  if ( (which & 1) != 0 )
  {
    if ( s->enc_read_ctx )
    {
      v32 = 1;
    }
    else
    {
      v6 = (evp_cipher_ctx_st *)CRYPTO_malloc(140, ".\\ssl\\s3_enc.c", 247);
      s->enc_read_ctx = v6;
      if ( !v6 )
        goto err_245;
      EVP_CIPHER_CTX_init(v6);
    }
    enc_read_ctx = s->enc_read_ctx;
    ssl_replace_hash(0, new_hash, &s->read_hash, (const env_md_st *)new_hash);
    if ( s->expand )
    {
      COMP_CTX_free(s->expand);
      s->expand = 0;
    }
    if ( !method )
      goto LABEL_19;
    v7 = COMP_CTX_new(method);
    s->expand = v7;
    if ( !v7 )
    {
      ERR_put_error((int)new_hash, 0x14u, 129, 142, ".\\ssl\\s3_enc.c", 267);
      return 0;
    }
    if ( !s->s3->rrec.comp )
      s->s3->rrec.comp = (unsigned __int8 *)CRYPTO_malloc(0x4000, ".\\ssl\\s3_enc.c", 272);
    if ( s->s3->rrec.comp )
    {
LABEL_19:
      read_sequence = s->s3->read_sequence;
      *(_DWORD *)read_sequence = 0;
      *((_DWORD *)read_sequence + 1) = 0;
      read_mac_secret = s->s3->read_mac_secret;
      goto LABEL_31;
    }
err_245:
    ERR_put_error((int)new_hash, 0x14u, 129, 65, ".\\ssl\\s3_enc.c", 382);
    return 0;
  }
  if ( s->enc_write_ctx )
  {
    v32 = 1;
  }
  else
  {
    v10 = (evp_cipher_ctx_st *)CRYPTO_malloc(140, ".\\ssl\\s3_enc.c", 284);
    s->enc_write_ctx = v10;
    if ( !v10 )
      goto err_245;
    EVP_CIPHER_CTX_init(v10);
  }
  enc_read_ctx = s->enc_write_ctx;
  ssl_replace_hash(0, new_hash, &s->write_hash, (const env_md_st *)new_hash);
  if ( s->compress )
  {
    COMP_CTX_free(s->compress);
    s->compress = 0;
  }
  if ( method )
  {
    v11 = COMP_CTX_new(method);
    s->compress = v11;
    if ( !v11 )
    {
      ERR_put_error((int)new_hash, 0x14u, 129, 142, ".\\ssl\\s3_enc.c", 303);
      return 0;
    }
  }
  write_sequence = s->s3->write_sequence;
  *(_DWORD *)write_sequence = 0;
  *((_DWORD *)write_sequence + 1) = 0;
  read_mac_secret = s->s3->write_mac_secret;
LABEL_31:
  dst = read_mac_secret;
  if ( v32 )
    EVP_CIPHER_CTX_cleanup(0, (int)new_hash, enc_read_ctx);
  key_block = s->s3->tmp.key_block;
  v14 = EVP_MD_size((int)new_hash, (const env_md_st *)new_hash);
  count = v14;
  if ( v14 < 0 )
    return 0;
  v15 = (int)EC_KEY_get0_public_key(e);
  if ( v36 )
  {
    new_cipher = s->s3->tmp.new_cipher;
    v17 = (new_cipher->algo_strength & 8) != 0 ? 5 : 8 - (new_cipher->algorithm_enc != 1);
    if ( v15 >= v17 )
    {
      if ( (new_cipher->algo_strength & 8) != 0 )
        v15 = 5;
      else
        v15 = 8 - (new_cipher->algorithm_enc != 1);
    }
  }
  v18 = (int)EC_KEY_get0_private_key((const ssl_st *)e);
  v41 = v18;
  if ( which == 18 || which == 33 )
  {
    v26 = 2 * v14;
    v20 = (engine_st *)&key_block[2 * v14];
    v27 = v26 + 2 * v15;
    v28 = (const __m128i *)&key_block[v27];
    v23 = (char *)(v27 + 2 * v18);
    v24 = s->s3;
    src = (const __m128i *)key_block;
    v33 = v28;
    server_random = v24->server_random;
  }
  else
  {
    src = (const __m128i *)&key_block[v14];
    v19 = v15 + 2 * v14;
    v20 = (engine_st *)&key_block[v19];
    v21 = v18 + v15 + v19;
    v22 = (const __m128i *)&key_block[v21];
    v23 = (char *)(v18 + v21);
    v24 = s->s3;
    v33 = v22;
    server_random = v24->client_random;
  }
  v39 = (int)server_random;
  if ( (int)v23 > v24->tmp.key_block_length )
  {
    ERR_put_error((int)v20, 0x14u, 129, 68, ".\\ssl\\s3_enc.c", 345);
    return 0;
  }
  EVP_MD_CTX_init(&ctx);
  memcpy((int)dst, src, count);
  if ( v36 )
  {
    v30 = EVP_md5();
    EVP_DigestInit_ex(v20, &ctx, v30, 0);
    EVP_DigestUpdate(&ctx);
    EVP_DigestUpdate(&ctx);
    v15 = v39;
    EVP_DigestUpdate(&ctx);
    EVP_DigestFinal_ex(v39, (int)v20, &ctx, v44, 0);
    v20 = (engine_st *)v44;
    if ( v41 > 0 )
    {
      v31 = EVP_md5();
      EVP_DigestInit_ex((engine_st *)v44, &ctx, v31, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      EVP_DigestFinal_ex(v39, (int)v44, &ctx, v43, 0);
      v33 = (const __m128i *)v43;
    }
  }
  s->session->key_arg_length = 0;
  EVP_CipherInit_ex(enc_read_ctx, (const evp_cipher_st *)e, 0, (const unsigned __int8 *)v20, v33, which & 2);
  OPENSSL_cleanse(v44, 32);
  OPENSSL_cleanse(v43, 16);
  EVP_MD_CTX_cleanup(v15, (int)v20, &ctx);
  return 1;
}
