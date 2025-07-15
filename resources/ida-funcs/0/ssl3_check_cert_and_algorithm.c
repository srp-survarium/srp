int __cdecl ssl3_check_cert_and_algorithm(ssl_st *s)
{
  const ssl_cipher_st *new_cipher; // eax
  unsigned int algorithm_mkey; // ecx
  int algorithm_auth; // ebx
  ssl_session_st *session; // ecx
  sess_cert_st *sess_cert; // esi
  int peer_cert_type; // edi
  sess_cert_st *v8; // eax
  evp_pkey_st *pubkey; // ebp
  __int16 v10; // si
  const rsa_st *v11; // ecx
  const dh_st *v12; // eax
  const ssl_cipher_st *v13; // ebx
  rsa_st *r; // [esp+4h] [ebp-Ch]
  dh_st *peer_dh_tmp; // [esp+8h] [ebp-8h]
  char v16; // [esp+Ch] [ebp-4h]

  new_cipher = s->s3->tmp.new_cipher;
  algorithm_mkey = new_cipher->algorithm_mkey;
  algorithm_auth = new_cipher->algorithm_auth;
  v16 = algorithm_mkey;
  if ( (algorithm_auth & 0x2C) != 0 || (algorithm_mkey & 0x100) != 0 )
    return 1;
  session = s->session;
  sess_cert = session->sess_cert;
  if ( !sess_cert )
  {
    ERR_put_error(algorithm_auth, 0x14u, 130, 68, ".\\ssl\\s3_clnt.c", 2889);
    return 0;
  }
  peer_cert_type = sess_cert->peer_cert_type;
  v8 = session->sess_cert;
  r = v8->peer_rsa_tmp;
  peer_dh_tmp = v8->peer_dh_tmp;
  if ( peer_cert_type == 5 )
  {
    if ( !ssl_check_srvr_ecc_cert_and_alg(sess_cert->peer_pkeys[5].x509, s->s3->tmp.new_cipher) )
    {
      ERR_put_error(algorithm_auth, 0x14u, 130, 304, ".\\ssl\\s3_clnt.c", 2909);
LABEL_41:
      ssl3_send_alert(s, 2, 40);
      return 0;
    }
  }
  else
  {
    pubkey = X509_get_pubkey(sess_cert->peer_pkeys[peer_cert_type].x509);
    v10 = X509_certificate_type(sess_cert->peer_pkeys[peer_cert_type].x509, pubkey);
    EVP_PKEY_free(peer_cert_type, pubkey);
    if ( (algorithm_auth & 1) != 0 && (v10 & 0x11) != 0x11 )
    {
      ERR_put_error(algorithm_auth, 0x14u, 130, 170, ".\\ssl\\s3_clnt.c", 2926);
      goto LABEL_41;
    }
    if ( (algorithm_auth & 2) != 0 && (v10 & 0x12) != 0x12 )
    {
      ERR_put_error(algorithm_auth, 0x14u, 130, 165, ".\\ssl\\s3_clnt.c", 2932);
      goto LABEL_41;
    }
    if ( (v16 & 1) == 0 || (v10 & 0x21) == 0x21 )
    {
      v11 = r;
    }
    else
    {
      v11 = r;
      if ( !r )
      {
        ERR_put_error(algorithm_auth, 0x14u, 130, 169, ".\\ssl\\s3_clnt.c", 2940);
        goto LABEL_41;
      }
    }
    if ( (v16 & 8) == 0 || (v10 & 0x44) == 0x44 )
    {
      v12 = peer_dh_tmp;
    }
    else
    {
      v12 = peer_dh_tmp;
      if ( !peer_dh_tmp )
      {
        ERR_put_error(algorithm_auth, 0x14u, 130, 163, ".\\ssl\\s3_clnt.c", 2948);
        goto LABEL_41;
      }
    }
    if ( (v16 & 2) != 0 && (v10 & 0x104) != 0x104 )
    {
      ERR_put_error(algorithm_auth, 0x14u, 130, 164, ".\\ssl\\s3_clnt.c", 2953);
      goto LABEL_41;
    }
    if ( (v16 & 4) != 0 && (v10 & 0x204) != 0x204 )
    {
      ERR_put_error(algorithm_auth, 0x14u, 130, 162, ".\\ssl\\s3_clnt.c", 2959);
      goto LABEL_41;
    }
    v13 = s->s3->tmp.new_cipher;
    if ( (v13->algo_strength & 2) != 0 && (v10 & 0x1000) == 0 )
    {
      if ( (v16 & 1) != 0 )
      {
        if ( !v11 || 8 * RSA_size(v11) > ((s->s3->tmp.new_cipher->algo_strength & 8) != 0 ? 512 : 1024) )
        {
          ERR_put_error((int)v13, 0x14u, 130, 167, ".\\ssl\\s3_clnt.c", 2973);
          goto LABEL_41;
        }
      }
      else
      {
        if ( (v16 & 0xE) == 0 )
        {
          ERR_put_error((int)v13, 0x14u, 130, 250, ".\\ssl\\s3_clnt.c", 2992);
          goto LABEL_41;
        }
        if ( !v12 || 8 * DH_size(v12) > ((s->s3->tmp.new_cipher->algo_strength & 8) != 0 ? 512 : 1024) )
        {
          ERR_put_error((int)v13, 0x14u, 130, 166, ".\\ssl\\s3_clnt.c", 2985);
          goto LABEL_41;
        }
      }
    }
  }
  return 1;
}
