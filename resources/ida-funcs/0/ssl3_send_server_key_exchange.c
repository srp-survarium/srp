int __cdecl ssl3_send_server_key_exchange(ssl_st *s)
{
  char *data; // ebx
  const ssl_cipher_st *new_cipher; // ecx
  unsigned int algorithm_mkey; // eax
  buf_mem_st *init_buf; // edx
  cert_st *cert; // ebp
  rsa_st *rsa_tmp; // esi
  rsa_st *(__cdecl *rsa_tmp_cb)(ssl_st *, int, int); // eax
  rsa_st *v8; // eax
  bignum_st *e; // ecx
  ssl3_state_st *s3; // edx
  dh_st *dh_tmp; // esi
  dh_st *(__cdecl *dh_tmp_cb)(ssl_st *, int, int); // ebp
  dh_st *v13; // eax
  dh_st *v14; // ebp
  bignum_st *v15; // eax
  bignum_st *g; // ecx
  bignum_st *pub_key; // edx
  const ec_key_st *ecdh_tmp; // eax
  ec_key_st *(__cdecl *ecdh_tmp_cb)(ssl_st *, int, int); // ebp
  ec_key_st *v20; // eax
  ssl_st *v21; // esi
  int shutdown; // eax
  const ec_point_st *v23; // eax
  unsigned int v24; // ebp
  bignum_ctx *v25; // eax
  const ec_point_st *v26; // eax
  bignum_st *v27; // eax
  int v28; // eax
  unsigned int v29; // ecx
  int v30; // edx
  int v31; // eax
  ssl3_state_st *v32; // ecx
  const ssl_cipher_st *v33; // eax
  evp_pkey_st *sign_pkey; // eax
  evp_pkey_st *v35; // ebp
  int v36; // esi
  int v37; // eax
  unsigned int v38; // eax
  unsigned __int8 *v39; // esi
  unsigned __int8 *v40; // esi
  char v41; // dl
  unsigned int v42; // ebx
  __m128i *v43; // ebp
  _BYTE *v44; // esi
  unsigned __int8 *v45; // esi
  int type; // eax
  int i; // ebp
  const env_md_st *md5; // eax
  int v49; // eax
  int v50; // eax
  const env_md_st *v52; // eax
  const env_md_st *v53; // eax
  int v54; // eax
  __int16 v55; // [esp-Ch] [ebp-A4h]
  int v56; // [esp-4h] [ebp-9Ch]
  bignum_ctx *v57; // [esp-4h] [ebp-9Ch]
  unsigned int siglen; // [esp+10h] [ebp-88h] BYREF
  int v59; // [esp+14h] [ebp-84h]
  unsigned int count; // [esp+18h] [ebp-80h]
  bignum_ctx *v61; // [esp+1Ch] [ebp-7Ch]
  unsigned __int8 *src; // [esp+20h] [ebp-78h]
  buf_mem_st *v63; // [esp+24h] [ebp-74h]
  evp_pkey_st *v64; // [esp+28h] [ebp-70h]
  bignum_st *a; // [esp+2Ch] [ebp-6Ch]
  bignum_st *v66; // [esp+30h] [ebp-68h]
  bignum_st *v67; // [esp+34h] [ebp-64h]
  int v68; // [esp+38h] [ebp-60h]
  unsigned int v69; // [esp+3Ch] [ebp-5Ch] BYREF
  int v70; // [esp+40h] [ebp-58h]
  env_md_ctx_st ctx; // [esp+44h] [ebp-54h] BYREF
  unsigned int v72; // [esp+5Ch] [ebp-3Ch]
  _DWORD v73[4]; // [esp+60h] [ebp-38h]
  unsigned __int8 v74[36]; // [esp+70h] [ebp-28h] BYREF

  data = 0;
  src = 0;
  count = 0;
  v70 = 0;
  v61 = 0;
  EVP_MD_CTX_init(&ctx);
  if ( s->state != 8528 )
    goto LABEL_87;
  new_cipher = s->s3->tmp.new_cipher;
  algorithm_mkey = new_cipher->algorithm_mkey;
  init_buf = s->init_buf;
  cert = s->cert;
  v72 = algorithm_mkey;
  v63 = init_buf;
  v68 = 0;
  v67 = 0;
  v66 = 0;
  a = 0;
  v59 = 0;
  if ( (algorithm_mkey & 1) != 0 )
  {
    rsa_tmp = cert->rsa_tmp;
    if ( !rsa_tmp )
    {
      rsa_tmp_cb = cert->rsa_tmp_cb;
      if ( !rsa_tmp_cb )
      {
        v56 = 1483;
        v55 = 172;
        goto LABEL_97;
      }
      v8 = rsa_tmp_cb(s, new_cipher->algo_strength & 2, (new_cipher->algo_strength & 8) != 0 ? 512 : 1024);
      rsa_tmp = v8;
      if ( !v8 )
      {
        v56 = 1474;
        v55 = 282;
LABEL_97:
        v36 = 40;
        ERR_put_error((int)data, 0x14u, 155, v55, ".\\ssl\\s3_srvr.c", v56);
        goto f_err_6;
      }
      RSA_up_ref(v8);
      cert->rsa_tmp = rsa_tmp;
    }
    e = rsa_tmp->e;
    s3 = s->s3;
    a = rsa_tmp->n;
    v66 = e;
    s3->tmp.use_rsa_tmp = 1;
    goto LABEL_59;
  }
  if ( (algorithm_mkey & 8) == 0 )
  {
    if ( (algorithm_mkey & 0x80u) == 0 )
    {
      if ( (algorithm_mkey & 0x100) == 0 )
      {
        v56 = 1684;
        v55 = 250;
        goto LABEL_97;
      }
      v59 = strlen(s->ctx->psk_identity_hint) + 2;
    }
    else
    {
      ecdh_tmp = cert->ecdh_tmp;
      if ( !ecdh_tmp )
      {
        ecdh_tmp_cb = cert->ecdh_tmp_cb;
        if ( !ecdh_tmp_cb
          || (ecdh_tmp = ecdh_tmp_cb(
                           s,
                           new_cipher->algo_strength & 2,
                           (new_cipher->algo_strength & 8) != 0 ? 512 : 1024)) == 0 )
        {
          v56 = 1563;
          v55 = 311;
          goto LABEL_97;
        }
      }
      if ( s->s3->tmp.ecdh )
      {
        ERR_put_error(0, 0x14u, 155, 68, ".\\ssl\\s3_srvr.c", 1569);
        goto LABEL_101;
      }
      v20 = EC_KEY_dup(0, ecdh_tmp);
      v21 = (ssl_st *)v20;
      if ( !v20 )
      {
        ERR_put_error(0, 0x14u, 155, 43, ".\\ssl\\s3_srvr.c", 1581);
        goto LABEL_101;
      }
      s->s3->tmp.ecdh = v20;
      if ( (!EC_KEY_get0_public_key((const engine_st *)v20)
         || !EC_KEY_get0_private_key(v21)
         || (s->options & 0x80000) != 0)
        && !EC_KEY_generate_key((bignum_ctx *)v21) )
      {
        ERR_put_error(0, 0x14u, 155, 43, ".\\ssl\\s3_srvr.c", 1592);
        goto LABEL_101;
      }
      data = (char *)EVP_CIPHER_block_size((const env_md_st *)v21);
      if ( !data || !EC_KEY_get0_public_key((const engine_st *)v21) || !EC_KEY_get0_private_key(v21) )
      {
        ERR_put_error((int)data, 0x14u, 155, 43, ".\\ssl\\s3_srvr.c", 1601);
        goto LABEL_101;
      }
      if ( (s->s3->tmp.new_cipher->algo_strength & 2) != 0
        && EC_GROUP_get_degree((int)data, (const ec_group_st *)data) > 163 )
      {
        ERR_put_error((int)data, 0x14u, 155, 310, ".\\ssl\\s3_srvr.c", 1608);
        goto LABEL_101;
      }
      shutdown = SSL_get_shutdown((const ssl_st *)data);
      v70 = tls1_ec_nid2curve_id(shutdown);
      if ( !v70 )
      {
        ERR_put_error((int)data, 0x14u, 155, 315, ".\\ssl\\s3_srvr.c", 1620);
        goto LABEL_101;
      }
      v23 = (const ec_point_st *)EC_KEY_get0_public_key((const engine_st *)v21);
      v24 = EC_POINT_point2oct((int)data, (const ec_group_st *)data, v23, POINT_CONVERSION_UNCOMPRESSED, 0, 0, 0);
      src = (unsigned __int8 *)CRYPTO_malloc(v24, ".\\ssl\\s3_srvr.c", 1634);
      v25 = BN_CTX_new((int)data);
      v61 = v25;
      if ( !src || !v25 )
      {
        ERR_put_error((int)data, 0x14u, 155, 65, ".\\ssl\\s3_srvr.c", 1638);
        goto err_227;
      }
      v57 = v25;
      v26 = (const ec_point_st *)EC_KEY_get0_public_key((const engine_st *)v21);
      count = EC_POINT_point2oct(
                (int)data,
                (const ec_group_st *)data,
                v26,
                POINT_CONVERSION_UNCOMPRESSED,
                src,
                v24,
                v57);
      if ( !count )
      {
        ERR_put_error((int)data, 0x14u, 155, 43, ".\\ssl\\s3_srvr.c", 1650);
        goto err_227;
      }
      BN_CTX_free(v61);
      v61 = 0;
      v59 = count + 4;
      a = 0;
      v66 = 0;
      v67 = 0;
      v68 = 0;
    }
    goto LABEL_59;
  }
  dh_tmp = cert->dh_tmp;
  if ( !dh_tmp )
  {
    dh_tmp_cb = cert->dh_tmp_cb;
    if ( !dh_tmp_cb
      || (dh_tmp = dh_tmp_cb(s, new_cipher->algo_strength & 2, (new_cipher->algo_strength & 8) != 0 ? 512 : 1024)) == 0 )
    {
      v56 = 1503;
      v55 = 171;
      goto LABEL_97;
    }
  }
  if ( !s->s3->tmp.dh )
  {
    v13 = DHparams_dup(0, dh_tmp);
    v14 = v13;
    if ( !v13 )
    {
      ERR_put_error(0, 0x14u, 155, 5, ".\\ssl\\s3_srvr.c", 1515);
      goto LABEL_101;
    }
    s->s3->tmp.dh = v13;
    if ( dh_tmp->pub_key && dh_tmp->priv_key && ((unsigned int)&loc_100000 & s->options) == 0 )
    {
      v13->pub_key = BN_dup(0, dh_tmp->pub_key);
      v15 = BN_dup(0, dh_tmp->priv_key);
      v14->priv_key = v15;
      if ( !v14->pub_key || !v15 )
      {
        ERR_put_error(0, 0x14u, 155, 5, ".\\ssl\\s3_srvr.c", 1538);
        goto LABEL_101;
      }
    }
    else if ( !DH_generate_key(v13) )
    {
      ERR_put_error(0, 0x14u, 155, 5, ".\\ssl\\s3_srvr.c", 1527);
      goto LABEL_101;
    }
    g = v14->g;
    pub_key = v14->pub_key;
    a = v14->p;
    v66 = g;
    v67 = pub_key;
LABEL_59:
    siglen = 0;
    if ( a )
    {
      v27 = a;
      do
      {
        v28 = BN_num_bits(v27);
        v29 = siglen;
        v30 = v59;
        v31 = (v28 + 7) / 8;
        v73[siglen] = v31;
        ++v29;
        v59 = v30 + v31 + 2;
        v27 = *(&a + v29);
        siglen = v29;
      }
      while ( v27 );
    }
    v32 = s->s3;
    v33 = v32->tmp.new_cipher;
    if ( (v33->algorithm_auth & 4) != 0 || (v33->algorithm_mkey & 0x100) != 0 )
    {
      v37 = 0;
      v64 = 0;
      v35 = 0;
    }
    else
    {
      sign_pkey = ssl_get_sign_pkey((int)data, s, v32->tmp.new_cipher);
      v35 = sign_pkey;
      v64 = sign_pkey;
      if ( !sign_pkey )
      {
        v36 = 50;
f_err_6:
        ssl3_send_alert(s, 2, v36);
err_227:
        if ( src )
          CRYPTO_free(src);
        goto LABEL_101;
      }
      v37 = EVP_PKEY_size(sign_pkey);
    }
    if ( !BUF_MEM_grow_clean(v63, v37 + v59 + 4) )
    {
      ERR_put_error((int)data, 0x14u, 155, 7, ".\\ssl\\s3_srvr.c", 1712);
      goto err_227;
    }
    data = s->init_buf->data;
    v38 = 0;
    v63 = (buf_mem_st *)data;
    v39 = (unsigned __int8 *)(data + 4);
    siglen = 0;
    if ( a )
    {
      do
      {
        *v39 = BYTE1(v73[v38]);
        v39[1] = v73[siglen];
        v40 = v39 + 2;
        BN_bn2bin(*(&a + siglen), v40);
        v39 = &v40[v73[siglen++]];
        v38 = siglen;
      }
      while ( *(&a + siglen) );
    }
    if ( (v72 & 0x80u) != 0 )
    {
      v41 = v70;
      v42 = count;
      v43 = (__m128i *)src;
      *v39 = 3;
      v44 = v39 + 1;
      *v44++ = 0;
      *v44++ = v41;
      *v44++ = v42;
      memcpy((int)v44, v43, v42);
      CRYPTO_free(v43);
      v35 = v64;
      v39 = &v44[v42];
      data = (char *)v63;
      src = 0;
    }
    if ( (v72 & 0x100) != 0 )
    {
      *v39 = (unsigned __int16)strlen(s->ctx->psk_identity_hint) >> 8;
      v39[1] = strlen(s->ctx->psk_identity_hint);
      v45 = v39 + 2;
      strncpy(v45, (unsigned __int8 *)s->ctx->psk_identity_hint, strlen(s->ctx->psk_identity_hint));
      v35 = v64;
      v39 = &v45[strlen(s->ctx->psk_identity_hint)];
    }
    if ( v35 )
    {
      type = v35->type;
      if ( v35->type == 6 )
      {
        data = (char *)v74;
        count = 0;
        for ( i = 2; i > 0; --i )
        {
          if ( i == 2 )
            md5 = s->ctx->md5;
          else
            md5 = s->ctx->sha1;
          EVP_DigestInit_ex((engine_st *)data, &ctx, md5, 0);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          EVP_DigestFinal_ex((int)s, (int)data, &ctx, (unsigned __int8 *)data, &siglen);
          count += siglen;
          data += siglen;
        }
        if ( RSA_sign(0x72u, v74, count, v39 + 2, &v69, v64->pkey.rsa) <= 0 )
        {
          ERR_put_error((int)data, 0x14u, 155, 4, ".\\ssl\\s3_srvr.c", 1786);
          goto err_227;
        }
        data = (char *)v63;
        *v39 = BYTE1(v69);
        v49 = v59;
        v39[1] = v69;
        v59 = v49 + v69 + 2;
      }
      else
      {
        if ( type == 116 )
        {
          v52 = EVP_dss1();
          EVP_DigestInit_ex((engine_st *)data, &ctx, v52, 0);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          if ( !EVP_SignFinal(&ctx, v39 + 2, &siglen, v35) )
          {
            ERR_put_error((int)data, 0x14u, 155, 10, ".\\ssl\\s3_srvr.c", 1805);
            goto err_227;
          }
        }
        else
        {
          if ( type != 408 )
          {
            v56 = 1835;
            v55 = 251;
            goto LABEL_97;
          }
          v53 = EVP_ecdsa();
          EVP_DigestInit_ex((engine_st *)data, &ctx, v53, 0);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          if ( !EVP_SignFinal(&ctx, v39 + 2, &siglen, v35) )
          {
            ERR_put_error((int)data, 0x14u, 155, 42, ".\\ssl\\s3_srvr.c", 1824);
            goto err_227;
          }
        }
        *v39 = BYTE1(siglen);
        v54 = v59;
        v39[1] = siglen;
        v59 = v54 + siglen + 2;
      }
    }
    v50 = v59;
    *data++ = 12;
    data[2] = v50;
    *data = BYTE2(v50);
    data[1] = BYTE1(v50);
    s->init_num = v50 + 4;
    s->init_off = 0;
LABEL_87:
    s->state = 8529;
    EVP_MD_CTX_cleanup((int)s, (int)data, &ctx);
    return ssl3_do_write(s, 22);
  }
  ERR_put_error(0, 0x14u, 155, 68, ".\\ssl\\s3_srvr.c", 1509);
LABEL_101:
  BN_CTX_free(v61);
  EVP_MD_CTX_cleanup((int)s, (int)data, &ctx);
  return -1;
}
