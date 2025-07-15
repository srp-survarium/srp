void __usercall ssl3_finish_mac(int a1@<ebx>, ssl_st *s, const char *buf, int len)
{
  int i; // esi
  env_md_ctx_st **v5; // eax

  if ( s->s3->handshake_buffer )
  {
    BIO_write(a1, s->s3->handshake_buffer, buf, len);
  }
  else
  {
    for ( i = 0; i < 4; ++i )
    {
      v5 = &s->s3->handshake_dgst[i];
      if ( *v5 )
        EVP_DigestUpdate(*v5);
    }
  }
}
