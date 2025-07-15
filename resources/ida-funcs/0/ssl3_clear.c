void __usercall ssl3_clear(int a1@<ebx>, ssl_st *s)
{
  stack_st_X509_NAME *ca_names; // eax
  ssl3_state_st *s3; // ecx
  ssl3_state_st *v5; // edx
  ssl3_state_st *v6; // eax
  unsigned int len; // edx
  unsigned __int8 *buf; // ebx
  unsigned __int8 *v9; // ebp
  int init_extra; // ecx
  bio_st *handshake_buffer; // eax
  ssl3_state_st *v12; // ecx
  unsigned int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]
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
    DH_free(0, a1, s->s3->tmp.dh);
    s->s3->tmp.dh = 0;
  }
  v5 = s->s3;
  if ( v5->tmp.ecdh )
  {
    EC_KEY_free(v5->tmp.ecdh);
    s->s3->tmp.ecdh = 0;
  }
  v6 = s->s3;
  len = v6->wbuf.len;
  buf = v6->rbuf.buf;
  v9 = v6->wbuf.buf;
  sa = (ssl_st *)v6->rbuf.len;
  init_extra = v6->init_extra;
  handshake_buffer = v6->handshake_buffer;
  v13 = len;
  v14 = init_extra;
  if ( handshake_buffer )
  {
    BIO_free(0, (int)buf, handshake_buffer);
    s->s3->handshake_buffer = 0;
  }
  if ( s->s3->handshake_dgst )
    ssl3_free_digest_list(s);
  memset((int)s->s3, 0, sizeof(ssl3_state_st));
  s->s3->rbuf.buf = buf;
  s->s3->wbuf.buf = v9;
  s->s3->rbuf.len = (unsigned int)sa;
  s->s3->wbuf.len = v13;
  s->s3->init_extra = v14;
  ssl_free_wbio_buffer(0, (int)buf, s);
  v12 = s->s3;
  s->packet_length = 0;
  v12->renegotiate = 0;
  s->s3->total_renegotiations = 0;
  s->s3->num_renegotiations = 0;
  s->s3->in_read_app_data = 0;
  s->version = 768;
}
