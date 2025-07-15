int __usercall ssl3_send_client_key_exchange@<eax>(int a1@<ebx>, ssl_st *s)
{
  bool v2; // zf
  unsigned int algorithm_mkey; // eax
  unsigned __int8 *v4; // edi
  sess_cert_st *v5; // eax
  rsa_st *peer_rsa_tmp; // ebx
  evp_pkey_st *v7; // eax
  unsigned __int8 client_version; // al
  unsigned __int8 *v9; // ebp
  int v10; // eax
  int v11; // ebx
  char *v12; // eax
  sess_cert_st *sess_cert; // eax
  int peer_dh_tmp; // ebx
  dh_st *v16; // eax
  dh_st *v17; // ebp
  int v18; // ebx
  __int64 v19; // rax
  int v20; // ebx
  unsigned __int8 *v21; // edi
  sess_cert_st *v22; // eax
  const env_md_st *peer_ecdh_tmp; // ebx
  evp_pkey_st *pubkey; // eax
  const ec_group_st *v25; // ebp
  const rsa_meth_st *v26; // eax
  const ec_point_st *v27; // ebx
  ec_key_st *v28; // eax
  int degree; // eax
  ecdh_data_st *v30; // ebx
  const ec_point_st *v31; // eax
  unsigned int v32; // ebx
  bignum_ctx *v33; // eax
  const ec_point_st *v34; // eax
  unsigned int v35; // ebx
  int v36; // edi
  sess_cert_st *v37; // ecx
  x509_st *x509; // eax
  evp_pkey_ctx_st *v39; // ebp
  cert_pkey_st *key; // ecx
  engine_st *v41; // ebx
  char *v42; // eax
  const env_md_st *digestbyname; // eax
  unsigned int v44; // eax
  int v45; // edi
  int v46; // eax
  unsigned int (__cdecl *psk_client_callback)(ssl_st *, const char *, char *, unsigned int, unsigned __int8 *, unsigned int); // eax
  unsigned int v48; // eax
  int v49; // ebp
  char v50; // cl
  char *v51; // eax
  ssl_session_st *session; // ecx
  ssl_session_st *v53; // eax
  unsigned int v54; // kr00_4
  evp_pkey_st *v55; // [esp-18h] [ebp-3A0h]
  bignum_ctx *v56; // [esp-4h] [ebp-38Ch]
  engine_st *e; // [esp+10h] [ebp-378h]
  bignum_ctx *ctx; // [esp+14h] [ebp-374h]
  __m128i *src; // [esp+18h] [ebp-370h]
  unsigned int outlen; // [esp+1Ch] [ebp-36Ch] BYREF
  evp_pkey_st *v61; // [esp+20h] [ebp-368h]
  evp_pkey_st *x; // [esp+24h] [ebp-364h]
  unsigned int v63; // [esp+28h] [ebp-360h] BYREF
  char *data; // [esp+2Ch] [ebp-35Ch]
  unsigned __int8 p2[2]; // [esp+30h] [ebp-358h] BYREF
  unsigned __int8 in[32]; // [esp+60h] [ebp-328h] BYREF
  __m128i out[16]; // [esp+80h] [ebp-308h] BYREF
  __m128i v68[32]; // [esp+180h] [ebp-208h] BYREF

  v2 = s->state == 4480;
  e = 0;
  x = 0;
  src = 0;
  ctx = 0;
  if ( !v2 )
    return ssl3_do_write(s, 22);
  algorithm_mkey = s->s3->tmp.new_cipher->algorithm_mkey;
  data = s->init_buf->data;
  v4 = (unsigned __int8 *)(data + 4);
  if ( (algorithm_mkey & 1) == 0 )
  {
    if ( (algorithm_mkey & 0xE) != 0 )
    {
      sess_cert = s->session->sess_cert;
      if ( !sess_cert )
      {
        ssl3_send_alert(s, 2, 10);
        ERR_put_error(a1, 0x14u, 152, 244, ".\\ssl\\s3_clnt.c", 2223);
        goto err_222;
      }
      peer_dh_tmp = (int)sess_cert->peer_dh_tmp;
      if ( !peer_dh_tmp )
      {
        ssl3_send_alert(s, 2, 40);
        ERR_put_error(0, 0x14u, 152, 238, ".\\ssl\\s3_clnt.c", 2233);
        goto err_222;
      }
      v16 = DHparams_dup(peer_dh_tmp, sess_cert->peer_dh_tmp);
      v17 = v16;
      if ( !v16 )
      {
        ERR_put_error(peer_dh_tmp, 0x14u, 152, 5, ".\\ssl\\s3_clnt.c", 2240);
        goto err_222;
      }
      if ( !DH_generate_key(v16) )
      {
        ERR_put_error(peer_dh_tmp, 0x14u, 152, 5, ".\\ssl\\s3_clnt.c", 2245);
        DH_free((int)v4, peer_dh_tmp, v17);
        goto err_222;
      }
      v18 = DH_compute_key(v4, *(const bignum_st **)(peer_dh_tmp + 20), v17);
      if ( v18 <= 0 )
      {
        ERR_put_error(v18, 0x14u, 152, 5, ".\\ssl\\s3_clnt.c", 2257);
        DH_free((int)v4, v18, v17);
        goto err_222;
      }
      s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(s, s->session->master_key, v4, v18);
      memset((int)v4, 0, v18);
      v19 = BN_num_bits(v17->pub_key) + 7;
      HIDWORD(v19) = BYTE4(v19) & 7;
      v20 = (HIDWORD(v19) + (int)v19) >> 3;
      *v4 = (HIDWORD(v19) + (int)v19) >> 11;
      v4[1] = v20;
      v21 = v4 + 2;
      BN_bn2bin(v17->pub_key, v21);
      v11 = v20 + 2;
      DH_free((int)v21, v11, v17);
    }
    else if ( (algorithm_mkey & 0xE0) != 0 )
    {
      v22 = s->session->sess_cert;
      peer_ecdh_tmp = (const env_md_st *)v22->peer_ecdh_tmp;
      if ( !peer_ecdh_tmp )
      {
        pubkey = X509_get_pubkey(v22->peer_pkeys[5].x509);
        x = pubkey;
        if ( !pubkey || pubkey->type != 408 || (peer_ecdh_tmp = (const env_md_st *)pubkey->pkey.ptr) == 0 )
        {
          ERR_put_error((int)peer_ecdh_tmp, 0x14u, 152, 68, ".\\ssl\\s3_clnt.c", 2331);
          goto err_222;
        }
      }
      v25 = (const ec_group_st *)EVP_CIPHER_block_size(peer_ecdh_tmp);
      v26 = EC_KEY_get0_public_key((const engine_st *)peer_ecdh_tmp);
      v27 = (const ec_point_st *)v26;
      if ( !v25 || !v26 )
      {
        ERR_put_error((int)v26, 0x14u, 152, 68, ".\\ssl\\s3_clnt.c", 2344);
        goto err_222;
      }
      v28 = EC_KEY_new((int)v26);
      e = (engine_st *)v28;
      if ( !v28 )
      {
        ERR_put_error((int)v27, 0x14u, 152, 65, ".\\ssl\\s3_clnt.c", 2350);
        goto err_222;
      }
      if ( !EC_KEY_set_group(v28, v25) )
      {
        ERR_put_error((int)v27, 0x14u, 152, 16, ".\\ssl\\s3_clnt.c", 2356);
        goto err_222;
      }
      if ( !EC_KEY_generate_key((bignum_ctx *)e) )
      {
        ERR_put_error((int)v27, 0x14u, 152, 43, ".\\ssl\\s3_clnt.c", 2384);
        goto err_222;
      }
      degree = EC_GROUP_get_degree((int)v27, v25);
      if ( degree <= 0 )
      {
        ERR_put_error((int)v27, 0x14u, 152, 43, ".\\ssl\\s3_clnt.c", 2397);
        goto err_222;
      }
      v30 = ECDH_compute_key((int)v4, v4, (degree + 7) / 8, v27, (ec_key_st *)e, 0);
      if ( (int)v30 <= 0 )
      {
        ERR_put_error((int)v30, 0x14u, 152, 43, ".\\ssl\\s3_clnt.c", 2404);
        goto err_222;
      }
      s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(
                                        s,
                                        s->session->master_key,
                                        v4,
                                        (int)v30);
      memset((int)v4, 0, (int)v30);
      v31 = (const ec_point_st *)EC_KEY_get0_public_key(e);
      v32 = EC_POINT_point2oct((int)v30, v25, v31, POINT_CONVERSION_UNCOMPRESSED, 0, 0, 0);
      src = (__m128i *)CRYPTO_malloc(v32, ".\\ssl\\s3_clnt.c", 2434);
      v33 = BN_CTX_new(v32);
      ctx = v33;
      if ( !src || !v33 )
      {
        ERR_put_error(v32, 0x14u, 152, 65, ".\\ssl\\s3_clnt.c", 2439);
        goto err_222;
      }
      v56 = v33;
      v34 = (const ec_point_st *)EC_KEY_get0_public_key(e);
      v35 = EC_POINT_point2oct(v32, v25, v34, POINT_CONVERSION_UNCOMPRESSED, (unsigned __int8 *)src, v32, v56);
      *v4 = v35;
      v36 = (int)(v4 + 1);
      memcpy(v36, src, v35);
      v11 = v35 + 1;
      BN_CTX_free(ctx);
      CRYPTO_free(src);
      EC_KEY_free((ec_key_st *)e);
      EVP_PKEY_free(v36, x);
    }
    else if ( (algorithm_mkey & 0x200) != 0 )
    {
      v37 = s->session->sess_cert;
      x509 = v37->peer_pkeys[7].x509;
      if ( !x509 )
      {
        x509 = v37->peer_pkeys[6].x509;
        if ( !x509 )
        {
          ERR_put_error(a1, 0x14u, 152, 330, ".\\ssl\\s3_clnt.c", 2483);
          goto err_222;
        }
      }
      v61 = X509_get_pubkey(x509);
      v39 = EVP_PKEY_CTX_new((int)v4, v61, 0);
      EVP_PKEY_encrypt_init(a1, v39);
      RAND_bytes((int)v4);
      if ( s->s3->tmp.cert_req )
      {
        key = s->cert->key;
        if ( key->privatekey )
        {
          if ( EVP_PKEY_derive_set_peer(a1, v39, key->privatekey) <= 0 )
            ERR_clear_error(a1);
        }
      }
      v41 = (engine_st *)EVP_MD_CTX_create();
      v42 = (char *)OBJ_nid2sn((int)v41, 0x329u);
      digestbyname = EVP_get_digestbyname(v42);
      EVP_DigestInit(v41, (env_md_ctx_st *)v41, digestbyname);
      EVP_DigestUpdate((env_md_ctx_st *)v41);
      EVP_DigestUpdate((env_md_ctx_st *)v41);
      EVP_DigestFinal_ex((int)v4, (int)v41, (env_md_ctx_st *)v41, p2, &v63);
      EVP_MD_CTX_destroy((int)v4, (int)v41, (env_md_ctx_st *)v41);
      if ( EVP_PKEY_CTX_ctrl((int)v41, v39, -1, 256, 8, 8, p2) < 0 )
      {
        ERR_put_error((int)v41, 0x14u, 152, 274, ".\\ssl\\s3_clnt.c", 2519);
        goto err_222;
      }
      *v4++ = 48;
      outlen = 255;
      if ( EVP_PKEY_encrypt((int)v41, v39, (unsigned __int8 *)out, &outlen, in, 0x20u) < 0 )
      {
        ERR_put_error((int)v41, 0x14u, 152, 274, ".\\ssl\\s3_clnt.c", 2528);
        goto err_222;
      }
      v44 = outlen;
      if ( outlen < 0x80 )
      {
        v11 = outlen + 2;
      }
      else
      {
        *v4++ = -127;
        v11 = v44 + 3;
      }
      *v4 = v44;
      v45 = (int)(v4 + 1);
      memcpy(v45, out, v44);
      if ( EVP_PKEY_CTX_ctrl(v11, v39, -1, -1, 2, 2, 0) > 0 )
        s->s3->flags |= 0x10u;
      EVP_PKEY_CTX_free(v45, v39);
      v46 = s->method->ssl3_enc->generate_master_secret(s, s->session->master_key, in, 32);
      v55 = v61;
      s->session->master_key_length = v46;
      EVP_PKEY_free(v45, v55);
    }
    else
    {
      if ( (algorithm_mkey & 0x100) == 0 )
      {
        ssl3_send_alert(s, 2, 40);
        ERR_put_error(a1, 0x14u, 152, 68, ".\\ssl\\s3_clnt.c", 2643);
        goto err_222;
      }
      psk_client_callback = s->psk_client_callback;
      v11 = 0;
      v61 = (evp_pkey_st *)1;
      if ( !psk_client_callback )
      {
        ERR_put_error(0, 0x14u, 152, 224, ".\\ssl\\s3_clnt.c", 2569);
        goto err_222;
      }
      v48 = psk_client_callback(s, s->ctx->psk_identity_hint, out[0].m128i_i8, 128u, (unsigned __int8 *)v68, 516u);
      outlen = v48;
      if ( v48 <= 0x100 )
      {
        if ( v48 )
        {
          v49 = 2 * v48 + 4;
          memmove((int)&v68[0].m128i_i32[1] + v48, v68, v48);
          v63 = outlen >> 8;
          v68[0].m128i_i8[0] = BYTE1(outlen);
          v68[0].m128i_i8[1] = outlen;
          memset((int)v68[0].m128i_i32 + 2, 0, outlen);
          v50 = outlen;
          v51 = &v68[0].m128i_i8[outlen + 2];
          *v51 = BYTE1(outlen);
          v51[1] = v50;
          if ( s->session->psk_identity_hint )
            CRYPTO_free(s->session->psk_identity_hint);
          s->session->psk_identity_hint = BUF_strdup(s->ctx->psk_identity_hint);
          if ( !s->ctx->psk_identity_hint || s->session->psk_identity_hint )
          {
            session = s->session;
            if ( session->psk_identity )
              CRYPTO_free(session->psk_identity);
            s->session->psk_identity = BUF_strdup(out[0].m128i_i8);
            v53 = s->session;
            if ( v53->psk_identity )
            {
              s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(
                                                s,
                                                v53->master_key,
                                                (unsigned __int8 *)v68,
                                                v49);
              v54 = strlen(out[0].m128i_i8);
              *v4 = BYTE1(v54);
              v4[1] = v54;
              v4 += 2;
              memcpy((int)v4, out, v54);
              v11 = v54 + 2;
              v61 = 0;
            }
            else
            {
              ERR_put_error(0, 0x14u, 152, 65, ".\\ssl\\s3_clnt.c", 2615);
            }
          }
          else
          {
            ERR_put_error(0, 0x14u, 152, 65, ".\\ssl\\s3_clnt.c", 2605);
          }
        }
        else
        {
          ERR_put_error(0, 0x14u, 152, 223, ".\\ssl\\s3_clnt.c", 2585);
        }
      }
      else
      {
        ERR_put_error(0, 0x14u, 152, 68, ".\\ssl\\s3_clnt.c", 2579);
      }
      OPENSSL_cleanse(out, 128);
      OPENSSL_cleanse(v68, 516);
      if ( v61 )
      {
        ssl3_send_alert(s, 2, 40);
        goto err_222;
      }
    }
LABEL_21:
    v12 = data;
    *data = 16;
    (++v12)[2] = v11;
    *v12 = BYTE2(v11);
    v12[1] = BYTE1(v11);
    s->state = 4481;
    s->init_num = v11 + 4;
    s->init_off = 0;
    return ssl3_do_write(s, 22);
  }
  v5 = s->session->sess_cert;
  if ( v5->peer_rsa_tmp )
  {
    peer_rsa_tmp = v5->peer_rsa_tmp;
  }
  else
  {
    v7 = X509_get_pubkey(v5->peer_pkeys[0].x509);
    if ( !v7 || v7->type != 6 || !v7->pkey.ptr )
    {
      ERR_put_error(a1, 0x14u, 152, 68, ".\\ssl\\s3_clnt.c", 2037);
      goto err_222;
    }
    peer_rsa_tmp = v7->pkey.rsa;
    EVP_PKEY_free((int)v4, v7);
  }
  client_version = s->client_version;
  p2[0] = BYTE1(s->client_version);
  p2[1] = client_version;
  if ( RAND_bytes((int)v4) > 0 )
  {
    s->session->master_key_length = 48;
    v9 = v4;
    if ( s->version > 768 )
      v4 += 2;
    v10 = RSA_public_encrypt(48, p2, v4, peer_rsa_tmp);
    v11 = v10;
    if ( (s->options & 0x8000000) != 0 )
      ++v4[1];
    if ( (s->options & 0x10000000) != 0 )
      p2[0] = 112;
    if ( v10 <= 0 )
    {
      ERR_put_error(v10, 0x14u, 152, 119, ".\\ssl\\s3_clnt.c", 2063);
      goto err_222;
    }
    if ( s->version > 768 )
    {
      v9[1] = v10;
      *v9 = BYTE1(v10);
      v11 = v10 + 2;
    }
    s->session->master_key_length = s->method->ssl3_enc->generate_master_secret(s, s->session->master_key, p2, 48);
    OPENSSL_cleanse(p2, 48);
    goto LABEL_21;
  }
err_222:
  BN_CTX_free(ctx);
  if ( src )
    CRYPTO_free(src);
  if ( e )
    EC_KEY_free((ec_key_st *)e);
  EVP_PKEY_free((int)v4, x);
  return -1;
}
