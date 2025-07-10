int __cdecl ssl3_get_key_exchange(ssl_st *s)
{
  int (__cdecl *ssl_get_message)(ssl_st *, int, int, int, int, int *); // eax
  int result; // eax
  int v3; // ebx
  ssl3_state_st *s3; // eax
  sess_cert_st *sess_cert; // eax
  unsigned __int8 *init_msg; // esi
  rsa_st *peer_rsa_tmp; // eax
  sess_cert_st *v8; // ecx
  sess_cert_st *v9; // edx
  const ssl_cipher_st *new_cipher; // eax
  signed int v11; // ebp
  unsigned __int8 *v12; // esi
  ssl_ctx_st *v13; // edx
  int v14; // eax
  int v15; // ebp
  const unsigned __int8 *v16; // esi
  bignum_st *v17; // eax
  const unsigned __int8 *v18; // esi
  int v19; // eax
  int v20; // ebp
  const unsigned __int8 *v21; // esi
  bignum_st *v22; // eax
  const unsigned __int8 *v23; // esi
  ec_group_st *v24; // ebx
  unsigned __int8 *v25; // esi
  int v26; // eax
  int type; // eax
  int i; // ebx
  const env_md_st *md5; // eax
  int v30; // eax
  int v31; // ebp
  const unsigned __int8 *v32; // esi
  bignum_st *v33; // eax
  const unsigned __int8 *v34; // esi
  int v35; // eax
  int v36; // ebp
  const unsigned __int8 *v37; // esi
  bignum_st *v38; // eax
  const unsigned __int8 *v39; // esi
  int v40; // eax
  int v41; // ebp
  const unsigned __int8 *v42; // esi
  bignum_st *v43; // eax
  x509_st *x509; // edx
  int v45; // eax
  const ec_group_st *v46; // eax
  ec_group_st *v47; // ebp
  ec_group_st *v48; // ebp
  bool v49; // zf
  unsigned __int8 *v50; // esi
  bignum_ctx *v51; // eax
  const unsigned __int8 *v52; // esi
  x509_st *v53; // edx
  signed int v54; // eax
  const env_md_st *v55; // eax
  const env_md_st *v56; // eax
  bignum_ctx *v57; // [esp-10h] [ebp-170h]
  int max_cert_list; // [esp-8h] [ebp-168h]
  unsigned int len; // [esp+Ch] [ebp-154h]
  unsigned int lena; // [esp+Ch] [ebp-154h]
  unsigned int lenb; // [esp+Ch] [ebp-154h]
  unsigned int lenc; // [esp+Ch] [ebp-154h]
  unsigned int size; // [esp+10h] [ebp-150h] BYREF
  evp_pkey_st *pkey; // [esp+14h] [ebp-14Ch]
  rsa_st *r; // [esp+18h] [ebp-148h]
  unsigned __int8 *md; // [esp+1Ch] [ebp-144h]
  ec_key_st *key; // [esp+20h] [ebp-140h]
  dh_st *v68; // [esp+24h] [ebp-13Ch]
  ec_point_st *point; // [esp+28h] [ebp-138h]
  bignum_ctx *v70; // [esp+2Ch] [ebp-134h]
  void *data; // [esp+30h] [ebp-130h]
  ec_group_st *group; // [esp+34h] [ebp-12Ch]
  env_md_ctx_st ctx; // [esp+38h] [ebp-128h] BYREF
  int v74; // [esp+50h] [ebp-110h]
  int v75; // [esp+54h] [ebp-10Ch] BYREF
  char dst[132]; // [esp+58h] [ebp-108h] BYREF
  unsigned __int8 m[128]; // [esp+DCh] [ebp-84h] BYREF

  ssl_get_message = s->method->ssl_get_message;
  max_cert_list = s->max_cert_list;
  pkey = 0;
  r = 0;
  v68 = 0;
  key = 0;
  v70 = 0;
  point = 0;
  result = ssl_get_message(s, 4416, 4417, -1, max_cert_list, &v75);
  v3 = result;
  if ( !v75 )
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
  data = init_msg;
  if ( sess_cert )
  {
    peer_rsa_tmp = sess_cert->peer_rsa_tmp;
    if ( peer_rsa_tmp )
    {
      RSA_free((unsigned int)s, peer_rsa_tmp);
      s->session->sess_cert->peer_rsa_tmp = 0;
    }
    v8 = s->session->sess_cert;
    if ( v8->peer_dh_tmp )
    {
      DH_free((unsigned int)s, v8->peer_dh_tmp);
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
  md = (unsigned __int8 *)new_cipher->algorithm_auth;
  EVP_MD_CTX_init(&ctx);
  v74 = len & 0x100;
  if ( (len & 0x100) != 0 )
  {
    v11 = init_msg[1] | (*init_msg << 8);
    v12 = init_msg + 2;
    lena = 40;
    size = v11;
    data = (void *)(v11 + 2);
    if ( v11 > 128 )
    {
      ERR_put_error(0x14u, 141, 146, ".\\ssl\\s3_clnt.c", 1255);
LABEL_121:
      ssl3_send_alert(s, 2, lena);
      goto err_218;
    }
    if ( v11 + 2 > v3 )
    {
      lena = 50;
      ERR_put_error(0x14u, 141, 316, ".\\ssl\\s3_clnt.c", 1262);
      goto LABEL_121;
    }
    memcpy((unsigned __int8 *)dst, v12, v11);
    memset((int)&dst[v11], 0, 129 - v11);
    v13 = s->ctx;
    if ( v13->psk_identity_hint )
      CRYPTO_free(v13->psk_identity_hint);
    s->ctx->psk_identity_hint = BUF_strdup(dst);
    if ( !s->ctx->psk_identity_hint )
    {
      ERR_put_error(0x14u, 141, 65, ".\\ssl\\s3_clnt.c", 1276);
      goto LABEL_121;
    }
    v3 -= (int)data;
    goto LABEL_26;
  }
  if ( (len & 1) == 0 )
  {
    if ( (len & 8) != 0 )
    {
      v68 = DH_new();
      if ( !v68 )
      {
        ERR_put_error(0x14u, 141, 5, ".\\ssl\\s3_clnt.c", 1344);
        goto err_218;
      }
      v30 = init_msg[1] | (*init_msg << 8);
      v31 = v30 + 2;
      v32 = init_msg + 2;
      size = v30;
      if ( v30 + 2 > v3 )
      {
        lena = 50;
        ERR_put_error(0x14u, 141, 110, ".\\ssl\\s3_clnt.c", 1352);
        goto LABEL_121;
      }
      v33 = BN_bin2bn(v32, v30, 0);
      v68->p = v33;
      if ( !v33 )
      {
        ERR_put_error(0x14u, 141, 3, ".\\ssl\\s3_clnt.c", 1357);
        goto err_218;
      }
      v34 = &v32[size];
      v35 = v34[1] | (*v34 << 8);
      v36 = v35 + v31 + 2;
      v37 = v34 + 2;
      size = v35;
      if ( v36 > v3 )
      {
        lena = 50;
        ERR_put_error(0x14u, 141, 108, ".\\ssl\\s3_clnt.c", 1367);
        goto LABEL_121;
      }
      v38 = BN_bin2bn(v37, v35, 0);
      v68->g = v38;
      if ( !v38 )
      {
        ERR_put_error(0x14u, 141, 3, ".\\ssl\\s3_clnt.c", 1372);
        goto err_218;
      }
      v39 = &v37[size];
      v40 = v39[1] | (*v39 << 8);
      v41 = v40 + v36 + 2;
      v42 = v39 + 2;
      size = v40;
      if ( v41 > v3 )
      {
        lena = 50;
        ERR_put_error(0x14u, 141, 109, ".\\ssl\\s3_clnt.c", 1382);
        goto LABEL_121;
      }
      v43 = BN_bin2bn(v42, v40, 0);
      v68->pub_key = v43;
      if ( !v43 )
      {
        ERR_put_error(0x14u, 141, 3, ".\\ssl\\s3_clnt.c", 1387);
        goto err_218;
      }
      v23 = &v42[size];
      v3 -= v41;
      if ( ((unsigned __int8)md & 1) != 0 )
      {
        x509 = s->session->sess_cert->peer_pkeys[0].x509;
      }
      else
      {
        if ( ((unsigned __int8)md & 2) == 0 )
        {
LABEL_73:
          s->session->sess_cert->peer_dh_tmp = v68;
          v68 = 0;
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
      ERR_put_error(0x14u, 141, 235, ".\\ssl\\s3_clnt.c", 1412);
      goto LABEL_121;
    }
    if ( (len & 0x80u) == 0 )
    {
      if ( len )
      {
        lena = 10;
        ERR_put_error(0x14u, 141, 244, ".\\ssl\\s3_clnt.c", 1521);
        goto LABEL_121;
      }
      goto LABEL_26;
    }
    key = EC_KEY_new();
    if ( !key )
    {
      ERR_put_error(0x14u, 141, 65, ".\\ssl\\s3_clnt.c", 1425);
      goto err_218;
    }
    if ( v3 < 3 || *init_msg != 3 || (v45 = tls1_ec_curve_id2nid(init_msg[2])) == 0 )
    {
      lena = 80;
      ERR_put_error(0x14u, 141, 314, ".\\ssl\\s3_clnt.c", 1444);
      goto LABEL_121;
    }
    v46 = EC_GROUP_new_by_curve_name(v45);
    v47 = (ec_group_st *)v46;
    if ( !v46 )
    {
      ERR_put_error(0x14u, 141, 16, ".\\ssl\\s3_clnt.c", 1451);
      goto err_218;
    }
    if ( !EC_KEY_set_group(key, v46) )
    {
      ERR_put_error(0x14u, 141, 16, ".\\ssl\\s3_clnt.c", 1456);
      goto err_218;
    }
    EC_GROUP_free(v47);
    v48 = (ec_group_st *)EVP_CIPHER_block_size((const env_md_st *)key);
    v49 = (s->s3->tmp.new_cipher->algo_strength & 2) == 0;
    group = v48;
    if ( !v49 && EC_GROUP_get_degree(v48) > 163 )
    {
      lena = 60;
      ERR_put_error(0x14u, 141, 310, ".\\ssl\\s3_clnt.c", 1467);
      goto LABEL_121;
    }
    v50 = init_msg + 3;
    point = EC_POINT_new(v48);
    if ( !point || (v51 = BN_CTX_new(), (v70 = v51) == 0) )
    {
      ERR_put_error(0x14u, 141, 65, ".\\ssl\\s3_clnt.c", 1477);
      goto err_218;
    }
    lenc = *v50;
    v52 = v50 + 1;
    if ( (int)(lenc + 4) > v3 || !EC_POINT_oct2point(group, point, v52, lenc, v51) )
    {
      lena = 50;
      ERR_put_error(0x14u, 141, 306, ".\\ssl\\s3_clnt.c", 1489);
      goto LABEL_121;
    }
    v23 = &v52[lenc];
    v3 -= lenc + 4;
    if ( ((unsigned __int8)md & 1) != 0 )
    {
      v53 = s->session->sess_cert->peer_pkeys[0].x509;
    }
    else
    {
      if ( ((unsigned __int8)md & 0x40) == 0 )
      {
LABEL_97:
        EC_KEY_set_public_key(key, point);
        v57 = v70;
        s->session->sess_cert->peer_ecdh_tmp = key;
        key = 0;
        BN_CTX_free(v57);
        v70 = 0;
        EC_POINT_free(point);
        point = 0;
        goto LABEL_44;
      }
      v53 = s->session->sess_cert->peer_pkeys[5].x509;
    }
    pkey = X509_get_pubkey(v53);
    goto LABEL_97;
  }
  r = RSA_new();
  if ( !r )
  {
    ERR_put_error(0x14u, 141, 65, ".\\ssl\\s3_clnt.c", 1290);
    goto err_218;
  }
  v14 = init_msg[1] | (*init_msg << 8);
  v15 = v14 + 2;
  v16 = init_msg + 2;
  size = v14;
  if ( v14 + 2 > v3 )
  {
    lena = 50;
    ERR_put_error(0x14u, 141, 121, ".\\ssl\\s3_clnt.c", 1298);
    goto LABEL_121;
  }
  v17 = BN_bin2bn(v16, v14, r->n);
  r->n = v17;
  if ( !v17 )
  {
    ERR_put_error(0x14u, 141, 3, ".\\ssl\\s3_clnt.c", 1303);
    goto err_218;
  }
  v18 = &v16[size];
  v19 = v18[1] | (*v18 << 8);
  v20 = v19 + v15 + 2;
  v21 = v18 + 2;
  size = v19;
  if ( v20 > v3 )
  {
    lena = 50;
    ERR_put_error(0x14u, 141, 120, ".\\ssl\\s3_clnt.c", 1313);
    goto LABEL_121;
  }
  v22 = BN_bin2bn(v21, v19, r->e);
  r->e = v22;
  if ( !v22 )
  {
    ERR_put_error(0x14u, 141, 3, ".\\ssl\\s3_clnt.c", 1318);
    goto err_218;
  }
  v23 = &v21[size];
  v3 -= v20;
  if ( ((unsigned __int8)md & 1) == 0 )
  {
    ERR_put_error(0x14u, 141, 68, ".\\ssl\\s3_clnt.c", 1329);
    goto err_218;
  }
  pkey = X509_get_pubkey(s->session->sess_cert->peer_pkeys[0].x509);
  s->session->sess_cert->peer_rsa_tmp = r;
  r = 0;
LABEL_44:
  if ( pkey )
  {
    v24 = (ec_group_st *)(v3 - 2);
    size = v23[1] | (*v23 << 8);
    v25 = (unsigned __int8 *)(v23 + 2);
    group = v24;
    v26 = EVP_PKEY_size(pkey);
    if ( (ec_group_st *)size != v24 || (int)v24 > v26 || (int)v24 <= 0 )
    {
      lena = 50;
      ERR_put_error(0x14u, 141, 264, ".\\ssl\\s3_clnt.c", 1540);
      goto LABEL_121;
    }
    type = pkey->type;
    if ( pkey->type == 6 )
    {
      lenb = 0;
      md = m;
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
        EVP_DigestFinal_ex((unsigned int)s, &ctx, md, &size);
        md += size;
        lenb += size;
      }
      v54 = RSA_verify(0x72u, m, lenb, v25, (unsigned int)group, pkey->pkey.rsa);
      size = v54;
      if ( v54 < 0 )
      {
        lena = 51;
        ERR_put_error(0x14u, 141, 118, ".\\ssl\\s3_clnt.c", 1567);
        goto LABEL_121;
      }
      if ( !v54 )
      {
        lena = 51;
        ERR_put_error(0x14u, 141, 123, ".\\ssl\\s3_clnt.c", 1574);
        goto LABEL_121;
      }
    }
    else if ( type == 116 )
    {
      v55 = EVP_dss1();
      EVP_DigestInit_ex(&ctx, v55, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      if ( EVP_VerifyFinal(&ctx, v25, (unsigned int)v24, pkey) <= 0 )
      {
        lena = 51;
        ERR_put_error(0x14u, 141, 123, ".\\ssl\\s3_clnt.c", 1592);
        goto LABEL_121;
      }
    }
    else
    {
      if ( type != 408 )
      {
        ERR_put_error(0x14u, 141, 68, ".\\ssl\\s3_clnt.c", 1617);
        goto err_218;
      }
      v56 = EVP_ecdsa();
      EVP_DigestInit_ex(&ctx, v56, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      if ( EVP_VerifyFinal(&ctx, v25, (unsigned int)v24, pkey) <= 0 )
      {
        lena = 51;
        ERR_put_error(0x14u, 141, 123, ".\\ssl\\s3_clnt.c", 1610);
        goto LABEL_121;
      }
    }
LABEL_119:
    EVP_PKEY_free(pkey);
    EVP_MD_CTX_cleanup((unsigned int)s, &ctx);
    return 1;
  }
LABEL_26:
  if ( ((unsigned __int8)md & 4) != 0 || v74 )
  {
    if ( v3 )
    {
      lena = 50;
      ERR_put_error(0x14u, 141, 153, ".\\ssl\\s3_clnt.c", 1633);
      goto LABEL_121;
    }
    goto LABEL_119;
  }
  ERR_put_error(0x14u, 141, 68, ".\\ssl\\s3_clnt.c", 1626);
err_218:
  EVP_PKEY_free(pkey);
  if ( r )
    RSA_free((unsigned int)s, r);
  if ( v68 )
    DH_free((unsigned int)s, v68);
  BN_CTX_free(v70);
  EC_POINT_free(point);
  if ( key )
    EC_KEY_free(key);
  EVP_MD_CTX_cleanup((unsigned int)s, &ctx);
  return -1;
}
