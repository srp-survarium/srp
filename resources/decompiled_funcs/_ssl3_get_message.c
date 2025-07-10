int __cdecl ssl3_get_message(ssl_st *s, int st1, int stn, int mt, unsigned int max, int *ok)
{
  ssl3_state_st *s3; // eax
  int v7; // edi
  ssl3_state_st *v8; // edx
  int result; // eax
  char *data; // edi
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  unsigned int v12; // ebp
  buf_mem_st *init_buf; // edx
  int v14; // edi
  unsigned __int8 *init_msg; // ebp
  void (__cdecl *v16)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  int v17; // [esp-4h] [ebp-14h]

  s3 = s->s3;
  if ( s3->tmp.reuse_message )
  {
    s3->tmp.reuse_message = 0;
    if ( mt < 0 || s->s3->tmp.message_type == mt )
    {
      *ok = 1;
      v8 = s->s3;
      s->init_msg = s->init_buf->data + 4;
      result = v8->tmp.message_size;
      s->init_num = result;
    }
    else
    {
      v7 = 10;
      ERR_put_error(0x14u, 142, 244, ".\\ssl\\s3_both.c", 407);
LABEL_30:
      ssl3_send_alert(s, 2, v7);
      *ok = 0;
      return -1;
    }
  }
  else
  {
    data = s->init_buf->data;
    if ( s->state == st1 )
    {
      while ( 1 )
      {
        if ( s->init_num < 4 )
        {
          while ( 1 )
          {
            result = s->method->ssl_read_bytes(s, 22, (unsigned __int8 *)&data[s->init_num], 4 - s->init_num, 0);
            if ( result <= 0 )
              break;
            s->init_num += result;
            if ( s->init_num >= 4 )
              goto LABEL_10;
          }
          s->rwstate = 3;
          *ok = 0;
          return result;
        }
LABEL_10:
        if ( s->server || *data || data[1] || data[2] || data[3] )
          break;
        msg_callback = s->msg_callback;
        s->init_num = 0;
        if ( msg_callback )
          msg_callback(0, s->version, 22, data, 4u, s, s->msg_callback_arg);
      }
      if ( mt < 0 )
      {
        if ( *data == 1 && st1 == 8576 && stn == 8577 )
          ssl3_init_finished_mac(s);
      }
      else if ( (unsigned __int8)*data != mt )
      {
        v7 = 10;
        ERR_put_error(0x14u, 142, 244, ".\\ssl\\s3_both.c", 460);
        goto LABEL_30;
      }
      s->s3->tmp.message_type = (unsigned __int8)*data;
      v12 = (unsigned __int8)data[3] | ((((unsigned __int8)data[1] << 8) | (unsigned __int8)data[2]) << 8);
      if ( v12 > max )
      {
        v17 = 481;
LABEL_29:
        v7 = 47;
        ERR_put_error(0x14u, 142, 152, ".\\ssl\\s3_both.c", v17);
        goto LABEL_30;
      }
      if ( v12 > 0x7FFFFFFB )
      {
        v17 = 487;
        goto LABEL_29;
      }
      if ( v12 && !BUF_MEM_grow_clean(s->init_buf, v12 + 4) )
      {
        ERR_put_error(0x14u, 142, 7, ".\\ssl\\s3_both.c", 492);
        *ok = 0;
        return -1;
      }
      s->s3->tmp.message_size = v12;
      init_buf = s->init_buf;
      s->state = stn;
      s->init_msg = init_buf->data + 4;
      s->init_num = 0;
    }
    v14 = s->s3->tmp.message_size - s->init_num;
    init_msg = (unsigned __int8 *)s->init_msg;
    if ( v14 <= 0 )
    {
LABEL_38:
      ssl3_finish_mac(s, (const unsigned __int8 *)s->init_buf->data, s->init_num + 4);
      v16 = s->msg_callback;
      if ( v16 )
        v16(0, s->version, 22, s->init_buf->data, s->init_num + 4, s, s->msg_callback_arg);
      *ok = 1;
      return s->init_num;
    }
    else
    {
      while ( 1 )
      {
        result = s->method->ssl_read_bytes(s, 22, &init_msg[s->init_num], v14, 0);
        if ( result <= 0 )
          break;
        s->init_num += result;
        v14 -= result;
        if ( v14 <= 0 )
          goto LABEL_38;
      }
      s->rwstate = 3;
      *ok = 0;
    }
  }
  return result;
}
