int __cdecl ssl3_setup_write_buffer(ssl_st *s)
{
  int v1; // eax
  int v2; // ecx
  unsigned int options; // eax
  unsigned int max_send_fragment; // edx
  int v5; // ebx
  unsigned __int8 *v6; // eax

  if ( EVP_CIPHER_CTX_cipher(s) == 65279 || (v1 = EVP_CIPHER_CTX_cipher(s), v2 = 5, v1 == 256) )
    v2 = 14;
  if ( !s->s3->wbuf.buf )
  {
    options = s->options;
    max_send_fragment = s->max_send_fragment;
    v5 = max_send_fragment + v2 + 83;
    if ( ((unsigned int)&loc_20000 & options) == 0 )
      v5 = max_send_fragment + v2 + 1107;
    if ( (options & 0x800) == 0 )
      v5 += v2 + 83;
    v6 = (unsigned __int8 *)freelist_extract(s->ctx, v5, 0);
    if ( !v6 )
    {
      ERR_put_error(0x14u, 291, 65, ".\\ssl\\s3_both.c", 780);
      return 0;
    }
    s->s3->wbuf.buf = v6;
    s->s3->wbuf.len = v5;
  }
  return 1;
}
