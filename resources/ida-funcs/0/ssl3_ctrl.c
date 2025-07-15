int __usercall ssl3_ctrl@<eax>(int a1@<ebx>, ssl_st *s, int cmd, int larg, rsa_st *parg)
{
  int v5; // edi
  int result; // eax
  ssl3_state_st *s3; // esi
  cert_st *cert; // esi
  evp_pkey_st *privatekey; // esi
  rsa_st *v10; // edi
  cert_st *v11; // edx
  dh_st *v12; // eax
  dh_st *v13; // edi
  cert_st *v14; // ecx
  char *v15; // eax

  v5 = 0;
  if ( (cmd == 2 || cmd == 5 || cmd == 3 || cmd == 6) && !ssl_cert_inst(a1, &s->cert) )
  {
    ERR_put_error(a1, 0x14u, 213, 65, ".\\ssl\\s3_lib.c", 2262);
    return 0;
  }
  else
  {
    switch ( cmd )
    {
      case 1:
        cert = s->cert;
        if ( !cert || cert->rsa_tmp )
          goto LABEL_69;
        privatekey = cert->pkeys[0].privatekey;
        if ( !privatekey )
        {
LABEL_68:
          v5 = 1;
          goto LABEL_69;
        }
        if ( EVP_PKEY_size(privatekey) <= 64 )
          goto LABEL_69;
        return 1;
      case 2:
        if ( !parg )
        {
          ERR_put_error(a1, 0x14u, 213, 67, ".\\ssl\\s3_lib.c", 2300);
          return 0;
        }
        v10 = RSAPrivateKey_dup(a1, parg);
        if ( !v10 )
        {
          ERR_put_error(a1, 0x14u, 213, 4, ".\\ssl\\s3_lib.c", 2305);
          return 0;
        }
        v11 = s->cert;
        if ( v11->rsa_tmp )
          RSA_free((int)v10, a1, v11->rsa_tmp);
        s->cert->rsa_tmp = v10;
        return 1;
      case 3:
        if ( !parg )
        {
          ERR_put_error(a1, 0x14u, 213, 67, ".\\ssl\\s3_lib.c", 2327);
          return 0;
        }
        v12 = DHparams_dup(a1, (dh_st *)parg);
        v13 = v12;
        if ( !v12 )
        {
          ERR_put_error(a1, 0x14u, 213, 5, ".\\ssl\\s3_lib.c", 2332);
          return 0;
        }
        if ( ((unsigned int)&loc_100000 & s->options) != 0 || DH_generate_key(v12) )
        {
          v14 = s->cert;
          if ( v14->dh_tmp )
            DH_free((int)v13, a1, v14->dh_tmp);
          s->cert->dh_tmp = v13;
          return 1;
        }
        else
        {
          DH_free((int)v13, a1, v13);
          ERR_put_error(a1, 0x14u, 213, 5, ".\\ssl\\s3_lib.c", 2340);
          return 0;
        }
      case 4:
        if ( !parg )
        {
          ERR_put_error(a1, 0x14u, 213, 67, ".\\ssl\\s3_lib.c", 2364);
          return 0;
        }
        if ( !EC_KEY_up_ref((ec_key_st *)parg) )
        {
          ERR_put_error(a1, 0x14u, 213, 43, ".\\ssl\\s3_lib.c", 2369);
          return 0;
        }
        if ( (s->options & 0x80000) != 0 || EC_KEY_generate_key((bignum_ctx *)parg) )
        {
          if ( s->cert->ecdh_tmp )
            EC_KEY_free(s->cert->ecdh_tmp);
          s->cert->ecdh_tmp = (ec_key_st *)parg;
          return 1;
        }
        else
        {
          EC_KEY_free((ec_key_st *)parg);
          ERR_put_error(a1, 0x14u, 213, 43, ".\\ssl\\s3_lib.c", 2378);
          return 0;
        }
      case 5:
        ERR_put_error(a1, 0x14u, 213, 66, ".\\ssl\\s3_lib.c", 2316);
        return 0;
      case 6:
        ERR_put_error(a1, 0x14u, 213, 66, ".\\ssl\\s3_lib.c", 2352);
        return 0;
      case 7:
        ERR_put_error(a1, 0x14u, 213, 66, ".\\ssl\\s3_lib.c", 2390);
        return 0;
      case 8:
        return s->hit;
      case 10:
        return s->s3->num_renegotiations;
      case 11:
        s3 = s->s3;
        result = s3->num_renegotiations;
        s3->num_renegotiations = 0;
        return result;
      case 12:
        return s->s3->total_renegotiations;
      case 13:
        return s->s3->flags;
      case 55:
        if ( larg )
        {
          ERR_put_error(a1, 0x14u, 213, 320, ".\\ssl\\s3_lib.c", 2419);
          return 0;
        }
        if ( s->tlsext_hostname )
          CRYPTO_free(s->tlsext_hostname);
        s->tlsext_hostname = 0;
        v5 = 1;
        if ( parg )
        {
          if ( strlen((const char *)parg) > 0xFF )
          {
            ERR_put_error(a1, 0x14u, 213, 319, ".\\ssl\\s3_lib.c", 2408);
            return 0;
          }
          v15 = BUF_strdup((char *)parg);
          s->tlsext_hostname = v15;
          if ( !v15 )
          {
            ERR_put_error(a1, 0x14u, 213, 68, ".\\ssl\\s3_lib.c", 2413);
            return 0;
          }
        }
LABEL_69:
        result = v5;
        break;
      case 57:
        result = 1;
        s->tlsext_debug_arg = parg;
        return result;
      case 65:
        s->tlsext_status_type = larg;
        return 1;
      case 66:
        result = 1;
        parg->pad = (int)s->tlsext_ocsp_exts;
        return result;
      case 67:
        s->tlsext_ocsp_exts = (stack_st_X509_EXTENSION *)parg;
        return 1;
      case 68:
        result = 1;
        parg->pad = (int)s->tlsext_ocsp_ids;
        return result;
      case 69:
        s->tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)parg;
        return 1;
      case 70:
        parg->pad = (int)s->tlsext_ocsp_resp;
        return s->tlsext_ocsp_resplen;
      case 71:
        if ( s->tlsext_ocsp_resp )
          CRYPTO_free(s->tlsext_ocsp_resp);
        s->tlsext_ocsp_resp = (unsigned __int8 *)parg;
        s->tlsext_ocsp_resplen = larg;
        goto LABEL_68;
      default:
        goto LABEL_69;
    }
  }
  return result;
}
