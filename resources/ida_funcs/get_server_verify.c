int __usercall get_server_verify@<eax>(ssl_st *s@<esi>)
{
  char *data; // edi
  int v2; // eax
  int init_num; // ecx
  int v5; // eax
  int v6; // eax
  char *v7; // ebp
  unsigned int v8; // ebx
  int v9; // edi
  int v10; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  ssl2_state_st *s2; // ecx
  unsigned int challenge_length; // eax
  unsigned __int8 *challenge; // ecx
  _BYTE *v15; // edi

  data = s->init_buf->data;
  if ( s->state != 4192 )
    goto LABEL_8;
  v2 = ssl2_read(s, &data[s->init_num], 1 - s->init_num);
  init_num = s->init_num;
  if ( v2 < 1 - init_num )
    return ssl2_part_read(s, 0x6Eu, v2);
  s->init_num = v2 + init_num;
  s->state = 4193;
  if ( *data == 5 )
  {
LABEL_8:
    v6 = s->init_num;
    v7 = s->init_buf->data;
    v8 = s->s2->challenge_length + 1;
    v9 = v8 - v6;
    v10 = ssl2_read(s, &v7[v6], v8 - v6);
    if ( v10 < v9 )
      return ssl2_part_read(s, 0x6Eu, v10);
    msg_callback = s->msg_callback;
    if ( msg_callback )
      msg_callback(0, s->version, 0, v7, v8, s, s->msg_callback_arg);
    s2 = s->s2;
    challenge_length = s2->challenge_length;
    challenge = s2->challenge;
    v15 = v7 + 1;
    if ( challenge_length < 4 )
    {
LABEL_15:
      if ( !challenge_length
        || *challenge == *v15
        && (challenge_length <= 1 || challenge[1] == v15[1] && (challenge_length <= 2 || challenge[2] == v15[2])) )
      {
        return 1;
      }
    }
    else
    {
      while ( *(_DWORD *)v15 == *(_DWORD *)challenge )
      {
        challenge_length -= 4;
        challenge += 4;
        v15 += 4;
        if ( challenge_length < 4 )
          goto LABEL_15;
      }
    }
    ssl2_return_error(s, 0);
    ERR_put_error(0x14u, 110, 136, ".\\ssl\\s2_clnt.c", 943);
    return -1;
  }
  if ( *data )
  {
    ssl2_return_error(s, 0);
    ERR_put_error(0x14u, 110, 212, ".\\ssl\\s2_clnt.c", 917);
    return -1;
  }
  else
  {
    ERR_put_error(0x14u, 110, 200, ".\\ssl\\s2_clnt.c", 921);
    v5 = ssl2_read(s, &data[s->init_num], 3 - s->init_num);
    return ssl2_part_read(s, 0x6Eu, v5);
  }
}
