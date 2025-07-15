void __usercall ssl3_free(int a1@<edi>, int a2@<ebx>, ssl_st *s)
{
  ssl3_state_st *s3; // edx
  ssl3_state_st *v4; // ecx
  stack_st_X509_NAME *ca_names; // eax

  if ( s )
  {
    ssl3_cleanup_key_block(s);
    if ( s->s3->rbuf.buf )
      ssl3_release_read_buffer(s);
    if ( s->s3->wbuf.buf )
      ssl3_release_write_buffer(s);
    s3 = s->s3;
    if ( s3->rrec.comp )
      CRYPTO_free(s3->rrec.comp);
    if ( s->s3->tmp.dh )
      DH_free(a1, a2, s->s3->tmp.dh);
    v4 = s->s3;
    if ( v4->tmp.ecdh )
      EC_KEY_free(v4->tmp.ecdh);
    ca_names = s->s3->tmp.ca_names;
    if ( ca_names )
      sk_pop_free(&ca_names->stack, (void (__cdecl *)(void *))X509_NAME_free);
    if ( s->s3->handshake_buffer )
      BIO_free(a1, a2, s->s3->handshake_buffer);
    if ( s->s3->handshake_dgst )
      ssl3_free_digest_list(s);
    OPENSSL_cleanse(s->s3, 1052);
    CRYPTO_free(s->s3);
    s->s3 = 0;
  }
}
