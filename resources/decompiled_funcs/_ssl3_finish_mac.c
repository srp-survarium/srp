void __cdecl ssl3_finish_mac(ssl_st *s, const unsigned __int8 *buf, int len)
{
  int i; // esi
  env_md_ctx_st **v4; // eax

  if ( s->s3->handshake_buffer )
  {
    BIO_write(s->s3->handshake_buffer, (const char *)buf, len);
  }
  else
  {
    for ( i = 0; i < 4; ++i )
    {
      v4 = &s->s3->handshake_dgst[i];
      if ( *v4 )
        EVP_DigestUpdate(*v4);
    }
  }
}
