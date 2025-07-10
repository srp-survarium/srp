int __cdecl ssl3_get_cert_verify(ssl_st *s)
{
  ssl_st *v1; // ebx
  int result; // eax
  ssl_session_st *session; // eax
  x509_st *peer; // esi
  evp_pkey_st *pubkey; // ebp
  int v6; // eax
  ssl3_state_st *s3; // ecx
  int v8; // esi
  unsigned __int8 *init_msg; // edi
  int v10; // esi
  int v11; // eax
  int type; // eax
  int v13; // eax
  evp_pkey_ctx_st *v14; // ebx
  _iobuf *v15; // eax
  int v16; // eax
  char *v17; // ecx
  int v18; // esi
  int v19; // [esp+8h] [ebp-58h]
  int v20; // [esp+Ch] [ebp-54h]
  int v21; // [esp+18h] [ebp-48h] BYREF
  char v22; // [esp+5Bh] [ebp-5h] BYREF

  v1 = s;
  v20 = 0;
  result = s->method->ssl_get_message(s, 8608, 8609, -1, 514, &v21);
  v19 = result;
  if ( v21 )
  {
    session = s->session;
    peer = session->peer;
    if ( peer )
    {
      pubkey = X509_get_pubkey(session->peer);
      v6 = X509_certificate_type(peer, pubkey);
    }
    else
    {
      v6 = 0;
      peer = 0;
      pubkey = 0;
    }
    s3 = s->s3;
    if ( s3->tmp.message_type != 15 )
    {
      s3->tmp.reuse_message = 1;
      if ( peer && v6 | 0x10 )
      {
        v8 = 10;
        ERR_put_error(0x14u, 136, 174, ".\\ssl\\s3_srvr.c", 2735);
LABEL_49:
        ssl3_send_alert(v1, 2, v8);
        goto end_18;
      }
      v20 = 1;
end_18:
      EVP_PKEY_free(pubkey);
      return v20;
    }
    if ( !peer )
    {
      ERR_put_error(0x14u, 136, 186, ".\\ssl\\s3_srvr.c", 2744);
LABEL_12:
      v8 = 10;
      goto LABEL_49;
    }
    if ( (v6 & 0x10) == 0 )
    {
      ERR_put_error(0x14u, 136, 220, ".\\ssl\\s3_srvr.c", 2751);
      v8 = 47;
      goto LABEL_49;
    }
    if ( s3->change_cipher_spec )
    {
      ERR_put_error(0x14u, 136, 133, ".\\ssl\\s3_srvr.c", 2758);
      goto LABEL_12;
    }
    init_msg = (unsigned __int8 *)s->init_msg;
    if ( v19 == 64 && (pubkey->type == 812 || pubkey->type == 811) )
    {
      v10 = 64;
    }
    else
    {
      v10 = init_msg[1] | (*init_msg << 8);
      init_msg += 2;
      v19 -= 2;
      if ( v10 > v19 )
      {
        ERR_put_error(0x14u, 136, 159, ".\\ssl\\s3_srvr.c", 2779);
        goto LABEL_48;
      }
    }
    v11 = EVP_PKEY_size(pubkey);
    if ( v10 <= v11 && v19 <= v11 && v19 > 0 )
    {
      type = pubkey->type;
      if ( pubkey->type == 6 )
      {
        v13 = RSA_verify(0x72u, s->s3->tmp.cert_verify_md, 0x24u, init_msg, v10, pubkey->pkey.rsa);
        if ( v13 < 0 )
        {
          v8 = 51;
          ERR_put_error(0x14u, 136, 118, ".\\ssl\\s3_srvr.c", 2801);
          goto LABEL_49;
        }
        if ( !v13 )
        {
          v8 = 51;
          ERR_put_error(0x14u, 136, 122, ".\\ssl\\s3_srvr.c", 2807);
          goto LABEL_49;
        }
      }
      else
      {
        switch ( type )
        {
          case 116:
            if ( DSA_verify(
                   pubkey->save_type,
                   &s->s3->tmp.cert_verify_md[16],
                   20,
                   init_msg,
                   (unsigned __int8 *)v10,
                   pubkey->pkey.dsa) <= 0 )
            {
              v8 = 51;
              ERR_put_error(0x14u, 136, 112, ".\\ssl\\s3_srvr.c", 2823);
              goto LABEL_49;
            }
            break;
          case 408:
            if ( ECDSA_verify(pubkey->save_type, &s->s3->tmp.cert_verify_md[16], 20, init_msg, v10, pubkey->pkey.ec) <= 0 )
            {
              v8 = 51;
              ERR_put_error(0x14u, 136, 305, ".\\ssl\\s3_srvr.c", 2840);
              goto LABEL_49;
            }
            break;
          case 812:
          case 811:
            v14 = EVP_PKEY_CTX_new(pubkey, 0);
            EVP_PKEY_verify_init(v14);
            if ( v10 != 64 )
            {
              v15 = __iob_func();
              fprintf(v15 + 2, "GOST signature length is %d", v10);
            }
            v16 = 0;
            v17 = &v22;
            do
              *v17-- = init_msg[v16++];
            while ( v16 < 64 );
            v18 = EVP_PKEY_verify(v14);
            EVP_PKEY_CTX_free(v14);
            if ( v18 <= 0 )
            {
              v8 = 51;
              ERR_put_error(0x14u, 136, 305, ".\\ssl\\s3_srvr.c", 2863);
              v1 = s;
              goto LABEL_49;
            }
            break;
          default:
            ERR_put_error(0x14u, 136, 68, ".\\ssl\\s3_srvr.c", 2869);
            v8 = 43;
            goto LABEL_49;
        }
      }
      v20 = 1;
      goto end_18;
    }
    ERR_put_error(0x14u, 136, 265, ".\\ssl\\s3_srvr.c", 2787);
LABEL_48:
    v8 = 50;
    goto LABEL_49;
  }
  return result;
}
