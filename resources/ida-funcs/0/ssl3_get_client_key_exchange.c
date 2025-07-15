int __cdecl ssl3_get_client_key_exchange(ssl_st *s)
{
  int (__cdecl *ssl_get_message)(ssl_st *, int, int, int, int, int *); // edx
  int result; // eax
  int v3; // ebp
  ssl3_state_st *s3; // ecx
  const ssl_cipher_st *new_cipher; // eax
  __m128i *init_msg; // edi
  int algorithm_mkey; // ebx
  cert_st *cert; // eax
  rsa_st *rsa_tmp; // eax
  evp_pkey_st *privatekey; // eax
  rsa_st *v11; // ecx
  int v12; // eax
  int client_version; // eax
  int v14; // ecx
  int v15; // eax
  const bignum_st *v16; // eax
  bignum_st *v17; // ebp
  int v18; // ebx
  evp_pkey_st *v19; // eax
  const ec_point_st *v20; // eax
  bignum_ctx *v21; // eax
  unsigned int v22; // ecx
  int degree; // eax
  ecdh_data_st *v24; // ebx
  int v25; // ebx
  unsigned int (__cdecl *psk_server_callback)(ssl_st *, const char *, unsigned __int8 *, unsigned int); // ebp
  unsigned int v27; // ebx
  char *v28; // eax
  ssl_session_st *session; // edx
  ssl_session_st *v30; // edx
  unsigned int algorithm_auth; // eax
  int v32; // ebp
  evp_pkey_st *v33; // edx
  evp_pkey_ctx_st *v34; // ebx
  evp_pkey_st *pubkey; // eax
  unsigned int v36; // ecx
  const unsigned __int8 *v37; // eax
  __int16 v38; // [esp-10h] [ebp-2E8h]
  int v39; // [esp-8h] [ebp-2E0h]
  ec_group_st *group; // [esp+Ch] [ebp-2CCh]
  int groupa; // [esp+Ch] [ebp-2CCh]
  const env_md_st *md; // [esp+10h] [ebp-2C8h] BYREF
  evp_pkey_st *v43; // [esp+14h] [ebp-2C4h]
  ec_key_st *r; // [esp+18h] [ebp-2C0h]
  ec_point_st *dest; // [esp+1Ch] [ebp-2BCh]
  bignum_ctx *ctx; // [esp+20h] [ebp-2B8h]
  evp_pkey_st *x; // [esp+24h] [ebp-2B4h]
  int v48; // [esp+28h] [ebp-2B0h] BYREF
  unsigned __int8 out[32]; // [esp+2Ch] [ebp-2ACh] BYREF
  char dst[132]; // [esp+4Ch] [ebp-28Ch] BYREF
  __m128i src[32]; // [esp+D0h] [ebp-208h] BYREF

  ssl_get_message = s->method->ssl_get_message;
  r = 0;
  x = 0;
  dest = 0;
  ctx = 0;
  result = ssl_get_message(s, 8592, 8593, 16, 2048, &v48);
  v3 = result;
  if ( !v48 )
    return result;
  s3 = s->s3;
  new_cipher = s3->tmp.new_cipher;
  init_msg = (__m128i *)s->init_msg;
  algorithm_mkey = new_cipher->algorithm_mkey;
  if ( (algorithm_mkey & 1) != 0 )
  {
    if ( s3->tmp.use_rsa_tmp )
    {
      cert = s->cert;
      if ( !cert || (rsa_tmp = cert->rsa_tmp) == 0 )
      {
        v39 = 2002;
        v38 = 173;
LABEL_115:
        groupa = 40;
        ERR_put_error(algorithm_mkey, 0x14u, 139, v38, ".\\ssl\\s3_srvr.c", v39);
f_err_7:
        ssl3_send_alert(s, 2, groupa);
        goto err_229;
      }
    }
    else
    {
      privatekey = s->cert->pkeys[0].privatekey;
      if ( !privatekey || privatekey->type != 6 || (rsa_tmp = privatekey->pkey.rsa) == 0 )
      {
        v39 = 2015;
        v38 = 168;
        goto LABEL_115;
      }
    }
    v11 = rsa_tmp;
    if ( s->version > 768 )
    {
      v12 = init_msg->m128i_u8[1] | (init_msg->m128i_u8[0] << 8);
      init_msg = (__m128i *)((char *)init_msg + 2);
      if ( v3 == v12 + 2 )
      {
        v3 = v12;
      }
      else
      {
        if ( (s->options & 0x100) == 0 )
        {
          ERR_put_error(algorithm_mkey, 0x14u, 139, 234, ".\\ssl\\s3_srvr.c", 2029);
          goto err_229;
        }
        init_msg = (__m128i *)((char *)init_msg - 2);
      }
    }
    if ( RSA_private_decrypt(v3, (const unsigned __int8 *)init_msg, (unsigned __int8 *)init_msg, v11) == 48
      && ((client_version = s->client_version, v14 = init_msg->m128i_u8[0], v14 == client_version >> 8)
       && init_msg->m128i_i8[1] == (_BYTE)client_version
       || (s->options & 0x800000) != 0 && v14 == s->version >> 8 && init_msg->m128i_i8[1] == (unsigned __int8)s->version)
      || (ERR_clear_error(algorithm_mkey),
          init_msg->m128i_i8[0] = BYTE1(s->client_version),
          init_msg->m128i_i8[1] = s->client_version,
          RAND_pseudo_bytes((int)init_msg) > 0) )
    {
      s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(
                                        s,
                                        s->session->master_key,
                                        (unsigned __int8 *)init_msg,
                                        48);
      OPENSSL_cleanse(init_msg, 48);
      return 1;
    }
    goto err_229;
  }
  if ( (algorithm_mkey & 0xE) != 0 )
  {
    v15 = init_msg->m128i_u8[1] | (init_msg->m128i_u8[0] << 8);
    init_msg = (__m128i *)((char *)init_msg + 2);
    if ( v3 != v15 + 2 )
    {
      if ( SLOBYTE(s->options) >= 0 )
      {
        ERR_put_error(algorithm_mkey, 0x14u, 139, 148, ".\\ssl\\s3_srvr.c", 2103);
        goto err_229;
      }
      init_msg = (__m128i *)((char *)init_msg - 2);
      v15 = v3;
    }
    if ( v3 )
    {
      algorithm_mkey = (int)s3->tmp.dh;
      if ( algorithm_mkey )
      {
        v16 = BN_bin2bn((const unsigned __int8 *)init_msg, v15, 0);
        v17 = (bignum_st *)v16;
        if ( v16 )
        {
          v18 = DH_compute_key((unsigned __int8 *)init_msg, v16, (dh_st *)algorithm_mkey);
          if ( v18 > 0 )
          {
            DH_free((int)init_msg, v18, s->s3->tmp.dh);
            s->s3->tmp.dh = 0;
            BN_clear_free(v17);
            s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(
                                              s,
                                              s->session->master_key,
                                              (unsigned __int8 *)init_msg,
                                              v18);
            OPENSSL_cleanse(init_msg, v18);
            return 1;
          }
          ERR_put_error(v18, 0x14u, 139, 5, ".\\ssl\\s3_srvr.c", 2142);
          BN_clear_free(v17);
        }
        else
        {
          ERR_put_error(algorithm_mkey, 0x14u, 139, 130, ".\\ssl\\s3_srvr.c", 2134);
        }
        goto err_229;
      }
      v39 = 2124;
      v38 = 171;
    }
    else
    {
      v39 = 2116;
      v38 = 236;
    }
    goto LABEL_115;
  }
  if ( (algorithm_mkey & 0xE0) == 0 )
  {
    if ( (algorithm_mkey & 0x100) != 0 )
    {
      v25 = init_msg->m128i_u8[1] | (init_msg->m128i_u8[0] << 8);
      init_msg = (__m128i *)((char *)init_msg + 2);
      v43 = (evp_pkey_st *)1;
      groupa = 40;
      if ( v3 == v25 + 2 )
      {
        if ( v25 <= 128 )
        {
          psk_server_callback = s->psk_server_callback;
          if ( psk_server_callback )
          {
            memcpy((int)dst, init_msg, v25);
            memset((int)&dst[v25], 0, 129 - v25);
            v27 = psk_server_callback(s, dst, (unsigned __int8 *)src, 516u);
            OPENSSL_cleanse(dst, 129);
            if ( v27 <= 0x100 )
            {
              if ( v27 )
              {
                memmove((int)&src[0].m128i_i32[1] + v27, src, v27);
                md = (const env_md_st *)(v27 >> 8);
                src[0].m128i_i8[0] = BYTE1(v27);
                src[0].m128i_i8[1] = v27;
                memset((int)src[0].m128i_i32 + 2, 0, v27);
                v28 = &src[0].m128i_i8[v27 + 2];
                *v28 = BYTE1(v27);
                v28[1] = v27;
                session = s->session;
                if ( session->psk_identity )
                  CRYPTO_free(session->psk_identity);
                s->session->psk_identity = BUF_strdup(init_msg->m128i_i8);
                v30 = s->session;
                if ( v30->psk_identity )
                {
                  if ( v30->psk_identity_hint )
                    CRYPTO_free(v30->psk_identity_hint);
                  s->session->psk_identity_hint = BUF_strdup(s->ctx->psk_identity_hint);
                  if ( !s->ctx->psk_identity_hint || s->session->psk_identity_hint )
                  {
                    s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(
                                                      s,
                                                      s->session->master_key,
                                                      (unsigned __int8 *)src,
                                                      2 * v27 + 4);
                    v43 = 0;
                  }
                  else
                  {
                    ERR_put_error(v27, 0x14u, 139, 65, ".\\ssl\\s3_srvr.c", 2588);
                  }
                }
                else
                {
                  ERR_put_error(v27, 0x14u, 139, 65, ".\\ssl\\s3_srvr.c", 2577);
                }
              }
              else
              {
                ERR_put_error(0, 0x14u, 139, 223, ".\\ssl\\s3_srvr.c", 2557);
                groupa = 115;
              }
            }
            else
            {
              ERR_put_error(v27, 0x14u, 139, 68, ".\\ssl\\s3_srvr.c", 2550);
            }
          }
          else
          {
            ERR_put_error(v25, 0x14u, 139, 225, ".\\ssl\\s3_srvr.c", 2535);
          }
        }
        else
        {
          ERR_put_error(v25, 0x14u, 139, 146, ".\\ssl\\s3_srvr.c", 2529);
        }
      }
      else
      {
        ERR_put_error(v25, 0x14u, 139, 159, ".\\ssl\\s3_srvr.c", 2523);
      }
      OPENSSL_cleanse(src, 516);
      if ( !v43 )
        return 1;
      goto f_err_7;
    }
    if ( (algorithm_mkey & 0x200) == 0 )
    {
      v39 = 2679;
      v38 = 249;
      goto LABEL_115;
    }
    md = (const env_md_st *)32;
    algorithm_auth = new_cipher->algorithm_auth;
    v32 = 0;
    v33 = 0;
    if ( (algorithm_auth & 0x100) != 0 )
    {
      v33 = s->cert->pkeys[6].privatekey;
    }
    else if ( (algorithm_auth & 0x200) != 0 )
    {
      v33 = s->cert->pkeys[7].privatekey;
    }
    v34 = EVP_PKEY_CTX_new((int)init_msg, v33, 0);
    EVP_PKEY_decrypt_init((int)v34, v34);
    pubkey = X509_get_pubkey(s->session->peer);
    v43 = pubkey;
    if ( pubkey && EVP_PKEY_derive_set_peer((int)v34, v34, pubkey) <= 0 )
      ERR_clear_error((int)v34);
    if ( init_msg->m128i_i8[0] != 48 )
    {
      ERR_put_error((int)v34, 0x14u, 139, 147, ".\\ssl\\s3_srvr.c", 2634);
      goto gerr;
    }
    LOBYTE(v36) = init_msg->m128i_i8[1];
    if ( (_BYTE)v36 == 0x81 )
    {
      v36 = init_msg->m128i_u8[2];
      v37 = &init_msg->m128i_u8[3];
    }
    else
    {
      if ( (unsigned __int8)v36 >= 0x80u )
      {
        ERR_put_error((int)v34, 0x14u, 139, 147, ".\\ssl\\s3_srvr.c", 2649);
        goto gerr;
      }
      v37 = &init_msg->m128i_u8[2];
      v36 = (unsigned __int8)v36;
    }
    if ( EVP_PKEY_decrypt((int)v34, v34, out, (unsigned int *)&md, v37, v36) > 0 )
    {
      s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(s, s->session->master_key, out, 32);
      v32 = (EVP_PKEY_CTX_ctrl((int)v34, v34, -1, -1, 2, 2, 0) > 0) + 1;
    }
    else
    {
      ERR_put_error((int)v34, 0x14u, 139, 147, ".\\ssl\\s3_srvr.c", 2655);
    }
gerr:
    EVP_PKEY_free((int)init_msg, v43);
    EVP_PKEY_CTX_free((int)init_msg, v34);
    if ( v32 )
      return v32;
    goto err_229;
  }
  v43 = (evp_pkey_st *)1;
  r = EC_KEY_new(algorithm_mkey);
  if ( r )
  {
    if ( (algorithm_mkey & 0x60) != 0 )
      md = (const env_md_st *)s->cert->pkeys[5].privatekey->pkey.ptr;
    else
      md = (const env_md_st *)s->s3->tmp.ecdh;
    group = (ec_group_st *)EVP_CIPHER_block_size(md);
    md = (const env_md_st *)EC_KEY_get0_private_key((const ssl_st *)md);
    if ( !EC_KEY_set_group(r, group) || !EC_KEY_set_private_key(algorithm_mkey, r, (const bignum_st *)md) )
    {
      ERR_put_error(algorithm_mkey, 0x14u, 139, 16, ".\\ssl\\s3_srvr.c", 2390);
      goto err_229;
    }
    dest = EC_POINT_new(algorithm_mkey, group);
    if ( dest )
    {
      if ( v3 )
      {
        v21 = BN_CTX_new(algorithm_mkey);
        ctx = v21;
        if ( !v21 )
        {
          ERR_put_error(algorithm_mkey, 0x14u, 139, 65, ".\\ssl\\s3_srvr.c", 2450);
          goto err_229;
        }
        v22 = init_msg->m128i_u8[0];
        if ( v3 != v22 + 1 )
        {
          ERR_put_error(algorithm_mkey, 0x14u, 139, 16, ".\\ssl\\s3_srvr.c", 2460);
          goto err_229;
        }
        init_msg = (__m128i *)((char *)init_msg + 1);
        if ( !EC_POINT_oct2point(algorithm_mkey, group, dest, (const unsigned __int8 *)init_msg, v22, v21) )
        {
          ERR_put_error(algorithm_mkey, 0x14u, 139, 16, ".\\ssl\\s3_srvr.c", 2467);
          goto err_229;
        }
        init_msg = (__m128i *)s->init_buf->data;
      }
      else
      {
        if ( (algorithm_mkey & 0x80u) != 0 )
        {
          v39 = 2409;
          v38 = 311;
          goto LABEL_115;
        }
        v19 = X509_get_pubkey(s->session->peer);
        x = v19;
        if ( !v19 || v19->type != 408 )
        {
          v39 = 2429;
          v38 = 313;
          goto LABEL_115;
        }
        v20 = (const ec_point_st *)EC_KEY_get0_public_key((const engine_st *)v19->pkey.ptr);
        if ( !EC_POINT_copy(algorithm_mkey, dest, v20) )
        {
          ERR_put_error(algorithm_mkey, 0x14u, 139, 16, ".\\ssl\\s3_srvr.c", 2437);
          goto err_229;
        }
        v43 = (evp_pkey_st *)2;
      }
      degree = EC_GROUP_get_degree(algorithm_mkey, group);
      if ( degree > 0 )
      {
        v24 = ECDH_compute_key((int)init_msg, init_msg, (degree + 7) / 8, dest, r, 0);
        if ( (int)v24 > 0 )
        {
          EVP_PKEY_free((int)init_msg, x);
          EC_POINT_free(dest);
          EC_KEY_free(r);
          BN_CTX_free(ctx);
          EC_KEY_free(s->s3->tmp.ecdh);
          s->s3->tmp.ecdh = 0;
          s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(
                                            s,
                                            s->session->master_key,
                                            (unsigned __int8 *)init_msg,
                                            (int)v24);
          OPENSSL_cleanse(init_msg, v24);
          return (int)v43;
        }
        ERR_put_error((int)v24, 0x14u, 139, 43, ".\\ssl\\s3_srvr.c", 2488);
      }
      else
      {
        ERR_put_error(algorithm_mkey, 0x14u, 139, 43, ".\\ssl\\s3_srvr.c", 2481);
      }
      goto err_229;
    }
    ERR_put_error(algorithm_mkey, 0x14u, 139, 65, ".\\ssl\\s3_srvr.c", 2398);
  }
  else
  {
    ERR_put_error(algorithm_mkey, 0x14u, 139, 65, ".\\ssl\\s3_srvr.c", 2365);
  }
err_229:
  EVP_PKEY_free((int)init_msg, x);
  EC_POINT_free(dest);
  if ( r )
    EC_KEY_free(r);
  BN_CTX_free(ctx);
  return -1;
}
