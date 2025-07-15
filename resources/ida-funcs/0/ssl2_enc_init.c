int __usercall ssl2_enc_init@<eax>(int a1@<edi>, engine_st *a2@<ebx>, ssl_st *s, int client)
{
  ssl_st *v4; // esi
  evp_cipher_ctx_st *v6; // eax
  evp_cipher_ctx_st *v7; // eax
  const ssl_method_st *method; // ebp
  int v9; // edi
  const ssl_method_st *v10; // ebx
  const ssl_method_st *v11; // edi
  const env_md_st *v12; // [esp+4h] [ebp-Ch] BYREF
  evp_cipher_ctx_st *enc_write_ctx; // [esp+8h] [ebp-8h]
  evp_cipher_ctx_st *enc_read_ctx; // [esp+Ch] [ebp-4h]

  v4 = s;
  if ( ssl_cipher_get_evp(s->session, (const evp_cipher_st **)&s, &v12, 0, 0, 0) )
  {
    ssl_replace_hash(a1, a2, &v4->read_hash, v12);
    ssl_replace_hash(a1, a2, &v4->write_hash, v12);
    if ( (v4->enc_read_ctx
       || (v6 = (evp_cipher_ctx_st *)CRYPTO_malloc(140, ".\\ssl\\s2_enc.c", 82), (v4->enc_read_ctx = v6) != 0))
      && ((enc_read_ctx = v4->enc_read_ctx, EVP_CIPHER_CTX_init(enc_read_ctx), v4->enc_write_ctx)
       || (v7 = (evp_cipher_ctx_st *)CRYPTO_malloc(140, ".\\ssl\\s2_enc.c", 92), (v4->enc_write_ctx = v7) != 0)) )
    {
      enc_write_ctx = v4->enc_write_ctx;
      EVP_CIPHER_CTX_init(enc_write_ctx);
      method = s->method;
      v4->s2->key_material_length = 2 * (_DWORD)method;
      if ( v4->s2->key_material_length > 0x30 )
        OpenSSLDie(
          a1,
          (int)v4,
          (int)a2,
          ".\\ssl\\s2_enc.c",
          100,
          "s->s2->key_material_length <= sizeof s->s2->key_material");
      if ( ssl2_generate_key_material(v4) > 0 )
      {
        if ( (int)s->rbio > 8 )
          OpenSSLDie(a1, (int)v4, (int)a2, ".\\ssl\\s2_enc.c", 105, "c->iv_len <= (int)sizeof(s->session->key_arg)");
        v9 = client;
        v10 = client != 0 ? method : 0;
        EVP_EncryptInit_ex(
          enc_write_ctx,
          (const evp_cipher_st *)s,
          0,
          &v4->s2->key_material[(unsigned int)v10],
          (const __m128i *)v4->session->key_arg);
        v11 = v9 == 0 ? method : 0;
        EVP_DecryptInit_ex(
          enc_read_ctx,
          (const evp_cipher_st *)s,
          0,
          &v4->s2->key_material[(unsigned int)v11],
          (const __m128i *)v4->session->key_arg);
        v4->s2->read_key = (unsigned __int8 *)&v11[1].ssl_renegotiate_check + (unsigned int)v4->s2;
        v4->s2->write_key = (unsigned __int8 *)&v10[1].ssl_renegotiate_check + (unsigned int)v4->s2;
        return 1;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      ERR_put_error((int)a2, 0x14u, 124, 65, ".\\ssl\\s2_enc.c", 114);
      return 0;
    }
  }
  else
  {
    ssl2_return_error((int)a2, v4, 1);
    ERR_put_error((int)a2, 0x14u, 124, 206, ".\\ssl\\s2_enc.c", 74);
    return 0;
  }
}
