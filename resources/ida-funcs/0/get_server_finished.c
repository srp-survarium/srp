int __usercall get_server_finished@<eax>(ssl_st *s@<esi>, int a2@<ebx>)
{
  char *data; // edi
  int v3; // eax
  int v4; // ecx
  char v6; // al
  int v7; // eax
  int init_num; // eax
  int v9; // ebx
  int v10; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  int v12; // ecx
  _DWORD *v13; // edi
  unsigned __int8 *v14; // eax
  ssl_session_st *session; // edx
  unsigned int session_id_length; // ecx
  unsigned __int8 *session_id; // edx
  unsigned __int8 *v18; // edi
  int v19; // eax

  data = s->init_buf->data;
  if ( s->state != 4208 )
  {
LABEL_11:
    init_num = s->init_num;
    v9 = 17 - init_num;
    v10 = ssl2_read(s, (unsigned __int8 *)&data[init_num], 17 - init_num);
    if ( v10 < v9 )
      return ssl2_part_read(s, 108, v10);
    s->init_num += v10;
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
          v18 = (unsigned __int8 *)(data + 1);
          if ( session_id_length < 4 )
          {
LABEL_23:
            if ( !session_id_length )
              goto LABEL_17;
          }
          else
          {
            while ( *(_DWORD *)v18 == *(_DWORD *)session_id )
            {
              session_id_length -= 4;
              session_id += 4;
              v18 += 4;
              if ( session_id_length < 4 )
                goto LABEL_23;
            }
          }
          v9 = *session_id;
          v19 = *v18 - v9;
          if ( !v19 )
          {
            if ( session_id_length <= 1 )
              goto LABEL_17;
            v9 = session_id[1];
            v19 = v18[1] - v9;
            if ( !v19 )
            {
              if ( session_id_length <= 2 )
                goto LABEL_17;
              v9 = session_id[2];
              v19 = v18[2] - v9;
              if ( !v19 )
              {
                if ( session_id_length <= 3 )
                  goto LABEL_17;
                v19 = v18[3] - session_id[3];
              }
            }
          }
          if ( !((v19 >> 31) | 1) )
            goto LABEL_17;
        }
        ssl2_return_error(s, 0);
        ERR_put_error(v9, 0x14u, 108, 231, ".\\ssl\\s2_clnt.c", 1015);
        return -1;
      }
    }
    else
    {
      s->session->session_id_length = 16;
      v12 = *(_DWORD *)(data + 1);
      v13 = data + 1;
      v14 = s->session->session_id;
      *(_DWORD *)v14 = v12;
      *((_DWORD *)v14 + 1) = v13[1];
      *((_DWORD *)v14 + 2) = v13[2];
      *((_DWORD *)v14 + 3) = v13[3];
    }
LABEL_17:
    s->state = 3;
    return 1;
  }
  v3 = ssl2_read(s, (unsigned __int8 *)&data[s->init_num], 1 - s->init_num);
  v4 = s->init_num;
  if ( v3 < 1 - v4 )
    return ssl2_part_read(s, 108, v3);
  s->init_num = v3 + v4;
  v6 = *data;
  if ( *data == 7 )
  {
    s->state = 4176;
    return 1;
  }
  if ( v6 == 6 )
  {
    s->state = 4209;
    goto LABEL_11;
  }
  if ( v6 )
  {
    ssl2_return_error(s, 0);
    ERR_put_error(a2, 0x14u, 108, 212, ".\\ssl\\s2_clnt.c", 974);
    return -1;
  }
  else
  {
    ERR_put_error(a2, 0x14u, 108, 200, ".\\ssl\\s2_clnt.c", 978);
    v7 = ssl2_read(s, (unsigned __int8 *)&data[s->init_num], 3 - s->init_num);
    return ssl2_part_read(s, 110, v7);
  }
}
