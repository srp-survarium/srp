int __cdecl ssl3_send_server_key_exchange(ssl_st *s)
{
  const ssl_cipher_st *new_cipher; // ecx
  unsigned int algorithm_mkey; // eax
  buf_mem_st *init_buf; // edx
  cert_st *cert; // ebp
  rsa_st *rsa_tmp; // esi
  rsa_st *(__cdecl *rsa_tmp_cb)(ssl_st *, int, int); // eax
  rsa_st *v7; // eax
  bignum_st *e; // ecx
  ssl3_state_st *s3; // edx
  dh_st *dh_tmp; // esi
  dh_st *(__cdecl *dh_tmp_cb)(ssl_st *, int, int); // ebp
  dh_st *v12; // eax
  dh_st *v13; // ebp
  bignum_st *v14; // eax
  bignum_st *g; // ecx
  bignum_st *pub_key; // edx
  const ec_key_st *ecdh_tmp; // eax
  ec_key_st *(__cdecl *ecdh_tmp_cb)(ssl_st *, int, int); // ebp
  ec_key_st *v19; // eax
  ssl_st *v20; // esi
  const ec_group_st *v21; // ebx
  int shutdown; // eax
  const ec_point_st *v23; // eax
  int v24; // ebp
  bignum_ctx *v25; // eax
  const ec_point_st *v26; // eax
  bignum_st *v27; // eax
  int v28; // eax
  unsigned int v29; // ecx
  unsigned int v30; // edx
  int v31; // eax
  ssl3_state_st *v32; // ecx
  const ssl_cipher_st *v33; // eax
  evp_pkey_st *sign_pkey; // eax
  evp_pkey_st *v35; // ebp
  int v36; // esi
  int v37; // eax
  buf_mem_st *data; // ebx
  unsigned int v39; // eax
  unsigned __int8 *p_data; // esi
  unsigned __int8 *v41; // esi
  unsigned __int8 v42; // dl
  unsigned int v43; // ebx
  unsigned __int8 *v44; // ebp
  unsigned __int8 *v45; // esi
  unsigned __int8 *v46; // esi
  int type; // eax
  unsigned __int8 *v48; // ebx
  int i; // ebp
  const env_md_st *md5; // eax
  unsigned int v51; // eax
  unsigned int v52; // eax
  _BYTE *v53; // ebx
  const env_md_st *v55; // eax
  const env_md_st *v56; // eax
  unsigned int v57; // eax
  __int16 v58; // [esp-Ch] [ebp-A4h]
  int v59; // [esp-4h] [ebp-9Ch]
  bignum_ctx *v60; // [esp-4h] [ebp-9Ch]
  unsigned int size; // [esp+10h] [ebp-88h] BYREF
  unsigned int v62; // [esp+14h] [ebp-84h]
  unsigned int count; // [esp+18h] [ebp-80h]
  bignum_ctx *v64; // [esp+1Ch] [ebp-7Ch]
  unsigned __int8 *buf; // [esp+20h] [ebp-78h]
  buf_mem_st *str; // [esp+24h] [ebp-74h]
  evp_pkey_st *v67; // [esp+28h] [ebp-70h]
  bignum_st *a; // [esp+2Ch] [ebp-6Ch]
  bignum_st *v69; // [esp+30h] [ebp-68h]
  bignum_st *v70; // [esp+34h] [ebp-64h]
  int v71; // [esp+38h] [ebp-60h]
  unsigned int siglen; // [esp+3Ch] [ebp-5Ch] BYREF
  int v73; // [esp+40h] [ebp-58h]
  env_md_ctx_st ctx; // [esp+44h] [ebp-54h] BYREF
  unsigned int v75; // [esp+5Ch] [ebp-3Ch]
  _DWORD v76[4]; // [esp+60h] [ebp-38h]
  unsigned __int8 md[36]; // [esp+70h] [ebp-28h] BYREF

  buf = 0;
  count = 0;
  v73 = 0;
  v64 = 0;
  EVP_MD_CTX_init(&ctx);
  if ( s->state != 8528 )
    goto LABEL_87;
  new_cipher = s->s3->tmp.new_cipher;
  algorithm_mkey = new_cipher->algorithm_mkey;
  init_buf = s->init_buf;
  cert = s->cert;
  v75 = algorithm_mkey;
  str = init_buf;
  v71 = 0;
  v70 = 0;
  v69 = 0;
  a = 0;
  v62 = 0;
  if ( (algorithm_mkey & 1) != 0 )
  {
    rsa_tmp = cert->rsa_tmp;
    if ( !rsa_tmp )
    {
      rsa_tmp_cb = cert->rsa_tmp_cb;
      if ( !rsa_tmp_cb )
      {
        v59 = 1483;
        v58 = 172;
        goto LABEL_97;
      }
      v7 = rsa_tmp_cb(s, new_cipher->algo_strength & 2, (new_cipher->algo_strength & 8) != 0 ? 512 : 1024);
      rsa_tmp = v7;
      if ( !v7 )
      {
        v59 = 1474;
        v58 = 282;
LABEL_97:
        v36 = 40;
        ERR_put_error(0x14u, 155, v58, ".\\ssl\\s3_srvr.c", v59);
        goto f_err_6;
      }
      RSA_up_ref(v7);
      cert->rsa_tmp = rsa_tmp;
    }
    e = rsa_tmp->e;
    s3 = s->s3;
    a = rsa_tmp->n;
    v69 = e;
    s3->tmp.use_rsa_tmp = 1;
    goto LABEL_59;
  }
  if ( (algorithm_mkey & 8) == 0 )
  {
    if ( (algorithm_mkey & 0x80u) == 0 )
    {
      if ( (algorithm_mkey & 0x100) == 0 )
      {
        v59 = 1684;
        v58 = 250;
        goto LABEL_97;
      }
      v62 = strlen(s->ctx->psk_identity_hint) + 2;
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
          v59 = 1563;
          v58 = 311;
          goto LABEL_97;
        }
      }
      if ( s->s3->tmp.ecdh )
      {
        ERR_put_error(0x14u, 155, 68, ".\\ssl\\s3_srvr.c", 1569);
        goto LABEL_101;
      }
      v19 = EC_KEY_dup(ecdh_tmp);
      v20 = (ssl_st *)v19;
      if ( !v19 )
      {
        ERR_put_error(0x14u, 155, 43, ".\\ssl\\s3_srvr.c", 1581);
        goto LABEL_101;
      }
      s->s3->tmp.ecdh = v19;
      if ( (!EC_KEY_get0_public_key((const engine_st *)v19)
         || !EC_KEY_get0_private_key(v20)
         || (s->options & 0x80000) != 0)
        && !EC_KEY_generate_key((bignum_ctx *)v20) )
      {
        ERR_put_error(0x14u, 155, 43, ".\\ssl\\s3_srvr.c", 1592);
        goto LABEL_101;
      }
      v21 = (const ec_group_st *)EVP_CIPHER_block_size((const env_md_st *)v20);
      if ( !v21 || !EC_KEY_get0_public_key((const engine_st *)v20) || !EC_KEY_get0_private_key(v20) )
      {
        ERR_put_error(0x14u, 155, 43, ".\\ssl\\s3_srvr.c", 1601);
        goto LABEL_101;
      }
      if ( (s->s3->tmp.new_cipher->algo_strength & 2) != 0 && EC_GROUP_get_degree(v21) > 163 )
      {
        ERR_put_error(0x14u, 155, 310, ".\\ssl\\s3_srvr.c", 1608);
        goto LABEL_101;
      }
      shutdown = SSL_get_shutdown((const ssl_st *)v21);
      v73 = tls1_ec_nid2curve_id(shutdown);
      if ( !v73 )
      {
        ERR_put_error(0x14u, 155, 315, ".\\ssl\\s3_srvr.c", 1620);
        goto LABEL_101;
      }
      v23 = (const ec_point_st *)EC_KEY_get0_public_key((const engine_st *)v20);
      v24 = EC_POINT_point2oct(v21, v23, POINT_CONVERSION_UNCOMPRESSED, 0, 0, 0);
      buf = (unsigned __int8 *)CRYPTO_malloc(v24, ".\\ssl\\s3_srvr.c", 1634);
      v25 = BN_CTX_new();
      v64 = v25;
      if ( !buf || !v25 )
      {
        ERR_put_error(0x14u, 155, 65, ".\\ssl\\s3_srvr.c", 1638);
        goto err_225;
      }
      v60 = v25;
      v26 = (const ec_point_st *)EC_KEY_get0_public_key((const engine_st *)v20);
      count = EC_POINT_point2oct(v21, v26, POINT_CONVERSION_UNCOMPRESSED, buf, v24, v60);
      if ( !count )
      {
        ERR_put_error(0x14u, 155, 43, ".\\ssl\\s3_srvr.c", 1650);
        goto err_225;
      }
      BN_CTX_free(v64);
      v64 = 0;
      v62 = count + 4;
      a = 0;
      v69 = 0;
      v70 = 0;
      v71 = 0;
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
      v59 = 1503;
      v58 = 171;
      goto LABEL_97;
    }
  }
  if ( !s->s3->tmp.dh )
  {
    v12 = DHparams_dup(dh_tmp);
    v13 = v12;
    if ( !v12 )
    {
      ERR_put_error(0x14u, 155, 5, ".\\ssl\\s3_srvr.c", 1515);
      goto LABEL_101;
    }
    s->s3->tmp.dh = v12;
    if ( dh_tmp->pub_key && dh_tmp->priv_key && (s->options & 0x100000) == 0 )
    {
      v12->pub_key = BN_dup(dh_tmp->pub_key);
      v14 = BN_dup(dh_tmp->priv_key);
      v13->priv_key = v14;
      if ( !v13->pub_key || !v14 )
      {
        ERR_put_error(0x14u, 155, 5, ".\\ssl\\s3_srvr.c", 1538);
        goto LABEL_101;
      }
    }
    else if ( !DH_generate_key(v12) )
    {
      ERR_put_error(0x14u, 155, 5, ".\\ssl\\s3_srvr.c", 1527);
      goto LABEL_101;
    }
    g = v13->g;
    pub_key = v13->pub_key;
    a = v13->p;
    v69 = g;
    v70 = pub_key;
LABEL_59:
    size = 0;
    if ( a )
    {
      v27 = a;
      do
      {
        v28 = BN_num_bits(v27);
        v29 = size;
        v30 = v62;
        v31 = (v28 + 7) / 8;
        v76[size] = v31;
        ++v29;
        v62 = v30 + v31 + 2;
        v27 = *(&a + v29);
        size = v29;
      }
      while ( v27 );
    }
    v32 = s->s3;
    v33 = v32->tmp.new_cipher;
    if ( (v33->algorithm_auth & 4) != 0 || (v33->algorithm_mkey & 0x100) != 0 )
    {
      v37 = 0;
      v67 = 0;
      v35 = 0;
    }
    else
    {
      sign_pkey = ssl_get_sign_pkey(s, v32->tmp.new_cipher);
      v35 = sign_pkey;
      v67 = sign_pkey;
      if ( !sign_pkey )
      {
        v36 = 50;
f_err_6:
        ssl3_send_alert(s, 2, v36);
err_225:
        if ( buf )
          CRYPTO_free(buf);
        goto LABEL_101;
      }
      v37 = EVP_PKEY_size(sign_pkey);
    }
    if ( !BUF_MEM_grow_clean(str, v37 + v62 + 4) )
    {
      ERR_put_error(0x14u, 155, 7, ".\\ssl\\s3_srvr.c", 1712);
      goto err_225;
    }
    data = (buf_mem_st *)s->init_buf->data;
    v39 = 0;
    str = data;
    p_data = (unsigned __int8 *)&data->data;
    size = 0;
    if ( a )
    {
      do
      {
        *p_data = BYTE1(v76[v39]);
        p_data[1] = v76[size];
        v41 = p_data + 2;
        BN_bn2bin(*(&a + size), v41);
        p_data = &v41[v76[size++]];
        v39 = size;
      }
      while ( *(&a + size) );
    }
    if ( (v75 & 0x80u) != 0 )
    {
      v42 = v73;
      v43 = count;
      v44 = buf;
      *p_data = 3;
      v45 = p_data + 1;
      *v45++ = 0;
      *v45++ = v42;
      *v45++ = v43;
      memcpy(v45, v44, v43);
      CRYPTO_free(v44);
      v35 = v67;
      p_data = &v45[v43];
      data = str;
      buf = 0;
    }
    if ( (v75 & 0x100) != 0 )
    {
      *p_data = (unsigned __int16)strlen(s->ctx->psk_identity_hint) >> 8;
      p_data[1] = strlen(s->ctx->psk_identity_hint);
      v46 = p_data + 2;
      strncpy(v46, (unsigned __int8 *)s->ctx->psk_identity_hint, strlen(s->ctx->psk_identity_hint));
      v35 = v67;
      p_data = &v46[strlen(s->ctx->psk_identity_hint)];
    }
    if ( v35 )
    {
      type = v35->type;
      if ( v35->type == 6 )
      {
        v48 = md;
        count = 0;
        for ( i = 2; i > 0; --i )
        {
          if ( i == 2 )
            md5 = s->ctx->md5;
          else
            md5 = s->ctx->sha1;
          EVP_DigestInit_ex(&ctx, md5, 0);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          EVP_DigestFinal_ex((unsigned int)s, &ctx, v48, &size);
          count += size;
          v48 += size;
        }
        if ( RSA_sign(0x72u, md, count, p_data + 2, &siglen, v67->pkey.rsa) <= 0 )
        {
          ERR_put_error(0x14u, 155, 4, ".\\ssl\\s3_srvr.c", 1786);
          goto err_225;
        }
        data = str;
        *p_data = BYTE1(siglen);
        v51 = v62;
        p_data[1] = siglen;
        v62 = v51 + siglen + 2;
      }
      else
      {
        if ( type == 116 )
        {
          v55 = EVP_dss1();
          EVP_DigestInit_ex(&ctx, v55, 0);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          if ( !EVP_SignFinal(&ctx, p_data + 2, &size, v35) )
          {
            ERR_put_error(0x14u, 155, 10, ".\\ssl\\s3_srvr.c", 1805);
            goto err_225;
          }
        }
        else
        {
          if ( type != 408 )
          {
            v59 = 1835;
            v58 = 251;
            goto LABEL_97;
          }
          v56 = EVP_ecdsa();
          EVP_DigestInit_ex(&ctx, v56, 0);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          EVP_DigestUpdate(&ctx);
          if ( !EVP_SignFinal(&ctx, p_data + 2, &size, v35) )
          {
            ERR_put_error(0x14u, 155, 42, ".\\ssl\\s3_srvr.c", 1824);
            goto err_225;
          }
        }
        *p_data = BYTE1(size);
        v57 = v62;
        p_data[1] = size;
        v62 = v57 + size + 2;
      }
    }
    v52 = v62;
    LOBYTE(data->length) = 12;
    v53 = (char *)&data->length + 1;
    v53[2] = v52;
    *v53 = BYTE2(v52);
    v53[1] = BYTE1(v52);
    s->init_num = v52 + 4;
    s->init_off = 0;
LABEL_87:
    s->state = 8529;
    EVP_MD_CTX_cleanup((unsigned int)s, &ctx);
    return ssl3_do_write(s, 22);
  }
  ERR_put_error(0x14u, 155, 68, ".\\ssl\\s3_srvr.c", 1509);
LABEL_101:
  BN_CTX_free(v64);
  EVP_MD_CTX_cleanup((unsigned int)s, &ctx);
  return -1;
}
