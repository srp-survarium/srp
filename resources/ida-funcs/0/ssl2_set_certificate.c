int __cdecl ssl2_set_certificate(ssl_st *s, int type, int len, unsigned __int8 *data)
{
  evp_pkey_st *v4; // ebp
  x509_st *v5; // esi
  stack_st *v6; // eax
  stack_st_X509 *v7; // edi
  int v8; // eax
  sess_cert_st *v9; // edi
  ssl_session_st *session; // ecx
  evp_pkey_st *pubkey; // eax
  int v13; // [esp+Ch] [ebp-8h]
  stack_st *st; // [esp+10h] [ebp-4h]

  v4 = 0;
  st = 0;
  v13 = 0;
  v5 = d2i_X509(0, (const unsigned __int8 **)&data, len);
  if ( v5 )
  {
    v6 = sk_new_null();
    v7 = (stack_st_X509 *)v6;
    st = v6;
    if ( v6 && sk_push(v6, (char *)v5) )
    {
      v8 = ssl_verify_cert_chain(s, v7);
      if ( s->verify_mode && v8 <= 0 )
      {
        ERR_put_error(0x14u, 126, 134, ".\\ssl\\s2_clnt.c", 1051);
      }
      else
      {
        ERR_clear_error();
        s->session->verify_result = s->verify_result;
        v9 = ssl_sess_cert_new();
        if ( v9 )
        {
          session = s->session;
          if ( session->sess_cert )
            ssl_sess_cert_free(session->sess_cert);
          s->session->sess_cert = v9;
          v9->peer_pkeys[0].x509 = v5;
          v9->peer_key = v9->peer_pkeys;
          pubkey = X509_get_pubkey(v5);
          v4 = pubkey;
          v5 = 0;
          if ( pubkey )
          {
            if ( pubkey->type == 6 )
            {
              if ( ssl_set_peer_cert_type(v9, 1) )
                v13 = 1;
            }
            else
            {
              ERR_put_error(0x14u, 126, 210, ".\\ssl\\s2_clnt.c", 1079);
            }
          }
          else
          {
            ERR_put_error(0x14u, 126, 237, ".\\ssl\\s2_clnt.c", 1074);
          }
        }
        else
        {
          v13 = -1;
        }
      }
    }
    else
    {
      ERR_put_error(0x14u, 126, 65, ".\\ssl\\s2_clnt.c", 1043);
    }
  }
  else
  {
    ERR_put_error(0x14u, 126, 11, ".\\ssl\\s2_clnt.c", 1037);
  }
  sk_free(st);
  X509_free(v5);
  EVP_PKEY_free(v4);
  return v13;
}
