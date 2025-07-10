int __cdecl ssl3_get_new_session_ticket(ssl_st *s)
{
  ssl_st *v1; // edi
  int result; // eax
  ssl3_state_st *s3; // ecx
  int message_type; // edx
  int v5; // esi
  unsigned __int8 *init_msg; // esi
  int v7; // edx
  int v8; // edx
  int v9; // ebx
  unsigned __int8 *v10; // esi
  ssl_session_st *session; // eax
  ssl_session_st *v12; // edi
  const env_md_st *v13; // eax
  int v14; // [esp-Ch] [ebp-10h]

  v1 = s;
  result = s->method->ssl_get_message(s, 4576, 4577, -1, 0x4000, (int *)&s);
  if ( s )
  {
    s3 = v1->s3;
    message_type = s3->tmp.message_type;
    if ( message_type == 20 )
    {
      s3->tmp.reuse_message = 1;
      return 1;
    }
    if ( message_type != 4 )
    {
      v5 = 10;
      ERR_put_error(0x14u, 283, 114, ".\\ssl\\s3_clnt.c", 1834);
LABEL_11:
      ssl3_send_alert(v1, 2, v5);
      return -1;
    }
    if ( result < 6 )
    {
      v14 = 1841;
LABEL_10:
      v5 = 50;
      ERR_put_error(0x14u, 283, 159, ".\\ssl\\s3_clnt.c", v14);
      goto LABEL_11;
    }
    init_msg = (unsigned __int8 *)v1->init_msg;
    v1->session->tlsext_tick_lifetime_hint = *init_msg << 24;
    v7 = *++init_msg;
    v1->session->tlsext_tick_lifetime_hint |= v7 << 16;
    v8 = *++init_msg;
    v1->session->tlsext_tick_lifetime_hint |= v8 << 8;
    v1->session->tlsext_tick_lifetime_hint |= *++init_msg;
    v9 = init_msg[2] | (init_msg[1] << 8);
    v10 = init_msg + 3;
    if ( v9 + 6 != result )
    {
      v14 = 1852;
      goto LABEL_10;
    }
    if ( v1->session->tlsext_tick )
    {
      CRYPTO_free(v1->session->tlsext_tick);
      v1->session->tlsext_ticklen = 0;
    }
    v1->session->tlsext_tick = (unsigned __int8 *)CRYPTO_malloc(v9, ".\\ssl\\s3_clnt.c", 1860);
    session = v1->session;
    if ( session->tlsext_tick )
    {
      memcpy(session->tlsext_tick, v10, v9);
      v1->session->tlsext_ticklen = v9;
      v12 = v1->session;
      v13 = EVP_sha256();
      EVP_Digest((unsigned int)v12->session_id, v10, v9, v12->session_id, &v12->session_id_length, v13, 0);
      return 1;
    }
    else
    {
      ERR_put_error(0x14u, 283, 65, ".\\ssl\\s3_clnt.c", 1863);
      return -1;
    }
  }
  return result;
}
