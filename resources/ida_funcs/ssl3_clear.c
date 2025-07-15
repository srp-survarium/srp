void __cdecl ssl3_clear(ssl_st *s)
{
  stack_st_X509_NAME *ca_names; // eax
  ssl3_state_st *s3; // ecx
  ssl3_state_st *v4; // edx
  ssl3_state_st *v5; // eax
  unsigned int len; // edx
  unsigned __int8 *buf; // ebx
  unsigned __int8 *v8; // ebp
  int init_extra; // ecx
  bio_st *handshake_buffer; // eax
  ssl3_state_st *v11; // ecx
  unsigned int v12; // [esp+10h] [ebp-8h]
  int v13; // [esp+14h] [ebp-4h]
  ssl_st *sa; // [esp+1Ch] [ebp+4h]

  ssl3_cleanup_key_block(s);
  ca_names = s->s3->tmp.ca_names;
  if ( ca_names )
    sk_pop_free(&ca_names->stack, (void (__cdecl *)(void *))X509_NAME_free);
  s3 = s->s3;
  if ( s3->rrec.comp )
  {
    CRYPTO_free(s3->rrec.comp);
    s->s3->rrec.comp = 0;
  }
  if ( s->s3->tmp.dh )
  {
    DH_free(0, s->s3->tmp.dh);
    s->s3->tmp.dh = 0;
  }
  v4 = s->s3;
  if ( v4->tmp.ecdh )
  {
    EC_KEY_free(v4->tmp.ecdh);
    s->s3->tmp.ecdh = 0;
  }
  v5 = s->s3;
  len = v5->wbuf.len;
  buf = v5->rbuf.buf;
  v8 = v5->wbuf.buf;
  sa = (ssl_st *)v5->rbuf.len;
  init_extra = v5->init_extra;
  handshake_buffer = v5->handshake_buffer;
  v12 = len;
  v13 = init_extra;
  if ( handshake_buffer )
  {
    BIO_free(0, handshake_buffer);
    s->s3->handshake_buffer = 0;
  }
  if ( s->s3->handshake_dgst )
    ssl3_free_digest_list(s);
  memset((int)s->s3, 0, sizeof(ssl3_state_st));
  s->s3->rbuf.buf = buf;
  s->s3->wbuf.buf = v8;
  s->s3->rbuf.len = (unsigned int)sa;
  s->s3->wbuf.len = v12;
  s->s3->init_extra = v13;
  ssl_free_wbio_buffer(0, s);
  v11 = s->s3;
  s->packet_length = 0;
  v11->renegotiate = 0;
  s->s3->total_renegotiations = 0;
  s->s3->num_renegotiations = 0;
  s->s3->in_read_app_data = 0;
  s->version = 768;
}
