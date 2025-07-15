int __usercall ssl3_get_new_session_ticket@<eax>(engine_st *a1@<ebx>, ssl_st *s)
{
  ssl_st *v2; // edi
  int result; // eax
  ssl3_state_st *s3; // ecx
  int message_type; // edx
  int v6; // esi
  unsigned __int8 *init_msg; // esi
  int v8; // edx
  int v9; // edx
  __m128i *v10; // esi
  ssl_session_st *session; // eax
  ssl_session_st *v12; // edi
  const env_md_st *v13; // eax
  int v14; // [esp-Ch] [ebp-10h]

  v2 = s;
  result = s->method->ssl_get_message(s, 4576, 4577, -1, 0x4000, (int *)&s);
  if ( s )
  {
    s3 = v2->s3;
    message_type = s3->tmp.message_type;
    if ( message_type == 20 )
    {
      s3->tmp.reuse_message = 1;
      return 1;
    }
    if ( message_type != 4 )
    {
      v6 = 10;
      ERR_put_error((int)a1, 0x14u, 283, 114, ".\\ssl\\s3_clnt.c", 1834);
LABEL_11:
      ssl3_send_alert(v2, 2, v6);
      return -1;
    }
    if ( result < 6 )
    {
      v14 = 1841;
LABEL_10:
      v6 = 50;
      ERR_put_error((int)a1, 0x14u, 283, 159, ".\\ssl\\s3_clnt.c", v14);
      goto LABEL_11;
    }
    init_msg = (unsigned __int8 *)v2->init_msg;
    v2->session->tlsext_tick_lifetime_hint = *init_msg << 24;
    v8 = *++init_msg;
    v2->session->tlsext_tick_lifetime_hint |= v8 << 16;
    v9 = *++init_msg;
    v2->session->tlsext_tick_lifetime_hint |= v9 << 8;
    v2->session->tlsext_tick_lifetime_hint |= *++init_msg;
    a1 = (engine_st *)(init_msg[2] | (init_msg[1] << 8));
    v10 = (__m128i *)(init_msg + 3);
    if ( (const char **)((char *)&a1->name + 2) != (const char **)result )
    {
      v14 = 1852;
      goto LABEL_10;
    }
    if ( v2->session->tlsext_tick )
    {
      CRYPTO_free(v2->session->tlsext_tick);
      v2->session->tlsext_ticklen = 0;
    }
    v2->session->tlsext_tick = (unsigned __int8 *)CRYPTO_malloc((int)a1, ".\\ssl\\s3_clnt.c", 1860);
    session = v2->session;
    if ( session->tlsext_tick )
    {
      memcpy((int)session->tlsext_tick, v10, (unsigned int)a1);
      v2->session->tlsext_ticklen = (unsigned int)a1;
      v12 = v2->session;
      v13 = EVP_sha256();
      EVP_Digest((int)v12->session_id, a1, v10, (unsigned int)a1, v12->session_id, &v12->session_id_length, v13, 0);
      return 1;
    }
    else
    {
      ERR_put_error((int)a1, 0x14u, 283, 65, ".\\ssl\\s3_clnt.c", 1863);
      return -1;
    }
  }
  return result;
}
