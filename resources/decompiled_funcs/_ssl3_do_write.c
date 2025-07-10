int __cdecl ssl3_do_write(ssl_st *s, int type)
{
  int v2; // edi
  int init_num; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // ecx

  v2 = ssl3_write_bytes(s, type, &s->init_buf->data[s->init_off], s->init_num);
  if ( v2 < 0 )
    return -1;
  if ( type == 22 )
    ssl3_finish_mac(s, (const unsigned __int8 *)&s->init_buf->data[s->init_off], v2);
  init_num = s->init_num;
  if ( v2 == init_num )
  {
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(1, s->version, type, s->init_buf->data, init_num + s->init_off, s, s->msg_callback_arg);
    return 1;
  }
  else
  {
    s->init_off += v2;
    s->init_num = init_num - v2;
    return 0;
  }
}
