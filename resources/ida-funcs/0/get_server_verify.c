int __usercall get_server_verify@<eax>(ssl_st *s@<esi>, int a2@<ebx>)
{
  char *data; // edi
  int v3; // eax
  int init_num; // ecx
  int v6; // eax
  int v7; // eax
  char *v8; // ebp
  int v9; // ebx
  int v10; // edi
  int v11; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  ssl2_state_st *s2; // ecx
  unsigned int challenge_length; // eax
  unsigned __int8 *challenge; // ecx
  _BYTE *v16; // edi

  data = s->init_buf->data;
  if ( s->state != 4192 )
    goto LABEL_8;
  v3 = ssl2_read(s, (unsigned __int8 *)&data[s->init_num], 1 - s->init_num);
  init_num = s->init_num;
  if ( v3 < 1 - init_num )
    return ssl2_part_read(s, 110, v3);
  s->init_num = v3 + init_num;
  s->state = 4193;
  if ( *data == 5 )
  {
LABEL_8:
    v7 = s->init_num;
    v8 = s->init_buf->data;
    v9 = s->s2->challenge_length + 1;
    v10 = v9 - v7;
    v11 = ssl2_read(s, (unsigned __int8 *)&v8[v7], v9 - v7);
    if ( v11 < v10 )
      return ssl2_part_read(s, 110, v11);
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(0, s->version, 0, v8, v9, s, s->msg_callback_arg);
    s2 = s->s2;
    challenge_length = s2->challenge_length;
    challenge = s2->challenge;
    v16 = v8 + 1;
    if ( challenge_length < 4 )
    {
LABEL_15:
      if ( !challenge_length
        || *challenge == *v16
        && (challenge_length <= 1 || challenge[1] == v16[1] && (challenge_length <= 2 || challenge[2] == v16[2])) )
      {
        return 1;
      }
    }
    else
    {
      while ( *(_DWORD *)v16 == *(_DWORD *)challenge )
      {
        challenge_length -= 4;
        challenge += 4;
        v16 += 4;
        if ( challenge_length < 4 )
          goto LABEL_15;
      }
    }
    ssl2_return_error(s, 0);
    ERR_put_error(v9, 0x14u, 110, 136, ".\\ssl\\s2_clnt.c", 943);
    return -1;
  }
  if ( *data )
  {
    ssl2_return_error(s, 0);
    ERR_put_error(a2, 0x14u, 110, 212, ".\\ssl\\s2_clnt.c", 917);
    return -1;
  }
  else
  {
    ERR_put_error(a2, 0x14u, 110, 200, ".\\ssl\\s2_clnt.c", 921);
    v6 = ssl2_read(s, (unsigned __int8 *)&data[s->init_num], 3 - s->init_num);
    return ssl2_part_read(s, 110, v6);
  }
}
