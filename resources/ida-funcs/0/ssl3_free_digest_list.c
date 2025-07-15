void __cdecl ssl3_free_digest_list(ssl_st *s)
{
  int i; // esi
  env_md_ctx_st **v2; // eax

  if ( s->s3->handshake_dgst )
  {
    for ( i = 0; i < 4; ++i )
    {
      v2 = &s->s3->handshake_dgst[i];
      if ( *v2 )
        EVP_MD_CTX_destroy((unsigned int)s, *v2);
    }
    CRYPTO_free(s->s3->handshake_dgst);
    s->s3->handshake_dgst = 0;
  }
}
