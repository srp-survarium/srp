const char *__usercall ssl3_handshake_mac@<eax>(
        ssl_st *s@<edx>,
        int md_nid@<ecx>,
        engine_st *sender@<ebx>,
        int len,
        unsigned __int8 *p)
{
  unsigned int v7; // eax
  ui_string_st **v8; // ecx
  ui_string_st *object; // eax
  bool v10; // zf
  const env_md_ctx_st *v11; // edi
  ui_string_st *v13; // eax
  int v14; // ecx
  int v15; // edi
  ui_string_st *v16; // eax
  unsigned int v17; // [esp+Ch] [ebp-64h] BYREF
  ui_string_st ctx[2]; // [esp+10h] [ebp-60h] BYREF

  if ( s->s3->handshake_buffer && !ssl3_digest_cached_records((int)sender, s) )
    return 0;
  v7 = 0;
  v17 = 0;
  while ( 1 )
  {
    v8 = (ui_string_st **)&s->s3->handshake_dgst[v7];
    if ( *v8 )
    {
      object = X509_EXTENSION_get_object(*v8);
      v10 = EVP_CIPHER_CTX_cipher((const ssl_st *)object) == md_nid;
      v7 = v17;
      if ( v10 )
        break;
    }
    v17 = ++v7;
    if ( v7 >= 4 )
      goto LABEL_9;
  }
  v11 = s->s3->handshake_dgst[v17];
  if ( !v11 )
  {
LABEL_9:
    ERR_put_error((int)sender, 0x14u, 285, 324, ".\\ssl\\s3_enc.c", 671);
    return 0;
  }
  EVP_MD_CTX_init((env_md_ctx_st *)ctx);
  EVP_MD_CTX_copy_ex((int)sender, (env_md_ctx_st *)ctx, v11);
  v13 = X509_EXTENSION_get_object(ctx);
  v14 = EVP_MD_size((int)sender, (const env_md_st *)v13);
  if ( v14 < 0 )
    return 0;
  v15 = v14 * (48 / v14);
  if ( sender )
    EVP_DigestUpdate((env_md_ctx_st *)ctx);
  EVP_DigestUpdate((env_md_ctx_st *)ctx);
  EVP_DigestUpdate((env_md_ctx_st *)ctx);
  EVP_DigestFinal_ex(v15, (int)sender, (env_md_ctx_st *)ctx, (unsigned __int8 *)&ctx[0].flags, &v17);
  v16 = X509_EXTENSION_get_object(ctx);
  EVP_DigestInit_ex(sender, (env_md_ctx_st *)ctx, (const env_md_st *)v16, 0);
  EVP_DigestUpdate((env_md_ctx_st *)ctx);
  EVP_DigestUpdate((env_md_ctx_st *)ctx);
  EVP_DigestUpdate((env_md_ctx_st *)ctx);
  EVP_DigestFinal_ex(v15, (int)sender, (env_md_ctx_st *)ctx, p, (unsigned int *)&ctx[0]._.string_data.test_buf);
  EVP_MD_CTX_cleanup(v15, (int)sender, (env_md_ctx_st *)ctx);
  return ctx[0]._.string_data.test_buf;
}
