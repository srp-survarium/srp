void __usercall ssl3_free_digest_list(int a1@<ebx>, ssl_st *s)
{
  int i; // esi
  env_md_ctx_st **v3; // eax

  if ( s->s3->handshake_dgst )
  {
    for ( i = 0; i < 4; ++i )
    {
      v3 = &s->s3->handshake_dgst[i];
      if ( *v3 )
        EVP_MD_CTX_destroy((int)s, a1, *v3);
    }
    CRYPTO_free(s->s3->handshake_dgst);
    s->s3->handshake_dgst = 0;
  }
}
