int __usercall ssl2_do_write@<eax>(int a1@<ebx>, ssl_st *s)
{
  int v2; // eax
  int init_num; // ecx
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax

  v2 = ssl2_write(a1, s, (unsigned __int8 *)&s->init_buf->data[s->init_off], s->init_num);
  init_num = s->init_num;
  if ( v2 == init_num )
  {
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(1, s->version, 0, s->init_buf->data, init_num + s->init_off, s, s->msg_callback_arg);
    return 1;
  }
  else if ( v2 >= 0 )
  {
    s->init_off += v2;
    s->init_num = init_num - v2;
    return 0;
  }
  else
  {
    return -1;
  }
}
