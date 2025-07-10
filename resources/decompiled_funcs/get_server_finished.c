int __usercall get_server_finished@<eax>(ssl_st *s@<esi>)
{
  char *data; // edi
  int v2; // eax
  int v3; // ecx
  char v5; // al
  int v6; // eax
  int init_num; // eax
  int v8; // ebx
  int v9; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  int v11; // ecx
  _DWORD *v12; // edi
  unsigned __int8 *v13; // eax
  ssl_session_st *session; // edx
  unsigned int session_id_length; // ecx
  unsigned __int8 *session_id; // edx
  unsigned __int8 *v17; // edi
  int v18; // eax

  data = s->init_buf->data;
  if ( s->state != 4208 )
  {
LABEL_11:
    init_num = s->init_num;
    v8 = 17 - init_num;
    v9 = ssl2_read(s, &data[init_num], 17 - init_num);
    if ( v9 < v8 )
      return ssl2_part_read(s, 0x6Cu, v9);
    s->init_num += v9;
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(0, s->version, 0, data, s->init_num, s, s->msg_callback_arg);
    if ( s->hit )
    {
      if ( (s->options & 1) == 0 )
      {
        session = s->session;
        session_id_length = session->session_id_length;
        if ( session_id_length <= 0x20 )
        {
          session_id = session->session_id;
          v17 = (unsigned __int8 *)(data + 1);
          if ( session_id_length < 4 )
          {
LABEL_23:
            if ( !session_id_length )
              goto LABEL_17;
          }
          else
          {
            while ( *(_DWORD *)v17 == *(_DWORD *)session_id )
            {
              session_id_length -= 4;
              session_id += 4;
              v17 += 4;
              if ( session_id_length < 4 )
                goto LABEL_23;
            }
          }
          v18 = *v17 - *session_id;
          if ( !v18 )
          {
            if ( session_id_length <= 1 )
              goto LABEL_17;
            v18 = v17[1] - session_id[1];
            if ( !v18 )
            {
              if ( session_id_length <= 2 )
                goto LABEL_17;
              v18 = v17[2] - session_id[2];
              if ( !v18 )
              {
                if ( session_id_length <= 3 )
                  goto LABEL_17;
                v18 = v17[3] - session_id[3];
              }
            }
          }
          if ( !((v18 >> 31) | 1) )
            goto LABEL_17;
        }
        ssl2_return_error(s, 0);
        ERR_put_error(0x14u, 108, 231, ".\\ssl\\s2_clnt.c", 1015);
        return -1;
      }
    }
    else
    {
      s->session->session_id_length = 16;
      v11 = *(_DWORD *)(data + 1);
      v12 = data + 1;
      v13 = s->session->session_id;
      *(_DWORD *)v13 = v11;
      *((_DWORD *)v13 + 1) = v12[1];
      *((_DWORD *)v13 + 2) = v12[2];
      *((_DWORD *)v13 + 3) = v12[3];
    }
LABEL_17:
    s->state = 3;
    return 1;
  }
  v2 = ssl2_read(s, &data[s->init_num], 1 - s->init_num);
  v3 = s->init_num;
  if ( v2 < 1 - v3 )
    return ssl2_part_read(s, 0x6Cu, v2);
  s->init_num = v2 + v3;
  v5 = *data;
  if ( *data == 7 )
  {
    s->state = 4176;
    return 1;
  }
  if ( v5 == 6 )
  {
    s->state = 4209;
    goto LABEL_11;
  }
  if ( v5 )
  {
    ssl2_return_error(s, 0);
    ERR_put_error(0x14u, 108, 212, ".\\ssl\\s2_clnt.c", 974);
    return -1;
  }
  else
  {
    ERR_put_error(0x14u, 108, 200, ".\\ssl\\s2_clnt.c", 978);
    v6 = ssl2_read(s, &data[s->init_num], 3 - s->init_num);
    return ssl2_part_read(s, 0x6Eu, v6);
  }
}
