int __cdecl ssl3_get_client_key_exchange(ssl_st *s)
{
  int (__cdecl *ssl_get_message)(ssl_st *, int, int, int, int, int *); // edx
  int result; // eax
  int v3; // ebp
  ssl3_state_st *s3; // ecx
  const ssl_cipher_st *new_cipher; // eax
  unsigned __int8 *init_msg; // edi
  unsigned int algorithm_mkey; // ebx
  cert_st *cert; // eax
  rsa_st *rsa_tmp; // eax
  evp_pkey_st *privatekey; // eax
  rsa_st *v11; // ecx
  int v12; // eax
  int client_version; // eax
  int v14; // ecx
  int v15; // eax
  unsigned __int8 *v16; // edi
  dh_st *dh; // ebx
  const bignum_st *v18; // eax
  bignum_st *v19; // ebp
  int v20; // ebx
  evp_pkey_st *v21; // eax
  const ec_point_st *v22; // eax
  bignum_ctx *v23; // eax
  unsigned int v24; // ecx
  int degree; // eax
  ecdh_data_st *v26; // ebx
  signed int v27; // ebx
  unsigned __int8 *v28; // edi
  unsigned int (__cdecl *psk_server_callback)(ssl_st *, const char *, unsigned __int8 *, unsigned int); // ebp
  unsigned int v30; // ebx
  unsigned __int8 *v31; // eax
  ssl_session_st *session; // edx
  ssl_session_st *v33; // edx
  unsigned int algorithm_auth; // eax
  int v35; // ebp
  evp_pkey_st *v36; // edx
  evp_pkey_ctx_st *v37; // ebx
  evp_pkey_st *pubkey; // eax
  unsigned int v39; // ecx
  const unsigned __int8 *v40; // eax
  __int16 v41; // [esp-10h] [ebp-2E8h]
  int v42; // [esp-8h] [ebp-2E0h]
  ec_group_st *group; // [esp+Ch] [ebp-2CCh]
  int groupa; // [esp+Ch] [ebp-2CCh]
  const env_md_st *md; // [esp+10h] [ebp-2C8h] BYREF
  evp_pkey_st *v46; // [esp+14h] [ebp-2C4h]
  ec_key_st *key; // [esp+18h] [ebp-2C0h]
  ec_point_st *dest; // [esp+1Ch] [ebp-2BCh]
  bignum_ctx *ctx; // [esp+20h] [ebp-2B8h]
  evp_pkey_st *x; // [esp+24h] [ebp-2B4h]
  int v51; // [esp+28h] [ebp-2B0h] BYREF
  unsigned __int8 out[32]; // [esp+2Ch] [ebp-2ACh] BYREF
  char dst[132]; // [esp+4Ch] [ebp-28Ch] BYREF
  unsigned __int8 src[2]; // [esp+D0h] [ebp-208h] BYREF
  unsigned __int8 v55[514]; // [esp+D2h] [ebp-206h] BYREF

  ssl_get_message = s->method->ssl_get_message;
  key = 0;
  x = 0;
  dest = 0;
  ctx = 0;
  result = ssl_get_message(s, 8592, 8593, 16, 2048, &v51);
  v3 = result;
  if ( !v51 )
    return result;
  s3 = s->s3;
  new_cipher = s3->tmp.new_cipher;
  init_msg = (unsigned __int8 *)s->init_msg;
  algorithm_mkey = new_cipher->algorithm_mkey;
  if ( (algorithm_mkey & 1) != 0 )
  {
    if ( s3->tmp.use_rsa_tmp )
    {
      cert = s->cert;
      if ( !cert || (rsa_tmp = cert->rsa_tmp) == 0 )
      {
        v42 = 2002;
        v41 = 173;
LABEL_115:
        groupa = 40;
        ERR_put_error(0x14u, 139, v41, ".\\ssl\\s3_srvr.c", v42);
f_err_7:
        ssl3_send_alert(s, 2, groupa);
        goto err_227;
      }
    }
    else
    {
      privatekey = s->cert->pkeys[0].privatekey;
      if ( !privatekey || privatekey->type != 6 || (rsa_tmp = privatekey->pkey.rsa) == 0 )
      {
        v42 = 2015;
        v41 = 168;
        goto LABEL_115;
      }
    }
    v11 = rsa_tmp;
    if ( s->version > 768 )
    {
      v12 = init_msg[1] | (*init_msg << 8);
      init_msg += 2;
      if ( v3 == v12 + 2 )
      {
        v3 = v12;
      }
      else
      {
        if ( (s->options & 0x100) == 0 )
        {
          ERR_put_error(0x14u, 139, 234, ".\\ssl\\s3_srvr.c", 2029);
          goto err_227;
        }
        init_msg -= 2;
      }
    }
    if ( RSA_private_decrypt(v3, init_msg, init_msg, v11) == 48
      && ((client_version = s->client_version, v14 = *init_msg, v14 == client_version >> 8)
       && init_msg[1] == (_BYTE)client_version
       || ((unsigned int)&unk_800000 & s->options) != 0
       && v14 == s->version >> 8
       && init_msg[1] == (unsigned __int8)s->version)
      || (ERR_clear_error(),
          *init_msg = BYTE1(s->client_version),
          init_msg[1] = s->client_version,
          RAND_pseudo_bytes() > 0) )
    {
      s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(
                                        s,
                                        s->session->master_key,
                                        init_msg,
                                        48);
      OPENSSL_cleanse(init_msg, 48);
      return 1;
    }
    goto err_227;
  }
  if ( (algorithm_mkey & 0xE) != 0 )
  {
    v15 = init_msg[1] | (*init_msg << 8);
    v16 = init_msg + 2;
    if ( v3 != v15 + 2 )
    {
      if ( SLOBYTE(s->options) >= 0 )
      {
        ERR_put_error(0x14u, 139, 148, ".\\ssl\\s3_srvr.c", 2103);
        goto err_227;
      }
      v16 -= 2;
      v15 = v3;
    }
    if ( v3 )
    {
      dh = s3->tmp.dh;
      if ( dh )
      {
        v18 = BN_bin2bn(v16, v15, 0);
        v19 = (bignum_st *)v18;
        if ( v18 )
        {
          v20 = DH_compute_key(v16, v18, dh);
          if ( v20 > 0 )
          {
            DH_free((unsigned int)v16, s->s3->tmp.dh);
            s->s3->tmp.dh = 0;
            BN_clear_free(v19);
            s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(
                                              s,
                                              s->session->master_key,
                                              v16,
                                              v20);
            OPENSSL_cleanse(v16, v20);
            return 1;
          }
          ERR_put_error(0x14u, 139, 5, ".\\ssl\\s3_srvr.c", 2142);
          BN_clear_free(v19);
        }
        else
        {
          ERR_put_error(0x14u, 139, 130, ".\\ssl\\s3_srvr.c", 2134);
        }
        goto err_227;
      }
      v42 = 2124;
      v41 = 171;
    }
    else
    {
      v42 = 2116;
      v41 = 236;
    }
    goto LABEL_115;
  }
  if ( (algorithm_mkey & 0xE0) == 0 )
  {
    if ( (algorithm_mkey & 0x100) != 0 )
    {
      v27 = init_msg[1] | (*init_msg << 8);
      v28 = init_msg + 2;
      v46 = (evp_pkey_st *)1;
      groupa = 40;
      if ( v3 == v27 + 2 )
      {
        if ( v27 <= 128 )
        {
          psk_server_callback = s->psk_server_callback;
          if ( psk_server_callback )
          {
            memcpy((unsigned __int8 *)dst, v28, v27);
            memset((int)&dst[v27], 0, 129 - v27);
            v30 = psk_server_callback(s, dst, src, 516u);
            OPENSSL_cleanse(dst, 129);
            if ( v30 <= 0x100 )
            {
              if ( v30 )
              {
                memmove(&v55[v30 + 2], src, v30);
                md = (const env_md_st *)(v30 >> 8);
                src[0] = BYTE1(v30);
                src[1] = v30;
                memset((int)v55, 0, v30);
                v31 = &v55[v30];
                *v31 = BYTE1(v30);
                v31[1] = v30;
                session = s->session;
                if ( session->psk_identity )
                  CRYPTO_free(session->psk_identity);
                s->session->psk_identity = BUF_strdup((const char *)v28);
                v33 = s->session;
                if ( v33->psk_identity )
                {
                  if ( v33->psk_identity_hint )
                    CRYPTO_free(v33->psk_identity_hint);
                  s->session->psk_identity_hint = BUF_strdup(s->ctx->psk_identity_hint);
                  if ( !s->ctx->psk_identity_hint || s->session->psk_identity_hint )
                  {
                    s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(
                                                      s,
                                                      s->session->master_key,
                                                      src,
                                                      2 * v30 + 4);
                    v46 = 0;
                  }
                  else
                  {
                    ERR_put_error(0x14u, 139, 65, ".\\ssl\\s3_srvr.c", 2588);
                  }
                }
                else
                {
                  ERR_put_error(0x14u, 139, 65, ".\\ssl\\s3_srvr.c", 2577);
                }
              }
              else
              {
                ERR_put_error(0x14u, 139, 223, ".\\ssl\\s3_srvr.c", 2557);
                groupa = 115;
              }
            }
            else
            {
              ERR_put_error(0x14u, 139, 68, ".\\ssl\\s3_srvr.c", 2550);
            }
          }
          else
          {
            ERR_put_error(0x14u, 139, 225, ".\\ssl\\s3_srvr.c", 2535);
          }
        }
        else
        {
          ERR_put_error(0x14u, 139, 146, ".\\ssl\\s3_srvr.c", 2529);
        }
      }
      else
      {
        ERR_put_error(0x14u, 139, 159, ".\\ssl\\s3_srvr.c", 2523);
      }
      OPENSSL_cleanse(src, 516);
      if ( !v46 )
        return 1;
      goto f_err_7;
    }
    if ( (algorithm_mkey & 0x200) == 0 )
    {
      v42 = 2679;
      v41 = 249;
      goto LABEL_115;
    }
    md = (const env_md_st *)32;
    algorithm_auth = new_cipher->algorithm_auth;
    v35 = 0;
    v36 = 0;
    if ( (algorithm_auth & 0x100) != 0 )
    {
      v36 = s->cert->pkeys[6].privatekey;
    }
    else if ( (algorithm_auth & 0x200) != 0 )
    {
      v36 = s->cert->pkeys[7].privatekey;
    }
    v37 = EVP_PKEY_CTX_new(v36, 0);
    EVP_PKEY_decrypt_init(v37);
    pubkey = X509_get_pubkey(s->session->peer);
    v46 = pubkey;
    if ( pubkey && EVP_PKEY_derive_set_peer(v37, pubkey) <= 0 )
      ERR_clear_error();
    if ( *init_msg != 48 )
    {
      ERR_put_error(0x14u, 139, 147, ".\\ssl\\s3_srvr.c", 2634);
      goto gerr;
    }
    LOBYTE(v39) = init_msg[1];
    if ( (_BYTE)v39 == 0x81 )
    {
      v39 = init_msg[2];
      v40 = init_msg + 3;
    }
    else
    {
      if ( (unsigned __int8)v39 >= 0x80u )
      {
        ERR_put_error(0x14u, 139, 147, ".\\ssl\\s3_srvr.c", 2649);
        goto gerr;
      }
      v40 = init_msg + 2;
      v39 = (unsigned __int8)v39;
    }
    if ( EVP_PKEY_decrypt(v37, out, (unsigned int *)&md, v40, v39) > 0 )
    {
      s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(s, s->session->master_key, out, 32);
      v35 = (EVP_PKEY_CTX_ctrl(v37, -1, -1, 2, 2, 0) > 0) + 1;
    }
    else
    {
      ERR_put_error(0x14u, 139, 147, ".\\ssl\\s3_srvr.c", 2655);
    }
gerr:
    EVP_PKEY_free(v46);
    EVP_PKEY_CTX_free(v37);
    if ( v35 )
      return v35;
    goto err_227;
  }
  v46 = (evp_pkey_st *)1;
  key = EC_KEY_new();
  if ( key )
  {
    if ( (algorithm_mkey & 0x60) != 0 )
      md = (const env_md_st *)s->cert->pkeys[5].privatekey->pkey.ptr;
    else
      md = (const env_md_st *)s->s3->tmp.ecdh;
    group = (ec_group_st *)EVP_CIPHER_block_size(md);
    md = (const env_md_st *)EC_KEY_get0_private_key((const ssl_st *)md);
    if ( !EC_KEY_set_group(key, group) || !EC_KEY_set_private_key(key, (const bignum_st *)md) )
    {
      ERR_put_error(0x14u, 139, 16, ".\\ssl\\s3_srvr.c", 2390);
      goto err_227;
    }
    dest = EC_POINT_new(group);
    if ( dest )
    {
      if ( v3 )
      {
        v23 = BN_CTX_new();
        ctx = v23;
        if ( !v23 )
        {
          ERR_put_error(0x14u, 139, 65, ".\\ssl\\s3_srvr.c", 2450);
          goto err_227;
        }
        v24 = *init_msg;
        if ( v3 != v24 + 1 )
        {
          ERR_put_error(0x14u, 139, 16, ".\\ssl\\s3_srvr.c", 2460);
          goto err_227;
        }
        if ( !EC_POINT_oct2point(group, dest, init_msg + 1, v24, v23) )
        {
          ERR_put_error(0x14u, 139, 16, ".\\ssl\\s3_srvr.c", 2467);
          goto err_227;
        }
        init_msg = (unsigned __int8 *)s->init_buf->data;
      }
      else
      {
        if ( (algorithm_mkey & 0x80u) != 0 )
        {
          v42 = 2409;
          v41 = 311;
          goto LABEL_115;
        }
        v21 = X509_get_pubkey(s->session->peer);
        x = v21;
        if ( !v21 || v21->type != 408 )
        {
          v42 = 2429;
          v41 = 313;
          goto LABEL_115;
        }
        v22 = (const ec_point_st *)EC_KEY_get0_public_key((const engine_st *)v21->pkey.ptr);
        if ( !EC_POINT_copy(dest, v22) )
        {
          ERR_put_error(0x14u, 139, 16, ".\\ssl\\s3_srvr.c", 2437);
          goto err_227;
        }
        v46 = (evp_pkey_st *)2;
      }
      degree = EC_GROUP_get_degree(group);
      if ( degree > 0 )
      {
        v26 = ECDH_compute_key(init_msg, (degree + 7) / 8, dest, key, 0);
        if ( (int)v26 > 0 )
        {
          EVP_PKEY_free(x);
          EC_POINT_free(dest);
          EC_KEY_free(key);
          BN_CTX_free(ctx);
          EC_KEY_free(s->s3->tmp.ecdh);
          s->s3->tmp.ecdh = 0;
          s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(
                                            s,
                                            s->session->master_key,
                                            init_msg,
                                            (int)v26);
          OPENSSL_cleanse(init_msg, v26);
          return (int)v46;
        }
        ERR_put_error(0x14u, 139, 43, ".\\ssl\\s3_srvr.c", 2488);
      }
      else
      {
        ERR_put_error(0x14u, 139, 43, ".\\ssl\\s3_srvr.c", 2481);
      }
      goto err_227;
    }
    ERR_put_error(0x14u, 139, 65, ".\\ssl\\s3_srvr.c", 2398);
  }
  else
  {
    ERR_put_error(0x14u, 139, 65, ".\\ssl\\s3_srvr.c", 2365);
  }
err_227:
  EVP_PKEY_free(x);
  EC_POINT_free(dest);
  if ( key )
    EC_KEY_free(key);
  BN_CTX_free(ctx);
  return -1;
}
