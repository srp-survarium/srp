int __cdecl ssl3_send_change_cipher_spec(ssl_st *s, int a, int b)
{
  if ( s->state == a )
  {
    *s->init_buf->data = 1;
    s->init_num = 1;
    s->init_off = 0;
    s->state = b;
  }
  return ssl3_do_write(s, 20);
}
