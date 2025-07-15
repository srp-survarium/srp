int __cdecl ssl2_do_write(ssl_st *s)
{
  int v1; // eax
  int init_num; // ecx
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax

  v1 = ssl2_write(s, (unsigned __int8 *)&s->init_buf->data[s->init_off], s->init_num);
  init_num = s->init_num;
  if ( v1 == init_num )
  {
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(1, s->version, 0, s->init_buf->data, init_num + s->init_off, s, s->msg_callback_arg);
    return 1;
  }
  else if ( v1 >= 0 )
  {
    s->init_off += v1;
    s->init_num = init_num - v1;
    return 0;
  }
  else
  {
    return -1;
  }
}
