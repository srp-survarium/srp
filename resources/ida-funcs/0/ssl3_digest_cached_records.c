int __usercall ssl3_digest_cached_records@<eax>(int a1@<ebx>, ssl_st *s)
{
  ssl_st *v2; // esi
  env_md_ctx_st **handshake_dgst; // ecx
  engine_st *v4; // ebx
  unsigned int i; // edi
  ssl3_state_st *s3; // eax
  int v8; // [esp+8h] [ebp-8h] BYREF
  int parg; // [esp+Ch] [ebp-4h] BYREF

  v2 = s;
  ssl3_free_digest_list(a1, s);
  v2->s3->handshake_dgst = (env_md_ctx_st **)CRYPTO_malloc(16, ".\\ssl\\s3_enc.c", 604);
  handshake_dgst = v2->s3->handshake_dgst;
  *handshake_dgst = 0;
  handshake_dgst[1] = 0;
  handshake_dgst[2] = 0;
  handshake_dgst[3] = 0;
  v4 = (engine_st *)BIO_ctrl(a1, v2->s3->handshake_buffer, 3, 0, &parg);
  if ( (int)v4 > 0 )
  {
    for ( i = 0; ssl_get_handshake_digest(i, &v8, (const env_md_st **)&s); ++i )
    {
      s3 = v2->s3;
      if ( (v8 & s3->tmp.new_cipher->algorithm2) != 0 && s )
      {
        v2->s3->handshake_dgst[i] = EVP_MD_CTX_create();
        EVP_DigestInit_ex(v4, v2->s3->handshake_dgst[i], (const env_md_st *)s, 0);
        EVP_DigestUpdate(v2->s3->handshake_dgst[i]);
      }
      else
      {
        s3->handshake_dgst[i] = 0;
      }
    }
    BIO_free(i, (int)v4, v2->s3->handshake_buffer);
    v2->s3->handshake_buffer = 0;
    return 1;
  }
  else
  {
    ERR_put_error((int)v4, 0x14u, 293, 332, ".\\ssl\\s3_enc.c", 609);
    return 0;
  }
}
