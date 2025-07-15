void __usercall ssl3_init_finished_mac(int a1@<edi>, int a2@<ebx>, ssl_st *s)
{
  bio_method_st *v3; // eax

  if ( s->s3->handshake_buffer )
    BIO_free(a1, a2, s->s3->handshake_buffer);
  if ( s->s3->handshake_dgst )
    ssl3_free_digest_list(a2, s);
  v3 = BIO_s_mem();
  s->s3->handshake_buffer = BIO_new(a2, v3);
  BIO_ctrl(a2, s->s3->handshake_buffer, 9, 1, 0);
}
