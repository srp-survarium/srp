int __cdecl client_hello(ssl_st *s)
{
  bool v2; // zf
  char *data; // esi
  ssl_session_st *session; // eax
  unsigned __int8 *v6; // edi
  _BYTE *v7; // esi
  _BYTE *v8; // esi
  stack_st_SSL_CIPHER *ciphers; // eax
  int v10; // eax
  unsigned __int8 *v11; // edi
  unsigned int session_id_length; // ebx
  _BYTE *v13; // esi
  _BYTE *v14; // esi
  ssl2_state_st *s2; // eax
  int v16; // ecx
  unsigned __int8 *buf; // [esp+14h] [ebp+4h]

  v2 = s->state == 4112;
  data = s->init_buf->data;
  buf = (unsigned __int8 *)data;
  if ( v2 )
  {
    session = s->session;
    if ( (!session || session->ssl_version != s->version) && !ssl_get_new_session(s, 0) )
    {
      ssl2_return_error(s, 0);
      return -1;
    }
    *data = 1;
    v6 = (unsigned __int8 *)(data + 9);
    v7 = data + 1;
    *v7 = 0;
    v7[1] = 2;
    v8 = v7 + 2;
    ciphers = SSL_get_ciphers(s);
    v10 = ssl_cipher_list_to_bytes(s, ciphers, v6, 0);
    v11 = &v6[v10];
    if ( !v10 )
    {
      ERR_put_error(0x14u, 101, 181, ".\\ssl\\s2_clnt.c", 575);
      return -1;
    }
    *v8 = BYTE1(v10);
    v8[1] = v10;
    session_id_length = s->session->session_id_length;
    v13 = v8 + 2;
    if ( session_id_length && session_id_length <= 0x20 )
    {
      *v13 = BYTE1(session_id_length);
      v13[1] = session_id_length;
      v14 = v13 + 2;
      memcpy(v11, s->session->session_id, session_id_length);
      v11 += session_id_length;
    }
    else
    {
      *v13 = 0;
      v13[1] = 0;
      v14 = v13 + 2;
    }
    s->s2->challenge_length = 16;
    *v14 = 0;
    v14[1] = 16;
    if ( RAND_pseudo_bytes() <= 0 )
      return -1;
    s2 = s->s2;
    *(_DWORD *)v11 = *(_DWORD *)s2->challenge;
    v16 = *(_DWORD *)&s2->challenge[4];
    s2 = (ssl2_state_st *)((char *)s2 + 104);
    *((_DWORD *)v11 + 1) = v16;
    *((_DWORD *)v11 + 2) = s2->escape;
    *((_DWORD *)v11 + 3) = s2->ssl2_rollback;
    s->state = 4113;
    s->init_num = v11 - buf + 16;
    s->init_off = 0;
  }
  return ssl2_do_write(s);
}
