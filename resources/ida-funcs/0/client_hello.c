int __usercall client_hello@<eax>(int a1@<ebx>, ssl_st *s)
{
  bool v3; // zf
  char *data; // esi
  ssl_session_st *session; // eax
  unsigned __int8 *v7; // edi
  _BYTE *v8; // esi
  _BYTE *v9; // esi
  stack_st_SSL_CIPHER *ciphers; // eax
  int v11; // eax
  char *v12; // edi
  unsigned int session_id_length; // ebx
  _BYTE *v14; // esi
  _BYTE *v15; // esi
  ssl2_state_st *s2; // eax
  int v17; // ecx
  ssl_st *sa; // [esp+14h] [ebp+4h]

  v3 = s->state == 4112;
  data = s->init_buf->data;
  sa = (ssl_st *)data;
  if ( v3 )
  {
    session = s->session;
    if ( (!session || session->ssl_version != s->version) && !ssl_get_new_session(s, 0) )
    {
      ssl2_return_error(s, 0);
      return -1;
    }
    *data = 1;
    v7 = (unsigned __int8 *)(data + 9);
    v8 = data + 1;
    *v8 = 0;
    v8[1] = 2;
    v9 = v8 + 2;
    ciphers = SSL_get_ciphers(s);
    v11 = ssl_cipher_list_to_bytes(s, ciphers, v7, 0);
    v12 = (char *)&v7[v11];
    if ( !v11 )
    {
      ERR_put_error(a1, 0x14u, 101, 181, ".\\ssl\\s2_clnt.c", 575);
      return -1;
    }
    *v9 = BYTE1(v11);
    v9[1] = v11;
    session_id_length = s->session->session_id_length;
    v14 = v9 + 2;
    if ( session_id_length && session_id_length <= 0x20 )
    {
      *v14 = BYTE1(session_id_length);
      v14[1] = session_id_length;
      v15 = v14 + 2;
      memcpy((int)v12, (const __m128i *)s->session->session_id, session_id_length);
      v12 += session_id_length;
    }
    else
    {
      *v14 = 0;
      v14[1] = 0;
      v15 = v14 + 2;
    }
    s->s2->challenge_length = 16;
    *v15 = 0;
    v15[1] = 16;
    if ( RAND_pseudo_bytes((int)v12) <= 0 )
      return -1;
    s2 = s->s2;
    *(_DWORD *)v12 = *(_DWORD *)s2->challenge;
    v17 = *(_DWORD *)&s2->challenge[4];
    s2 = (ssl2_state_st *)((char *)s2 + 104);
    *((_DWORD *)v12 + 1) = v17;
    *((_DWORD *)v12 + 2) = s2->escape;
    *((_DWORD *)v12 + 3) = s2->ssl2_rollback;
    s->state = 4113;
    s->init_num = v12 - (char *)sa + 16;
    s->init_off = 0;
  }
  return ssl2_do_write(s);
}
