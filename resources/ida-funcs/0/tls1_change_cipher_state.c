int __cdecl tls1_change_cipher_state(ssl_st *s, int which)
{
  ssl3_state_st *s3; // eax
  const ssl_cipher_st *new_cipher; // ecx
  int new_compression; // ebx
  int v5; // edi
  evp_cipher_ctx_st *v6; // eax
  comp_ctx_st *v7; // eax
  unsigned __int8 *read_sequence; // eax
  ssl3_state_st *v10; // eax
  int *p_read_mac_secret_size; // eax
  evp_cipher_ctx_st *v12; // eax
  comp_ctx_st *v13; // eax
  unsigned __int8 *write_sequence; // eax
  ssl3_state_st *v15; // eax
  ssl3_state_st *v16; // eax
  unsigned int new_mac_secret_size; // ebx
  const __m128i *key_block; // ebp
  const rsa_meth_st *v19; // eax
  const ssl_cipher_st *v20; // edx
  int v21; // ecx
  int v22; // edi
  int v23; // ecx
  unsigned int v24; // eax
  char *v25; // eax
  const __m128i *v26; // edx
  int v27; // eax
  const char *v28; // ebp
  int v29; // eax
  evp_pkey_st *v30; // ebx
  ssl3_state_st *v31; // ebx
  const rsa_meth_st *v32; // eax
  const unsigned __int8 *v33; // ebx
  int v34; // [esp-4h] [ebp-CCh]
  int v35; // [esp+10h] [ebp-B8h]
  const __m128i *v36; // [esp+10h] [ebp-B8h]
  engine_st *e; // [esp+14h] [ebp-B4h]
  int *v38; // [esp+18h] [ebp-B0h]
  const __m128i *v39; // [esp+1Ch] [ebp-ACh]
  evp_cipher_ctx_st *enc_read_ctx; // [esp+20h] [ebp-A8h]
  int v41; // [esp+24h] [ebp-A4h]
  env_md_ctx_st *v42; // [esp+28h] [ebp-A0h]
  unsigned __int8 *dst; // [esp+2Ch] [ebp-9Ch]
  const __m128i *src; // [esp+30h] [ebp-98h]
  int v45; // [esp+34h] [ebp-94h]
  int type; // [esp+38h] [ebp-90h]
  engine_st *new_hash; // [esp+3Ch] [ebp-8Ch]
  int v48; // [esp+40h] [ebp-88h]
  unsigned __int8 v49[32]; // [esp+44h] [ebp-84h] BYREF
  unsigned __int8 v50[32]; // [esp+64h] [ebp-64h] BYREF
  unsigned __int8 v51[32]; // [esp+84h] [ebp-44h] BYREF
  unsigned __int8 v52[32]; // [esp+A4h] [ebp-24h] BYREF

  s3 = s->s3;
  new_cipher = s3->tmp.new_cipher;
  new_compression = (int)s3->tmp.new_compression;
  e = (engine_st *)s3->tmp.new_sym_enc;
  v5 = new_cipher->algo_strength & 2;
  new_hash = (engine_st *)s3->tmp.new_hash;
  v35 = 0;
  v45 = v5;
  type = s3->tmp.new_mac_pkey_type;
  if ( (which & 1) != 0 )
  {
    if ( (new_cipher->algorithm2 & 4) != 0 )
      s->mac_flags |= 1u;
    else
      s->mac_flags &= ~1u;
    if ( s->enc_read_ctx )
    {
      v35 = 1;
    }
    else
    {
      v6 = (evp_cipher_ctx_st *)CRYPTO_malloc(140, ".\\ssl\\t1_enc.c", 366);
      s->enc_read_ctx = v6;
      if ( !v6 )
        goto err_250;
      EVP_CIPHER_CTX_init(v6);
    }
    enc_read_ctx = s->enc_read_ctx;
    v42 = ssl_replace_hash(v5, (engine_st *)new_compression, &s->read_hash, 0);
    if ( s->expand )
    {
      COMP_CTX_free(s->expand);
      s->expand = 0;
    }
    if ( !new_compression )
      goto LABEL_19;
    v7 = COMP_CTX_new(*(comp_method_st **)(new_compression + 8));
    s->expand = v7;
    if ( !v7 )
    {
      v34 = 384;
LABEL_14:
      ERR_put_error(new_compression, 0x14u, 209, 142, ".\\ssl\\t1_enc.c", v34);
      return 0;
    }
    if ( !s->s3->rrec.comp )
      s->s3->rrec.comp = (unsigned __int8 *)CRYPTO_malloc(17728, ".\\ssl\\t1_enc.c", 389);
    if ( s->s3->rrec.comp )
    {
LABEL_19:
      if ( s->version != 65279 )
      {
        read_sequence = s->s3->read_sequence;
        *(_DWORD *)read_sequence = 0;
        *((_DWORD *)read_sequence + 1) = 0;
      }
      v10 = s->s3;
      dst = v10->read_mac_secret;
      p_read_mac_secret_size = &v10->read_mac_secret_size;
      goto LABEL_38;
    }
err_250:
    ERR_put_error(new_compression, 0x14u, 209, 65, ".\\ssl\\t1_enc.c", 542);
    return 0;
  }
  if ( (new_cipher->algorithm2 & 4) != 0 )
    s->mac_flags |= 2u;
  else
    s->mac_flags &= ~2u;
  if ( s->enc_write_ctx )
  {
    v35 = 1;
  }
  else
  {
    v12 = (evp_cipher_ctx_st *)CRYPTO_malloc(140, ".\\ssl\\t1_enc.c", 408);
    s->enc_write_ctx = v12;
    if ( !v12 )
      goto err_250;
    EVP_CIPHER_CTX_init(v12);
  }
  enc_read_ctx = s->enc_write_ctx;
  v42 = ssl_replace_hash(v5, (engine_st *)new_compression, &s->write_hash, 0);
  if ( s->compress )
  {
    COMP_CTX_free(s->compress);
    s->compress = 0;
  }
  if ( new_compression )
  {
    v13 = COMP_CTX_new(*(comp_method_st **)(new_compression + 8));
    s->compress = v13;
    if ( !v13 )
    {
      v34 = 426;
      goto LABEL_14;
    }
  }
  if ( s->version != 65279 )
  {
    write_sequence = s->s3->write_sequence;
    *(_DWORD *)write_sequence = 0;
    *((_DWORD *)write_sequence + 1) = 0;
  }
  v15 = s->s3;
  dst = v15->write_mac_secret;
  p_read_mac_secret_size = &v15->write_mac_secret_size;
LABEL_38:
  v38 = p_read_mac_secret_size;
  if ( v35 )
    EVP_CIPHER_CTX_cleanup(v5, new_compression, enc_read_ctx);
  v16 = s->s3;
  new_mac_secret_size = v16->tmp.new_mac_secret_size;
  key_block = (const __m128i *)v16->tmp.key_block;
  *v38 = new_mac_secret_size;
  v19 = EC_KEY_get0_public_key(e);
  if ( v5
    && ((v20 = s->s3->tmp.new_cipher, (v20->algo_strength & 8) == 0) ? (v21 = 8 - (v20->algorithm_enc != 1)) : (v21 = 5),
        (int)v19 >= v21) )
  {
    if ( (v20->algo_strength & 8) != 0 )
      v22 = 5;
    else
      v22 = 8 - (v20->algorithm_enc != 1);
  }
  else
  {
    v22 = (int)v19;
  }
  v23 = (int)EC_KEY_get0_private_key((const ssl_st *)e);
  v48 = v23;
  if ( which == 18 || which == 33 )
  {
    v29 = 2 * new_mac_secret_size + 2 * v22;
    v39 = (const __m128i *)((char *)key_block + 2 * new_mac_secret_size);
    v26 = (const __m128i *)((char *)key_block + v29);
    src = key_block;
    v27 = v29 + 2 * v23;
    v28 = "client write key";
    v41 = 1;
  }
  else
  {
    src = (const __m128i *)((char *)key_block + new_mac_secret_size);
    v24 = v22 + 2 * new_mac_secret_size;
    v39 = (const __m128i *)((char *)key_block + v24);
    v25 = (char *)(v23 + v22 + v24);
    v26 = (const __m128i *)((char *)key_block + (_DWORD)v25);
    v27 = (int)&v25[v23];
    v28 = "server write key";
    v41 = 0;
  }
  v36 = v26;
  if ( v27 > s->s3->tmp.key_block_length )
  {
    ERR_put_error(new_mac_secret_size, 0x14u, 209, 68, ".\\ssl\\t1_enc.c", 472);
    return 0;
  }
  memcpy((int)dst, src, new_mac_secret_size);
  v30 = EVP_PKEY_new_mac_key((int)dst, v22, type, 0, dst, *v38);
  EVP_DigestSignInit(v42, 0, new_hash, 0, v30);
  EVP_PKEY_free(v22, v30);
  if ( v45 )
  {
    v31 = s->s3;
    v32 = EC_KEY_get0_public_key(e);
    if ( !tls1_PRF(
            v31->tmp.new_cipher->algorithm2,
            v28,
            16,
            v31->client_random,
            32,
            v31->server_random,
            32,
            0,
            0,
            0,
            0,
            v39,
            v22,
            v50,
            v51,
            (int)v32) )
      return 0;
    v33 = v50;
    if ( v48 > 0 )
    {
      if ( !tls1_PRF(
              s->s3->tmp.new_cipher->algorithm2,
              "IV block",
              8,
              s->s3->client_random,
              32,
              s->s3->server_random,
              32,
              0,
              0,
              0,
              0,
              (const __m128i *)empty,
              0,
              v49,
              v52,
              2 * v48) )
        return 0;
      if ( v41 )
        v36 = (const __m128i *)v49;
      else
        v36 = (const __m128i *)&v49[v48];
    }
  }
  else
  {
    v33 = (const unsigned __int8 *)v39;
  }
  s->session->key_arg_length = 0;
  EVP_CipherInit_ex(enc_read_ctx, (const evp_cipher_st *)e, 0, v33, v36, which & 2);
  OPENSSL_cleanse(v50, 32);
  OPENSSL_cleanse(v51, 32);
  OPENSSL_cleanse(v49, 32);
  OPENSSL_cleanse(v52, 32);
  return 1;
}
