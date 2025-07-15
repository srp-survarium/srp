int __usercall ssl3_ctx_ctrl@<eax>(const ec_key_st *a1@<ebx>, ssl_ctx_st *ctx, int cmd, int larg, rsa_st *parg)
{
  cert_st *cert; // edi
  evp_pkey_st *privatekey; // edi
  int result; // eax
  rsa_st *v8; // esi
  dh_st *v9; // eax
  dh_st *v10; // ebx
  bignum_ctx *v11; // eax
  ec_key_st *v12; // ebx
  stack_st_X509 *v13; // eax

  cert = ctx->cert;
  switch ( cmd )
  {
    case 1:
      if ( cert->rsa_tmp )
        goto LABEL_9;
      privatekey = cert->pkeys[0].privatekey;
      if ( !privatekey )
        goto LABEL_47;
      if ( EVP_PKEY_size(privatekey) <= 64 )
        goto LABEL_9;
      return 1;
    case 2:
      if ( !parg || (v8 = RSAPrivateKey_dup((int)a1, parg)) == 0 )
      {
        ERR_put_error((int)a1, 0x14u, 133, 4, ".\\ssl\\s3_lib.c", 2587);
        goto LABEL_9;
      }
      if ( cert->rsa_tmp )
        RSA_free((int)cert, (int)a1, cert->rsa_tmp);
      cert->rsa_tmp = v8;
      return 1;
    case 3:
      v9 = DHparams_dup((int)a1, (dh_st *)parg);
      v10 = v9;
      if ( !v9 )
      {
        ERR_put_error(0, 0x14u, 133, 5, ".\\ssl\\s3_lib.c", 2614);
        goto LABEL_9;
      }
      if ( ((unsigned int)&loc_100000 & ctx->options) != 0 || DH_generate_key(v9) )
      {
        if ( cert->dh_tmp )
          DH_free((int)cert, (int)v10, cert->dh_tmp);
        cert->dh_tmp = v10;
        return 1;
      }
      else
      {
        ERR_put_error((int)v10, 0x14u, 133, 5, ".\\ssl\\s3_lib.c", 2621);
        DH_free((int)cert, (int)v10, v10);
        return 0;
      }
    case 4:
      if ( !parg )
      {
        ERR_put_error((int)a1, 0x14u, 133, 43, ".\\ssl\\s3_lib.c", 2646);
        goto LABEL_9;
      }
      v11 = (bignum_ctx *)EC_KEY_dup(a1, (const ec_key_st *)parg);
      v12 = (ec_key_st *)v11;
      if ( !v11 )
      {
        ERR_put_error(0, 0x14u, 133, 16, ".\\ssl\\s3_lib.c", 2652);
        goto LABEL_9;
      }
      if ( (ctx->options & 0x80000) != 0 || EC_KEY_generate_key(v11) )
      {
        if ( cert->ecdh_tmp )
          EC_KEY_free(cert->ecdh_tmp);
        cert->ecdh_tmp = v12;
        return 1;
      }
      else
      {
        EC_KEY_free(v12);
        ERR_put_error((int)v12, 0x14u, 133, 43, ".\\ssl\\s3_lib.c", 2660);
        return 0;
      }
    case 5:
      ERR_put_error((int)a1, 0x14u, 133, 66, ".\\ssl\\s3_lib.c", 2601);
      goto LABEL_9;
    case 6:
      ERR_put_error((int)a1, 0x14u, 133, 66, ".\\ssl\\s3_lib.c", 2634);
      goto LABEL_9;
    case 7:
      ERR_put_error((int)a1, 0x14u, 133, 66, ".\\ssl\\s3_lib.c", 2675);
      goto LABEL_9;
    case 14:
      if ( !ctx->extra_certs )
      {
        v13 = (stack_st_X509 *)sk_new_null();
        ctx->extra_certs = v13;
        if ( !v13 )
          goto LABEL_9;
      }
      sk_push(&ctx->extra_certs->stack, (char *)parg);
LABEL_47:
      result = 1;
      break;
    case 54:
      ctx->tlsext_servername_arg = parg;
      return 1;
    case 58:
    case 59:
      if ( parg )
      {
        if ( larg == 48 )
        {
          if ( cmd == 59 )
          {
            *(_DWORD *)ctx->tlsext_tick_key_name = parg->pad;
            *(_DWORD *)&ctx->tlsext_tick_key_name[4] = parg->version;
            *(_DWORD *)&ctx->tlsext_tick_key_name[8] = parg->meth;
            *(_DWORD *)&ctx->tlsext_tick_key_name[12] = parg->engine;
            *(_DWORD *)ctx->tlsext_tick_hmac_key = parg->n;
            *(_DWORD *)&ctx->tlsext_tick_hmac_key[4] = parg->e;
            *(_DWORD *)&ctx->tlsext_tick_hmac_key[8] = parg->d;
            *(_DWORD *)&ctx->tlsext_tick_hmac_key[12] = parg->p;
            *(_DWORD *)ctx->tlsext_tick_aes_key = parg->q;
            *(_DWORD *)&ctx->tlsext_tick_aes_key[4] = parg->dmp1;
            *(_DWORD *)&ctx->tlsext_tick_aes_key[8] = parg->dmq1;
            *(_DWORD *)&ctx->tlsext_tick_aes_key[12] = parg->iqmp;
          }
          else
          {
            parg->pad = *(_DWORD *)ctx->tlsext_tick_key_name;
            parg->version = *(_DWORD *)&ctx->tlsext_tick_key_name[4];
            parg->meth = *(const rsa_meth_st **)&ctx->tlsext_tick_key_name[8];
            parg->engine = *(engine_st **)&ctx->tlsext_tick_key_name[12];
            parg->n = *(bignum_st **)ctx->tlsext_tick_hmac_key;
            parg->e = *(bignum_st **)&ctx->tlsext_tick_hmac_key[4];
            parg->d = *(bignum_st **)&ctx->tlsext_tick_hmac_key[8];
            parg->p = *(bignum_st **)&ctx->tlsext_tick_hmac_key[12];
            parg->q = *(bignum_st **)ctx->tlsext_tick_aes_key;
            parg->dmp1 = *(bignum_st **)&ctx->tlsext_tick_aes_key[4];
            parg->dmq1 = *(bignum_st **)&ctx->tlsext_tick_aes_key[8];
            parg->iqmp = *(bignum_st **)&ctx->tlsext_tick_aes_key[12];
          }
          result = 1;
        }
        else
        {
          ERR_put_error((int)a1, 0x14u, 133, 325, ".\\ssl\\s3_lib.c", 2692);
LABEL_9:
          result = 0;
        }
      }
      else
      {
        result = 48;
      }
      break;
    case 64:
      ctx->tlsext_status_arg = parg;
      return 1;
    default:
      goto LABEL_9;
  }
  return result;
}
