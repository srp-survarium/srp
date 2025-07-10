void __usercall ssl3_init_finished_mac(unsigned int a1@<edi>, ssl_st *s)
{
  bio_method_st *v2; // eax

  if ( s->s3->handshake_buffer )
    BIO_free(a1, s->s3->handshake_buffer);
  if ( s->s3->handshake_dgst )
    ssl3_free_digest_list(s);
  v2 = BIO_s_mem();
  s->s3->handshake_buffer = BIO_new(v2);
  BIO_ctrl(s->s3->handshake_buffer, 9, 1, 0);
}
