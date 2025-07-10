int __usercall ssl2_enc_init@<eax>(unsigned int a1@<edi>, const evp_cipher_st *s, int client)
{
  ssl_st *v3; // esi
  evp_cipher_ctx_st *v5; // eax
  evp_cipher_ctx_st *v6; // eax
  int key_len; // ebp
  int v8; // edi
  int v9; // ebx
  int v10; // edi
  const env_md_st *md; // [esp+4h] [ebp-Ch] BYREF
  evp_cipher_ctx_st *ctx; // [esp+8h] [ebp-8h]
  evp_cipher_ctx_st *enc_read_ctx; // [esp+Ch] [ebp-4h]

  v3 = (ssl_st *)s;
  if ( ssl_cipher_get_evp((const ssl_session_st *)s[3].set_asn1_parameters, &s, &md, 0, 0, 0) )
  {
    ssl_replace_hash(a1, &v3->read_hash, md);
    ssl_replace_hash(a1, &v3->write_hash, md);
    if ( (v3->enc_read_ctx
       || (v5 = (evp_cipher_ctx_st *)CRYPTO_malloc(140, ".\\ssl\\s2_enc.c", 82), (v3->enc_read_ctx = v5) != 0))
      && ((enc_read_ctx = v3->enc_read_ctx, EVP_CIPHER_CTX_init(enc_read_ctx), v3->enc_write_ctx)
       || (v6 = (evp_cipher_ctx_st *)CRYPTO_malloc(140, ".\\ssl\\s2_enc.c", 92), (v3->enc_write_ctx = v6) != 0)) )
    {
      ctx = v3->enc_write_ctx;
      EVP_CIPHER_CTX_init(ctx);
      key_len = s->key_len;
      v3->s2->key_material_length = 2 * key_len;
      if ( v3->s2->key_material_length > 0x30 )
        OpenSSLDie(
          a1,
          (unsigned int)v3,
          ".\\ssl\\s2_enc.c",
          100,
          "s->s2->key_material_length <= sizeof s->s2->key_material");
      if ( ssl2_generate_key_material(v3) > 0 )
      {
        if ( s->iv_len > 8 )
          OpenSSLDie(a1, (unsigned int)v3, ".\\ssl\\s2_enc.c", 105, "c->iv_len <= (int)sizeof(s->session->key_arg)");
        v8 = client;
        v9 = client != 0 ? key_len : 0;
        EVP_EncryptInit_ex(ctx, s, 0, &v3->s2->key_material[v9], v3->session->key_arg);
        v10 = v8 == 0 ? key_len : 0;
        EVP_DecryptInit_ex(enc_read_ctx, s, 0, &v3->s2->key_material[v10], v3->session->key_arg);
        v3->s2->read_key = &v3->s2->key_material[v10];
        v3->s2->write_key = &v3->s2->key_material[v9];
        return 1;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      ERR_put_error(0x14u, 124, 65, ".\\ssl\\s2_enc.c", 114);
      return 0;
    }
  }
  else
  {
    ssl2_return_error(v3, 1);
    ERR_put_error(0x14u, 124, 206, ".\\ssl\\s2_enc.c", 74);
    return 0;
  }
}
