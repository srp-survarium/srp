ssl_st *__usercall tls1_cert_verify_mac@<eax>(int a1@<ebx>, ssl_st *s, int md_nid, unsigned __int8 *out)
{
  ssl_st *v4; // edi
  ssl_st *result; // eax
  int v6; // ebx
  int v7; // esi
  ui_string_st **v8; // eax
  ui_string_st *object; // eax
  const env_md_ctx_st *v10; // esi
  env_md_ctx_st ctx; // [esp+4h] [ebp-18h] BYREF

  v4 = s;
  if ( !s->s3->handshake_buffer || (result = (ssl_st *)ssl3_digest_cached_records(a1, s)) != 0 )
  {
    v6 = md_nid;
    v7 = 0;
    while ( 1 )
    {
      v8 = (ui_string_st **)&v4->s3->handshake_dgst[v7];
      if ( *v8 )
      {
        object = X509_EXTENSION_get_object(*v8);
        if ( EVP_CIPHER_CTX_cipher((const ssl_st *)object) == v6 )
          break;
      }
      if ( ++v7 >= 4 )
        goto LABEL_9;
    }
    v10 = v4->s3->handshake_dgst[v7];
    if ( !v10 )
    {
LABEL_9:
      ERR_put_error(v6, 0x14u, 286, 324, ".\\ssl\\t1_enc.c", 811);
      return 0;
    }
    EVP_MD_CTX_init(&ctx);
    EVP_MD_CTX_copy_ex(v6, &ctx, v10);
    EVP_DigestFinal_ex((int)v4, v6, &ctx, out, (unsigned int *)&s);
    EVP_MD_CTX_cleanup((int)v4, v6, &ctx);
    return s;
  }
  return result;
}
