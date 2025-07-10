ssl_st *__cdecl tls1_cert_verify_mac(ssl_st *s, int md_nid, unsigned __int8 *out)
{
  ssl_st *v3; // edi
  ssl_st *result; // eax
  int v5; // ebx
  int v6; // esi
  ui_string_st **v7; // eax
  ui_string_st *object; // eax
  const env_md_ctx_st *v9; // esi
  env_md_ctx_st ctx; // [esp+4h] [ebp-18h] BYREF

  v3 = s;
  if ( !s->s3->handshake_buffer || (result = (ssl_st *)ssl3_digest_cached_records(s)) != 0 )
  {
    v5 = md_nid;
    v6 = 0;
    while ( 1 )
    {
      v7 = (ui_string_st **)&v3->s3->handshake_dgst[v6];
      if ( *v7 )
      {
        object = X509_EXTENSION_get_object(*v7);
        if ( EVP_CIPHER_CTX_cipher((const ssl_st *)object) == v5 )
          break;
      }
      if ( ++v6 >= 4 )
        goto LABEL_9;
    }
    v9 = v3->s3->handshake_dgst[v6];
    if ( !v9 )
    {
LABEL_9:
      ERR_put_error(0x14u, 286, 324, ".\\ssl\\t1_enc.c", 811);
      return 0;
    }
    EVP_MD_CTX_init(&ctx);
    EVP_MD_CTX_copy_ex(&ctx, v9);
    EVP_DigestFinal_ex((unsigned int)v3, &ctx, out, (unsigned int *)&s);
    EVP_MD_CTX_cleanup((unsigned int)v3, &ctx);
    return s;
  }
  return result;
}
