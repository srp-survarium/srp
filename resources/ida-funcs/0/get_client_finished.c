int __usercall get_client_finished@<eax>(ssl_st *s@<esi>)
{
  char *data; // ebx
  int v2; // eax
  int v3; // ecx
  int v5; // eax
  unsigned int conn_id_length; // eax
  unsigned int v7; // ebp
  int init_num; // eax
  int v9; // edi
  int v10; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  ssl2_state_st *s2; // ecx
  unsigned int v13; // eax
  unsigned __int8 *conn_id; // ecx
  _BYTE *v15; // edi

  data = s->init_buf->data;
  if ( s->state != 8272 )
  {
LABEL_9:
    conn_id_length = s->s2->conn_id_length;
    if ( conn_id_length > 0x10 )
    {
      ssl2_return_error(s, 0);
      ERR_put_error((int)data, 0x14u, 105, 68, ".\\ssl\\s2_srvr.c", 848);
      return -1;
    }
    v7 = conn_id_length + 1;
    init_num = s->init_num;
    v9 = v7 - init_num;
    v10 = ssl2_read(s, (unsigned __int8 *)&data[init_num], v7 - init_num);
    if ( v10 < v9 )
      return ssl2_part_read(s, 105, v10);
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(0, s->version, 0, data, v7, s, s->msg_callback_arg);
    s2 = s->s2;
    v13 = s2->conn_id_length;
    conn_id = s2->conn_id;
    v15 = data + 1;
    if ( v13 < 4 )
    {
LABEL_18:
      if ( !v13 || *conn_id == *v15 && (v13 <= 1 || conn_id[1] == v15[1] && (v13 <= 2 || conn_id[2] == v15[2])) )
        return 1;
    }
    else
    {
      while ( *(_DWORD *)v15 == *(_DWORD *)conn_id )
      {
        v13 -= 4;
        conn_id += 4;
        v15 += 4;
        if ( v13 < 4 )
          goto LABEL_18;
      }
    }
    ssl2_return_error(s, 0);
    ERR_put_error((int)data, 0x14u, 105, 143, ".\\ssl\\s2_srvr.c", 864);
    return -1;
  }
  v2 = ssl2_read(s, (unsigned __int8 *)&data[s->init_num], 1 - s->init_num);
  v3 = s->init_num;
  if ( v2 < 1 - v3 )
    return ssl2_part_read(s, 105, v2);
  s->init_num = v2 + v3;
  if ( *data == 3 )
  {
    s->state = 8273;
    goto LABEL_9;
  }
  if ( *data )
  {
    ssl2_return_error(s, 0);
    ERR_put_error((int)data, 0x14u, 105, 212, ".\\ssl\\s2_srvr.c", 830);
    return -1;
  }
  else
  {
    ERR_put_error((int)data, 0x14u, 105, 200, ".\\ssl\\s2_srvr.c", 834);
    v5 = ssl2_read(s, (unsigned __int8 *)&data[s->init_num], 3 - s->init_num);
    return ssl2_part_read(s, 110, v5);
  }
}
