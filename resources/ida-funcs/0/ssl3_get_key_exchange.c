int __cdecl ssl3_get_key_exchange(ssl_st *s)
{
  int (__cdecl *ssl_get_message)(ssl_st *, int, int, int, int, int *); // eax
  int result; // eax
  int i; // ebx
  ssl3_state_st *s3; // eax
  sess_cert_st *sess_cert; // eax
  unsigned __int8 *init_msg; // esi
  rsa_st *peer_rsa_tmp; // eax
  sess_cert_st *v8; // ecx
  sess_cert_st *v9; // edx
  const ssl_cipher_st *new_cipher; // eax
  signed int v11; // ebp
  const __m128i *v12; // esi
  ssl_ctx_st *v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // ebp
  const unsigned __int8 *v16; // esi
  bignum_st *v17; // eax
  const unsigned __int8 *v18; // esi
  unsigned int v19; // eax
  int v20; // ebp
  const unsigned __int8 *v21; // esi
  bignum_st *v22; // eax
  const unsigned __int8 *v23; // esi
  unsigned __int8 *v24; // esi
  int v25; // eax
  int type; // eax
  const env_md_st *md5; // eax
  unsigned int v28; // eax
  unsigned int v29; // ebp
  const unsigned __int8 *v30; // esi
  bignum_st *v31; // eax
  const unsigned __int8 *v32; // esi
  unsigned int v33; // eax
  int v34; // ebp
  const unsigned __int8 *v35; // esi
  bignum_st *v36; // eax
  const unsigned __int8 *v37; // esi
  unsigned int v38; // eax
  int v39; // ebp
  const unsigned __int8 *v40; // esi
  bignum_st *v41; // eax
  x509_st *x509; // edx
  int v43; // eax
  ec_group_st *v44; // eax
  ec_group_st *v45; // ebp
  ec_group_st *v46; // ebp
  bool v47; // zf
  unsigned __int8 *v48; // esi
  bignum_ctx *v49; // eax
  const unsigned __int8 *v50; // esi
  x509_st *v51; // edx
  int v52; // eax
  const env_md_st *v53; // eax
  const env_md_st *v54; // eax
  bignum_ctx *v55; // [esp-10h] [ebp-170h]
  int max_cert_list; // [esp-8h] [ebp-168h]
  unsigned int len; // [esp+Ch] [ebp-154h]
  unsigned int lena; // [esp+Ch] [ebp-154h]
  unsigned int lenb; // [esp+Ch] [ebp-154h]
  unsigned int lenc; // [esp+Ch] [ebp-154h]
  int v61; // [esp+10h] [ebp-150h] BYREF
  evp_pkey_st *pkey; // [esp+14h] [ebp-14Ch]
  rsa_st *v63; // [esp+18h] [ebp-148h]
  unsigned __int8 *algorithm_auth; // [esp+1Ch] [ebp-144h]
  const env_md_st *md; // [esp+20h] [ebp-140h]
  dh_st *v66; // [esp+24h] [ebp-13Ch]
  ec_point_st *point; // [esp+28h] [ebp-138h]
  bignum_ctx *v68; // [esp+2Ch] [ebp-134h]
  int v69; // [esp+30h] [ebp-130h]
  ec_group_st *group; // [esp+34h] [ebp-12Ch]
  env_md_ctx_st ctx; // [esp+38h] [ebp-128h] BYREF
  int v72; // [esp+50h] [ebp-110h]
  int v73; // [esp+54h] [ebp-10Ch] BYREF
  char dst[132]; // [esp+58h] [ebp-108h] BYREF
  unsigned __int8 v75[128]; // [esp+DCh] [ebp-84h] BYREF

  ssl_get_message = s->method->ssl_get_message;
  max_cert_list = s->max_cert_list;
  pkey = 0;
  v63 = 0;
  v66 = 0;
  md = 0;
  v68 = 0;
  point = 0;
  result = ssl_get_message(s, 4416, 4417, -1, max_cert_list, &v73);
  i = result;
  if ( !v73 )
    return result;
  s3 = s->s3;
  if ( s3->tmp.message_type != 12 )
  {
    if ( (s3->tmp.new_cipher->algorithm_mkey & 0x100) != 0 )
    {
      s->session->sess_cert = ssl_sess_cert_new();
      if ( s->ctx->psk_identity_hint )
        CRYPTO_free(s->ctx->psk_identity_hint);
      s->ctx->psk_identity_hint = 0;
    }
    result = 1;
    s->s3->tmp.reuse_message = 1;
    return result;
  }
  sess_cert = s->session->sess_cert;
  init_msg = (unsigned __int8 *)s->init_msg;
  v69 = (int)init_msg;
  if ( sess_cert )
  {
    peer_rsa_tmp = sess_cert->peer_rsa_tmp;
    if ( peer_rsa_tmp )
    {
      RSA_free((int)s, i, peer_rsa_tmp);
      s->session->sess_cert->peer_rsa_tmp = 0;
    }
    v8 = s->session->sess_cert;
    if ( v8->peer_dh_tmp )
    {
      DH_free((int)s, i, v8->peer_dh_tmp);
      s->session->sess_cert->peer_dh_tmp = 0;
    }
    v9 = s->session->sess_cert;
    if ( v9->peer_ecdh_tmp )
    {
      EC_KEY_free(v9->peer_ecdh_tmp);
      s->session->sess_cert->peer_ecdh_tmp = 0;
    }
  }
  else
  {
    s->session->sess_cert = ssl_sess_cert_new();
  }
  new_cipher = s->s3->tmp.new_cipher;
  len = new_cipher->algorithm_mkey;
  algorithm_auth = (unsigned __int8 *)new_cipher->algorithm_auth;
  EVP_MD_CTX_init(&ctx);
  v72 = len & 0x100;
  if ( (len & 0x100) != 0 )
  {
    v11 = init_msg[1] | (*init_msg << 8);
    v12 = (const __m128i *)(init_msg + 2);
    lena = 40;
    v61 = v11;
    v69 = v11 + 2;
    if ( v11 > 128 )
    {
      ERR_put_error(i, 0x14u, 141, 146, ".\\ssl\\s3_clnt.c", 1255);
LABEL_121:
      ssl3_send_alert(s, 2, lena);
      goto err_220;
    }
    if ( v11 + 2 > i )
    {
      lena = 50;
      ERR_put_error(i, 0x14u, 141, 316, ".\\ssl\\s3_clnt.c", 1262);
      goto LABEL_121;
    }
    memcpy((int)dst, v12, v11);
    memset((int)&dst[v11], 0, 129 - v11);
    v13 = s->ctx;
    if ( v13->psk_identity_hint )
      CRYPTO_free(v13->psk_identity_hint);
    s->ctx->psk_identity_hint = BUF_strdup(dst);
    if ( !s->ctx->psk_identity_hint )
    {
      ERR_put_error(i, 0x14u, 141, 65, ".\\ssl\\s3_clnt.c", 1276);
      goto LABEL_121;
    }
    i -= v69;
    goto LABEL_26;
  }
  if ( (len & 1) == 0 )
  {
    if ( (len & 8) != 0 )
    {
      v66 = DH_new(i);
      if ( !v66 )
      {
        ERR_put_error(i, 0x14u, 141, 5, ".\\ssl\\s3_clnt.c", 1344);
        goto err_220;
      }
      v28 = init_msg[1] | (*init_msg << 8);
      v29 = v28 + 2;
      v30 = init_msg + 2;
      v61 = v28;
      if ( (int)(v28 + 2) > i )
      {
        lena = 50;
        ERR_put_error(i, 0x14u, 141, 110, ".\\ssl\\s3_clnt.c", 1352);
        goto LABEL_121;
      }
      v31 = BN_bin2bn(v30, v28, 0);
      v66->p = v31;
      if ( !v31 )
      {
        ERR_put_error(i, 0x14u, 141, 3, ".\\ssl\\s3_clnt.c", 1357);
        goto err_220;
      }
      v32 = &v30[v61];
      v33 = v32[1] | (*v32 << 8);
      v34 = v33 + v29 + 2;
      v35 = v32 + 2;
      v61 = v33;
      if ( v34 > i )
      {
        lena = 50;
        ERR_put_error(i, 0x14u, 141, 108, ".\\ssl\\s3_clnt.c", 1367);
        goto LABEL_121;
      }
      v36 = BN_bin2bn(v35, v33, 0);
      v66->g = v36;
      if ( !v36 )
      {
        ERR_put_error(i, 0x14u, 141, 3, ".\\ssl\\s3_clnt.c", 1372);
        goto err_220;
      }
      v37 = &v35[v61];
      v38 = v37[1] | (*v37 << 8);
      v39 = v38 + v34 + 2;
      v40 = v37 + 2;
      v61 = v38;
      if ( v39 > i )
      {
        lena = 50;
        ERR_put_error(i, 0x14u, 141, 109, ".\\ssl\\s3_clnt.c", 1382);
        goto LABEL_121;
      }
      v41 = BN_bin2bn(v40, v38, 0);
      v66->pub_key = v41;
      if ( !v41 )
      {
        ERR_put_error(i, 0x14u, 141, 3, ".\\ssl\\s3_clnt.c", 1387);
        goto err_220;
      }
      v23 = &v40[v61];
      i -= v39;
      if ( ((unsigned __int8)algorithm_auth & 1) != 0 )
      {
        x509 = s->session->sess_cert->peer_pkeys[0].x509;
      }
      else
      {
        if ( ((unsigned __int8)algorithm_auth & 2) == 0 )
        {
LABEL_73:
          s->session->sess_cert->peer_dh_tmp = v66;
          v66 = 0;
          goto LABEL_44;
        }
        x509 = s->session->sess_cert->peer_pkeys[2].x509;
      }
      pkey = X509_get_pubkey(x509);
      goto LABEL_73;
    }
    if ( (len & 6) != 0 )
    {
      lena = 47;
      ERR_put_error(i, 0x14u, 141, 235, ".\\ssl\\s3_clnt.c", 1412);
      goto LABEL_121;
    }
    if ( (len & 0x80u) == 0 )
    {
      if ( len )
      {
        lena = 10;
        ERR_put_error(i, 0x14u, 141, 244, ".\\ssl\\s3_clnt.c", 1521);
        goto LABEL_121;
      }
      goto LABEL_26;
    }
    md = (const env_md_st *)EC_KEY_new(i);
    if ( !md )
    {
      ERR_put_error(i, 0x14u, 141, 65, ".\\ssl\\s3_clnt.c", 1425);
      goto err_220;
    }
    if ( i < 3 || *init_msg != 3 || (v43 = tls1_ec_curve_id2nid(init_msg[2])) == 0 )
    {
      lena = 80;
      ERR_put_error(i, 0x14u, 141, 314, ".\\ssl\\s3_clnt.c", 1444);
      goto LABEL_121;
    }
    v44 = EC_GROUP_new_by_curve_name(i, v43);
    v45 = v44;
    if ( !v44 )
    {
      ERR_put_error(i, 0x14u, 141, 16, ".\\ssl\\s3_clnt.c", 1451);
      goto err_220;
    }
    if ( !EC_KEY_set_group((ec_key_st *)md, v44) )
    {
      ERR_put_error(i, 0x14u, 141, 16, ".\\ssl\\s3_clnt.c", 1456);
      goto err_220;
    }
    EC_GROUP_free(v45);
    v46 = (ec_group_st *)EVP_CIPHER_block_size(md);
    v47 = (s->s3->tmp.new_cipher->algo_strength & 2) == 0;
    group = v46;
    if ( !v47 && EC_GROUP_get_degree(i, v46) > 163 )
    {
      lena = 60;
      ERR_put_error(i, 0x14u, 141, 310, ".\\ssl\\s3_clnt.c", 1467);
      goto LABEL_121;
    }
    v48 = init_msg + 3;
    point = EC_POINT_new(i, v46);
    if ( !point || (v49 = BN_CTX_new(i), (v68 = v49) == 0) )
    {
      ERR_put_error(i, 0x14u, 141, 65, ".\\ssl\\s3_clnt.c", 1477);
      goto err_220;
    }
    lenc = *v48;
    v50 = v48 + 1;
    if ( (int)(lenc + 4) > i || !EC_POINT_oct2point(i, group, point, v50, lenc, v49) )
    {
      lena = 50;
      ERR_put_error(i, 0x14u, 141, 306, ".\\ssl\\s3_clnt.c", 1489);
      goto LABEL_121;
    }
    v23 = &v50[lenc];
    i -= lenc + 4;
    if ( ((unsigned __int8)algorithm_auth & 1) != 0 )
    {
      v51 = s->session->sess_cert->peer_pkeys[0].x509;
    }
    else
    {
      if ( ((unsigned __int8)algorithm_auth & 0x40) == 0 )
      {
LABEL_97:
        EC_KEY_set_public_key((ec_key_st *)md, point);
        v55 = v68;
        s->session->sess_cert->peer_ecdh_tmp = (ec_key_st *)md;
        md = 0;
        BN_CTX_free(v55);
        v68 = 0;
        EC_POINT_free(point);
        point = 0;
        goto LABEL_44;
      }
      v51 = s->session->sess_cert->peer_pkeys[5].x509;
    }
    pkey = X509_get_pubkey(v51);
    goto LABEL_97;
  }
  v63 = RSA_new(i);
  if ( !v63 )
  {
    ERR_put_error(i, 0x14u, 141, 65, ".\\ssl\\s3_clnt.c", 1290);
    goto err_220;
  }
  v14 = init_msg[1] | (*init_msg << 8);
  v15 = v14 + 2;
  v16 = init_msg + 2;
  v61 = v14;
  if ( (int)(v14 + 2) > i )
  {
    lena = 50;
    ERR_put_error(i, 0x14u, 141, 121, ".\\ssl\\s3_clnt.c", 1298);
    goto LABEL_121;
  }
  v17 = BN_bin2bn(v16, v14, v63->n);
  v63->n = v17;
  if ( !v17 )
  {
    ERR_put_error(i, 0x14u, 141, 3, ".\\ssl\\s3_clnt.c", 1303);
    goto err_220;
  }
  v18 = &v16[v61];
  v19 = v18[1] | (*v18 << 8);
  v20 = v19 + v15 + 2;
  v21 = v18 + 2;
  v61 = v19;
  if ( v20 > i )
  {
    lena = 50;
    ERR_put_error(i, 0x14u, 141, 120, ".\\ssl\\s3_clnt.c", 1313);
    goto LABEL_121;
  }
  v22 = BN_bin2bn(v21, v19, v63->e);
  v63->e = v22;
  if ( !v22 )
  {
    ERR_put_error(i, 0x14u, 141, 3, ".\\ssl\\s3_clnt.c", 1318);
    goto err_220;
  }
  v23 = &v21[v61];
  i -= v20;
  if ( ((unsigned __int8)algorithm_auth & 1) == 0 )
  {
    ERR_put_error(i, 0x14u, 141, 68, ".\\ssl\\s3_clnt.c", 1329);
    goto err_220;
  }
  pkey = X509_get_pubkey(s->session->sess_cert->peer_pkeys[0].x509);
  s->session->sess_cert->peer_rsa_tmp = v63;
  v63 = 0;
LABEL_44:
  if ( pkey )
  {
    i -= 2;
    v61 = v23[1] | (*v23 << 8);
    v24 = (unsigned __int8 *)(v23 + 2);
    group = (ec_group_st *)i;
    v25 = EVP_PKEY_size(pkey);
    if ( v61 != i || i > v25 || i <= 0 )
    {
      lena = 50;
      ERR_put_error(i, 0x14u, 141, 264, ".\\ssl\\s3_clnt.c", 1540);
      goto LABEL_121;
    }
    type = pkey->type;
    if ( pkey->type == 6 )
    {
      lenb = 0;
      algorithm_auth = v75;
      for ( i = 2; i > 0; --i )
      {
        if ( i == 2 )
          md5 = s->ctx->md5;
        else
          md5 = s->ctx->sha1;
        EVP_DigestInit_ex((engine_st *)i, &ctx, md5, 0);
        EVP_DigestUpdate(&ctx);
        EVP_DigestUpdate(&ctx);
        EVP_DigestUpdate(&ctx);
        EVP_DigestFinal_ex((int)s, i, &ctx, algorithm_auth, (unsigned int *)&v61);
        algorithm_auth += v61;
        lenb += v61;
      }
      v52 = RSA_verify(i, (void *)0x72, v75, lenb, v24, (int)group, pkey->pkey.rsa);
      v61 = v52;
      if ( v52 < 0 )
      {
        lena = 51;
        ERR_put_error(i, 0x14u, 141, 118, ".\\ssl\\s3_clnt.c", 1567);
        goto LABEL_121;
      }
      if ( !v52 )
      {
        lena = 51;
        ERR_put_error(i, 0x14u, 141, 123, ".\\ssl\\s3_clnt.c", 1574);
        goto LABEL_121;
      }
    }
    else if ( type == 116 )
    {
      v53 = EVP_dss1();
      EVP_DigestInit_ex((engine_st *)i, &ctx, v53, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      if ( EVP_VerifyFinal(&ctx, v24, i, pkey) <= 0 )
      {
        lena = 51;
        ERR_put_error(i, 0x14u, 141, 123, ".\\ssl\\s3_clnt.c", 1592);
        goto LABEL_121;
      }
    }
    else
    {
      if ( type != 408 )
      {
        ERR_put_error(i, 0x14u, 141, 68, ".\\ssl\\s3_clnt.c", 1617);
        goto err_220;
      }
      v54 = EVP_ecdsa();
      EVP_DigestInit_ex((engine_st *)i, &ctx, v54, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      if ( EVP_VerifyFinal(&ctx, v24, i, pkey) <= 0 )
      {
        lena = 51;
        ERR_put_error(i, 0x14u, 141, 123, ".\\ssl\\s3_clnt.c", 1610);
        goto LABEL_121;
      }
    }
LABEL_119:
    EVP_PKEY_free((int)s, pkey);
    EVP_MD_CTX_cleanup((int)s, i, &ctx);
    return 1;
  }
LABEL_26:
  if ( ((unsigned __int8)algorithm_auth & 4) != 0 || v72 )
  {
    if ( i )
    {
      lena = 50;
      ERR_put_error(i, 0x14u, 141, 153, ".\\ssl\\s3_clnt.c", 1633);
      goto LABEL_121;
    }
    goto LABEL_119;
  }
  ERR_put_error(i, 0x14u, 141, 68, ".\\ssl\\s3_clnt.c", 1626);
err_220:
  EVP_PKEY_free((int)s, pkey);
  if ( v63 )
    RSA_free((int)s, i, v63);
  if ( v66 )
    DH_free((int)s, i, v66);
  BN_CTX_free(v68);
  EC_POINT_free(point);
  if ( md )
    EC_KEY_free((ec_key_st *)md);
  EVP_MD_CTX_cleanup((int)s, i, &ctx);
  return -1;
}
