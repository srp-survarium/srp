int __cdecl ssl3_send_client_key_exchange(ssl_st *s)
{
  bool v1; // zf
  unsigned int algorithm_mkey; // eax
  unsigned __int8 *v3; // edi
  sess_cert_st *v4; // eax
  rsa_st *peer_rsa_tmp; // ebx
  evp_pkey_st *v6; // eax
  unsigned __int8 client_version; // al
  unsigned __int8 *v8; // ebp
  int v9; // eax
  unsigned int v10; // ebx
  char *v11; // eax
  sess_cert_st *sess_cert; // eax
  dh_st *peer_dh_tmp; // ebx
  dh_st *v15; // eax
  dh_st *v16; // ebp
  int v17; // ebx
  __int64 v18; // rax
  int v19; // ebx
  unsigned __int8 *v20; // edi
  sess_cert_st *v21; // eax
  const env_md_st *peer_ecdh_tmp; // ebx
  evp_pkey_st *pubkey; // eax
  const ec_group_st *v24; // ebp
  const rsa_meth_st *v25; // eax
  const ec_point_st *v26; // ebx
  ec_key_st *v27; // eax
  int degree; // eax
  ecdh_data_st *v29; // ebx
  const ec_point_st *v30; // eax
  int v31; // ebx
  bignum_ctx *v32; // eax
  const ec_point_st *v33; // eax
  unsigned int v34; // ebx
  sess_cert_st *v35; // ecx
  x509_st *x509; // eax
  evp_pkey_ctx_st *v37; // ebp
  cert_pkey_st *key; // ecx
  env_md_ctx_st *v39; // ebx
  const char *v40; // eax
  const env_md_st *digestbyname; // eax
  _BYTE *v42; // edi
  unsigned int v43; // eax
  int v44; // eax
  unsigned int (__cdecl *psk_client_callback)(ssl_st *, const char *, char *, unsigned int, unsigned __int8 *, unsigned int); // eax
  unsigned int v46; // eax
  int v47; // ebp
  unsigned __int8 v48; // cl
  unsigned __int8 *v49; // eax
  ssl_session_st *session; // ecx
  ssl_session_st *v51; // eax
  unsigned int v52; // kr00_4
  evp_pkey_st *v53; // [esp-18h] [ebp-3A0h]
  bignum_ctx *v54; // [esp-4h] [ebp-38Ch]
  bignum_ctx *eckey; // [esp+10h] [ebp-378h]
  bignum_ctx *ctx; // [esp+14h] [ebp-374h]
  unsigned __int8 *src; // [esp+18h] [ebp-370h]
  unsigned int outlen; // [esp+1Ch] [ebp-36Ch] BYREF
  evp_pkey_st *v59; // [esp+20h] [ebp-368h]
  evp_pkey_st *x; // [esp+24h] [ebp-364h]
  unsigned int size; // [esp+28h] [ebp-360h] BYREF
  char *data; // [esp+2Ch] [ebp-35Ch]
  unsigned __int8 from[2]; // [esp+30h] [ebp-358h] BYREF
  unsigned __int8 in[32]; // [esp+60h] [ebp-328h] BYREF
  unsigned __int8 out[256]; // [esp+80h] [ebp-308h] BYREF
  unsigned __int8 v66[2]; // [esp+180h] [ebp-208h] BYREF
  unsigned __int8 v67[514]; // [esp+182h] [ebp-206h] BYREF

  v1 = s->state == 4480;
  eckey = 0;
  x = 0;
  src = 0;
  ctx = 0;
  if ( !v1 )
    return ssl3_do_write(s, 22);
  algorithm_mkey = s->s3->tmp.new_cipher->algorithm_mkey;
  data = s->init_buf->data;
  v3 = (unsigned __int8 *)(data + 4);
  if ( (algorithm_mkey & 1) == 0 )
  {
    if ( (algorithm_mkey & 0xE) != 0 )
    {
      sess_cert = s->session->sess_cert;
      if ( !sess_cert )
      {
        ssl3_send_alert(s, 2, 10);
        ERR_put_error(0x14u, 152, 244, ".\\ssl\\s3_clnt.c", 2223);
        goto err_220;
      }
      peer_dh_tmp = sess_cert->peer_dh_tmp;
      if ( !peer_dh_tmp )
      {
        ssl3_send_alert(s, 2, 40);
        ERR_put_error(0x14u, 152, 238, ".\\ssl\\s3_clnt.c", 2233);
        goto err_220;
      }
      v15 = DHparams_dup(sess_cert->peer_dh_tmp);
      v16 = v15;
      if ( !v15 )
      {
        ERR_put_error(0x14u, 152, 5, ".\\ssl\\s3_clnt.c", 2240);
        goto err_220;
      }
      if ( !DH_generate_key(v15) )
      {
        ERR_put_error(0x14u, 152, 5, ".\\ssl\\s3_clnt.c", 2245);
        DH_free((unsigned int)v3, v16);
        goto err_220;
      }
      v17 = DH_compute_key(v3, peer_dh_tmp->pub_key, v16);
      if ( v17 <= 0 )
      {
        ERR_put_error(0x14u, 152, 5, ".\\ssl\\s3_clnt.c", 2257);
        DH_free((unsigned int)v3, v16);
        goto err_220;
      }
      s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(s, s->session->master_key, v3, v17);
      memset((int)v3, 0, v17);
      v18 = BN_num_bits(v16->pub_key) + 7;
      HIDWORD(v18) = BYTE4(v18) & 7;
      v19 = (HIDWORD(v18) + (int)v18) >> 3;
      *v3 = (HIDWORD(v18) + (int)v18) >> 11;
      v3[1] = v19;
      v20 = v3 + 2;
      BN_bn2bin(v16->pub_key, v20);
      v10 = v19 + 2;
      DH_free((unsigned int)v20, v16);
    }
    else if ( (algorithm_mkey & 0xE0) != 0 )
    {
      v21 = s->session->sess_cert;
      peer_ecdh_tmp = (const env_md_st *)v21->peer_ecdh_tmp;
      if ( !peer_ecdh_tmp )
      {
        pubkey = X509_get_pubkey(v21->peer_pkeys[5].x509);
        x = pubkey;
        if ( !pubkey || pubkey->type != 408 || (peer_ecdh_tmp = (const env_md_st *)pubkey->pkey.ptr) == 0 )
        {
          ERR_put_error(0x14u, 152, 68, ".\\ssl\\s3_clnt.c", 2331);
          goto err_220;
        }
      }
      v24 = (const ec_group_st *)EVP_CIPHER_block_size(peer_ecdh_tmp);
      v25 = EC_KEY_get0_public_key((const engine_st *)peer_ecdh_tmp);
      v26 = (const ec_point_st *)v25;
      if ( !v24 || !v25 )
      {
        ERR_put_error(0x14u, 152, 68, ".\\ssl\\s3_clnt.c", 2344);
        goto err_220;
      }
      v27 = EC_KEY_new();
      eckey = (bignum_ctx *)v27;
      if ( !v27 )
      {
        ERR_put_error(0x14u, 152, 65, ".\\ssl\\s3_clnt.c", 2350);
        goto err_220;
      }
      if ( !EC_KEY_set_group(v27, v24) )
      {
        ERR_put_error(0x14u, 152, 16, ".\\ssl\\s3_clnt.c", 2356);
        goto err_220;
      }
      if ( !EC_KEY_generate_key(eckey) )
      {
        ERR_put_error(0x14u, 152, 43, ".\\ssl\\s3_clnt.c", 2384);
        goto err_220;
      }
      degree = EC_GROUP_get_degree(v24);
      if ( degree <= 0 )
      {
        ERR_put_error(0x14u, 152, 43, ".\\ssl\\s3_clnt.c", 2397);
        goto err_220;
      }
      v29 = ECDH_compute_key(v3, (degree + 7) / 8, v26, (ec_key_st *)eckey, 0);
      if ( (int)v29 <= 0 )
      {
        ERR_put_error(0x14u, 152, 43, ".\\ssl\\s3_clnt.c", 2404);
        goto err_220;
      }
      s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(
                                        s,
                                        s->session->master_key,
                                        v3,
                                        (int)v29);
      memset((int)v3, 0, (unsigned int)v29);
      v30 = (const ec_point_st *)EC_KEY_get0_public_key((const engine_st *)eckey);
      v31 = EC_POINT_point2oct(v24, v30, POINT_CONVERSION_UNCOMPRESSED, 0, 0, 0);
      src = (unsigned __int8 *)CRYPTO_malloc(v31, ".\\ssl\\s3_clnt.c", 2434);
      v32 = BN_CTX_new();
      ctx = v32;
      if ( !src || !v32 )
      {
        ERR_put_error(0x14u, 152, 65, ".\\ssl\\s3_clnt.c", 2439);
        goto err_220;
      }
      v54 = v32;
      v33 = (const ec_point_st *)EC_KEY_get0_public_key((const engine_st *)eckey);
      v34 = EC_POINT_point2oct(v24, v33, POINT_CONVERSION_UNCOMPRESSED, src, v31, v54);
      *v3 = v34;
      memcpy(v3 + 1, src, v34);
      v10 = v34 + 1;
      BN_CTX_free(ctx);
      CRYPTO_free(src);
      EC_KEY_free((ec_key_st *)eckey);
      EVP_PKEY_free(x);
    }
    else if ( (algorithm_mkey & 0x200) != 0 )
    {
      v35 = s->session->sess_cert;
      x509 = v35->peer_pkeys[7].x509;
      if ( !x509 )
      {
        x509 = v35->peer_pkeys[6].x509;
        if ( !x509 )
        {
          ERR_put_error(0x14u, 152, 330, ".\\ssl\\s3_clnt.c", 2483);
          goto err_220;
        }
      }
      v59 = X509_get_pubkey(x509);
      v37 = EVP_PKEY_CTX_new(v59, 0);
      EVP_PKEY_encrypt_init(v37);
      RAND_bytes();
      if ( s->s3->tmp.cert_req )
      {
        key = s->cert->key;
        if ( key->privatekey )
        {
          if ( EVP_PKEY_derive_set_peer(v37, key->privatekey) <= 0 )
            ERR_clear_error();
        }
      }
      v39 = EVP_MD_CTX_create();
      v40 = OBJ_nid2sn(0x329u);
      digestbyname = EVP_get_digestbyname(v40);
      EVP_DigestInit(v39, digestbyname);
      EVP_DigestUpdate(v39);
      EVP_DigestUpdate(v39);
      EVP_DigestFinal_ex((unsigned int)v3, v39, from, &size);
      EVP_MD_CTX_destroy((unsigned int)v3, v39);
      if ( EVP_PKEY_CTX_ctrl(v37, -1, 256, 8, 8, from) < 0 )
      {
        ERR_put_error(0x14u, 152, 274, ".\\ssl\\s3_clnt.c", 2519);
        goto err_220;
      }
      *v3 = 48;
      v42 = v3 + 1;
      outlen = 255;
      if ( EVP_PKEY_encrypt(v37, out, &outlen, in, 0x20u) < 0 )
      {
        ERR_put_error(0x14u, 152, 274, ".\\ssl\\s3_clnt.c", 2528);
        goto err_220;
      }
      v43 = outlen;
      if ( outlen < 0x80 )
      {
        v10 = outlen + 2;
      }
      else
      {
        *v42++ = -127;
        v10 = v43 + 3;
      }
      *v42 = v43;
      memcpy(v42 + 1, out, v43);
      if ( EVP_PKEY_CTX_ctrl(v37, -1, -1, 2, 2, 0) > 0 )
        s->s3->flags |= 0x10u;
      EVP_PKEY_CTX_free(v37);
      v44 = s->method->ssl3_enc->generate_master_secret(s, s->session->master_key, in, 32);
      v53 = v59;
      s->session->master_key_length = v44;
      EVP_PKEY_free(v53);
    }
    else
    {
      if ( (algorithm_mkey & 0x100) == 0 )
      {
        ssl3_send_alert(s, 2, 40);
        ERR_put_error(0x14u, 152, 68, ".\\ssl\\s3_clnt.c", 2643);
        goto err_220;
      }
      psk_client_callback = s->psk_client_callback;
      v10 = 0;
      v59 = (evp_pkey_st *)1;
      if ( !psk_client_callback )
      {
        ERR_put_error(0x14u, 152, 224, ".\\ssl\\s3_clnt.c", 2569);
        goto err_220;
      }
      v46 = psk_client_callback(s, s->ctx->psk_identity_hint, (char *)out, 128u, v66, 516u);
      outlen = v46;
      if ( v46 <= 0x100 )
      {
        if ( v46 )
        {
          v47 = 2 * v46 + 4;
          memmove(&v67[v46 + 2], v66, v46);
          size = outlen >> 8;
          v66[0] = BYTE1(outlen);
          v66[1] = outlen;
          memset((int)v67, 0, outlen);
          v48 = outlen;
          v49 = &v67[outlen];
          *v49 = BYTE1(outlen);
          v49[1] = v48;
          if ( s->session->psk_identity_hint )
            CRYPTO_free(s->session->psk_identity_hint);
          s->session->psk_identity_hint = BUF_strdup(s->ctx->psk_identity_hint);
          if ( !s->ctx->psk_identity_hint || s->session->psk_identity_hint )
          {
            session = s->session;
            if ( session->psk_identity )
              CRYPTO_free(session->psk_identity);
            s->session->psk_identity = BUF_strdup((const char *)out);
            v51 = s->session;
            if ( v51->psk_identity )
            {
              s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(s, v51->master_key, v66, v47);
              v52 = strlen((const char *)out);
              *v3 = BYTE1(v52);
              v3[1] = v52;
              memcpy(v3 + 2, out, v52);
              v10 = v52 + 2;
              v59 = 0;
            }
            else
            {
              ERR_put_error(0x14u, 152, 65, ".\\ssl\\s3_clnt.c", 2615);
            }
          }
          else
          {
            ERR_put_error(0x14u, 152, 65, ".\\ssl\\s3_clnt.c", 2605);
          }
        }
        else
        {
          ERR_put_error(0x14u, 152, 223, ".\\ssl\\s3_clnt.c", 2585);
        }
      }
      else
      {
        ERR_put_error(0x14u, 152, 68, ".\\ssl\\s3_clnt.c", 2579);
      }
      OPENSSL_cleanse(out, 128);
      OPENSSL_cleanse(v66, 516);
      if ( v59 )
      {
        ssl3_send_alert(s, 2, 40);
        goto err_220;
      }
    }
LABEL_21:
    v11 = data;
    *data = 16;
    (++v11)[2] = v10;
    *v11 = BYTE2(v10);
    v11[1] = BYTE1(v10);
    s->state = 4481;
    s->init_num = v10 + 4;
    s->init_off = 0;
    return ssl3_do_write(s, 22);
  }
  v4 = s->session->sess_cert;
  if ( v4->peer_rsa_tmp )
  {
    peer_rsa_tmp = v4->peer_rsa_tmp;
  }
  else
  {
    v6 = X509_get_pubkey(v4->peer_pkeys[0].x509);
    if ( !v6 || v6->type != 6 || !v6->pkey.ptr )
    {
      ERR_put_error(0x14u, 152, 68, ".\\ssl\\s3_clnt.c", 2037);
      goto err_220;
    }
    peer_rsa_tmp = v6->pkey.rsa;
    EVP_PKEY_free(v6);
  }
  client_version = s->client_version;
  from[0] = BYTE1(s->client_version);
  from[1] = client_version;
  if ( RAND_bytes() > 0 )
  {
    s->session->master_key_length = 48;
    v8 = v3;
    if ( s->version > 768 )
      v3 += 2;
    v9 = RSA_public_encrypt(48, from, v3, peer_rsa_tmp);
    v10 = v9;
    if ( (s->options & 0x8000000) != 0 )
      ++v3[1];
    if ( (s->options & 0x10000000) != 0 )
      from[0] = 112;
    if ( v9 <= 0 )
    {
      ERR_put_error(0x14u, 152, 119, ".\\ssl\\s3_clnt.c", 2063);
      goto err_220;
    }
    if ( s->version > 768 )
    {
      v8[1] = v9;
      *v8 = BYTE1(v9);
      v10 = v9 + 2;
    }
    s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(s, s->session->master_key, from, 48);
    OPENSSL_cleanse(from, 48);
    goto LABEL_21;
  }
err_220:
  BN_CTX_free(ctx);
  if ( src )
    CRYPTO_free(src);
  if ( eckey )
    EC_KEY_free((ec_key_st *)eckey);
  EVP_PKEY_free(x);
  return -1;
}
