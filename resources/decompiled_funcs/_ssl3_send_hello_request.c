int __cdecl ssl3_send_hello_request(ssl_st *s)
{
  char *data; // eax

  if ( s->state == 8480 )
  {
    data = s->init_buf->data;
    *data = 0;
    data[1] = 0;
    data += 2;
    *data = 0;
    data[1] = 0;
    s->state = 8481;
    s->init_num = 4;
    s->init_off = 0;
  }
  return ssl3_do_write(s, 22);
}
