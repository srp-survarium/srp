int __usercall ssl2_set_certificate@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        ssl_st *s,
        int type,
        const unsigned __int8 *len,
        const unsigned __int8 *data)
{
  evp_pkey_st *v6; // ebp
  x509_st *v7; // esi
  stack_st *v8; // eax
  stack_st_X509 *v9; // edi
  int v10; // eax
  sess_cert_st *v11; // edi
  ssl_session_st *session; // ecx
  evp_pkey_st *pubkey; // eax
  int v15; // [esp-4h] [ebp-18h]
  int v16; // [esp+Ch] [ebp-8h]
  stack_st *st; // [esp+10h] [ebp-4h]

  v6 = 0;
  st = 0;
  v16 = 0;
  v7 = d2i_X509(0, (unsigned __int8 **)&data, len);
  if ( v7 )
  {
    v15 = a2;
    v8 = sk_new_null();
    v9 = (stack_st_X509 *)v8;
    st = v8;
    if ( v8 && sk_push(v8, (char *)v7) )
    {
      v10 = ssl_verify_cert_chain(s, v9);
      if ( s->verify_mode && v10 <= 0 )
      {
        ERR_put_error((int)s, 0x14u, 126, 134, ".\\ssl\\s2_clnt.c", 1051);
      }
      else
      {
        ERR_clear_error((int)s);
        s->session->verify_result = s->verify_result;
        v11 = ssl_sess_cert_new();
        if ( v11 )
        {
          session = s->session;
          if ( session->sess_cert )
            ssl_sess_cert_free(session->sess_cert);
          s->session->sess_cert = v11;
          v11->peer_pkeys[0].x509 = v7;
          v11->peer_key = v11->peer_pkeys;
          pubkey = X509_get_pubkey(v7);
          v6 = pubkey;
          v7 = 0;
          if ( pubkey )
          {
            if ( pubkey->type == 6 )
            {
              if ( ssl_set_peer_cert_type(v11, 1) )
                v16 = 1;
            }
            else
            {
              ERR_put_error((int)s, 0x14u, 126, 210, ".\\ssl\\s2_clnt.c", 1079);
            }
          }
          else
          {
            ERR_put_error((int)s, 0x14u, 126, 237, ".\\ssl\\s2_clnt.c", 1074);
          }
        }
        else
        {
          v16 = -1;
        }
      }
    }
    else
    {
      ERR_put_error(a1, 0x14u, 126, 65, ".\\ssl\\s2_clnt.c", 1043);
    }
    a2 = v15;
  }
  else
  {
    ERR_put_error(a1, 0x14u, 126, 11, ".\\ssl\\s2_clnt.c", 1037);
  }
  sk_free(st);
  X509_free(v7);
  EVP_PKEY_free(a2, v6);
  return v16;
}
