int __cdecl ssl3_digest_cached_records(ssl_st *s)
{
  ssl_st *v1; // esi
  env_md_ctx_st **handshake_dgst; // ecx
  unsigned int i; // edi
  ssl3_state_st *s3; // eax
  int mask; // [esp+8h] [ebp-8h] BYREF
  int parg; // [esp+Ch] [ebp-4h] BYREF

  v1 = s;
  ssl3_free_digest_list(s);
  v1->s3->handshake_dgst = (env_md_ctx_st **)CRYPTO_malloc(16, ".\\ssl\\s3_enc.c", 604);
  handshake_dgst = v1->s3->handshake_dgst;
  *handshake_dgst = 0;
  handshake_dgst[1] = 0;
  handshake_dgst[2] = 0;
  handshake_dgst[3] = 0;
  if ( BIO_ctrl(v1->s3->handshake_buffer, 3, 0, &parg) > 0 )
  {
    for ( i = 0; ssl_get_handshake_digest(i, &mask, (const env_md_st **)&s); ++i )
    {
      s3 = v1->s3;
      if ( (mask & s3->tmp.new_cipher->algorithm2) != 0 && s )
      {
        v1->s3->handshake_dgst[i] = EVP_MD_CTX_create();
        EVP_DigestInit_ex(v1->s3->handshake_dgst[i], (const env_md_st *)s, 0);
        EVP_DigestUpdate(v1->s3->handshake_dgst[i]);
      }
      else
      {
        s3->handshake_dgst[i] = 0;
      }
    }
    BIO_free(i, v1->s3->handshake_buffer);
    v1->s3->handshake_buffer = 0;
    return 1;
  }
  else
  {
    ERR_put_error(0x14u, 293, 332, ".\\ssl\\s3_enc.c", 609);
    return 0;
  }
}
