int __cdecl ssl3_setup_read_buffer(ssl_st *s)
{
  int v1; // eax
  int v2; // ecx
  ssl3_state_st *s3; // eax
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax

  if ( EVP_CIPHER_CTX_cipher(s) == 65279 || (v1 = EVP_CIPHER_CTX_cipher(s), v2 = 5, v1 == 256) )
    v2 = 13;
  s3 = s->s3;
  if ( !s3->rbuf.buf )
  {
    v4 = v2 + 16707;
    if ( (s->options & 0x20) != 0 )
    {
      s3->init_extra = 1;
      v4 = v2 + 33091;
    }
    if ( ((unsigned int)&loc_20000 & s->options) == 0 )
      v4 += 1024;
    v5 = (unsigned __int8 *)freelist_extract(s->ctx, v4, 1);
    if ( !v5 )
    {
      ERR_put_error(0x14u, 156, 65, ".\\ssl\\s3_both.c", 740);
      return 0;
    }
    s->s3->rbuf.buf = v5;
    s->s3->rbuf.len = v4;
  }
  s->packet = s->s3->rbuf.buf;
  return 1;
}
