int __usercall request_certificate@<eax>(ssl_st *s@<esi>)
{
  unsigned __int8 *ccl; // ebp
  bool v2; // zf
  int v3; // ebx
  char *data; // edi
  int v5; // edi
  int v7; // eax
  char *v8; // edi
  int v9; // eax
  int init_num; // ecx
  int v11; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  char v13; // cl
  unsigned __int8 *v14; // edi
  int v15; // eax
  unsigned __int8 *v16; // edi
  char *v17; // ebx
  unsigned int v18; // edi
  int v19; // eax
  int v20; // edi
  void (__cdecl *v21)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  ssl2_state_st *s2; // edx
  engine_st *v23; // ebx
  stack_st *v24; // eax
  stack_st_X509 *v25; // edi
  int v26; // eax
  unsigned __int8 *v27; // edi
  cert_st *cert; // ecx
  evp_pkey_st *pubkey; // edi
  int v30; // ebx
  int v31; // [esp-8h] [ebp-40h]
  int v32; // [esp+8h] [ebp-30h]
  x509_st *a; // [esp+Ch] [ebp-2Ch]
  unsigned __int8 *v34; // [esp+10h] [ebp-28h] BYREF
  stack_st *st; // [esp+14h] [ebp-24h]
  unsigned int v36; // [esp+18h] [ebp-20h]
  unsigned __int8 *out; // [esp+1Ch] [ebp-1Ch] BYREF
  env_md_ctx_st ctx; // [esp+20h] [ebp-18h] BYREF

  ccl = s->s2->tmp.ccl;
  v2 = s->state == 8304;
  v32 = -1;
  a = 0;
  st = 0;
  v3 = 8305;
  if ( v2 )
  {
    data = s->init_buf->data;
    *data = 7;
    v5 = (int)(data + 1);
    *(_BYTE *)v5 = 1;
    if ( RAND_pseudo_bytes(v5) <= 0 )
      return -1;
    *(_DWORD *)(v5 + 1) = *(_DWORD *)ccl;
    *(_DWORD *)(v5 + 5) = *((_DWORD *)ccl + 1);
    *(_DWORD *)(v5 + 9) = *((_DWORD *)ccl + 2);
    *(_DWORD *)(v5 + 13) = *((_DWORD *)ccl + 3);
    s->state = 8305;
    s->init_num = 18;
    s->init_off = 0;
  }
  if ( s->state != 8305 )
  {
LABEL_8:
    if ( s->state == 8306 )
    {
      v8 = s->init_buf->data;
      v9 = ssl2_read(s, (unsigned __int8 *)&v8[s->init_num], 6 - s->init_num);
      init_num = s->init_num;
      if ( v9 < 3 - init_num )
      {
LABEL_10:
        v7 = ssl2_part_read(s, 113, v9);
        goto LABEL_11;
      }
      v11 = init_num + v9;
      s->init_num = v11;
      if ( v11 >= 3 && !*v8 )
      {
        LOBYTE(v3) = 2;
        if ( v8[1] != 2 )
        {
          s->init_num = v11 - 3;
          v32 = ssl2_part_read(s, 113, 3);
          goto end_15;
        }
        msg_callback = s->msg_callback;
        if ( msg_callback )
          msg_callback(0, s->version, 0, v8 + 2, 3u, s, s->msg_callback_arg);
        if ( (s->verify_mode & 2) != 0 )
        {
          ssl2_return_error(s, 4);
          ERR_put_error(v3, 0x14u, 113, 199, ".\\ssl\\s2_srvr.c", 989);
          goto end_15;
        }
LABEL_45:
        v32 = 1;
        goto end_15;
      }
      v13 = *v8;
      v14 = (unsigned __int8 *)(v8 + 1);
      if ( v13 != 8 || v11 < 6 )
      {
        ssl2_return_error(s, 0);
        ERR_put_error(8305, 0x14u, 113, 219, ".\\ssl\\s2_srvr.c", 998);
        goto end_15;
      }
      if ( v11 != 6 )
      {
        ERR_put_error(8305, 0x14u, 113, 68, ".\\ssl\\s2_srvr.c", 1003);
        goto end_15;
      }
      v15 = *v14;
      v16 = v14 + 1;
      if ( v15 != 1 )
      {
        ssl2_return_error(s, 6);
        ERR_put_error(8305, 0x14u, 113, 117, ".\\ssl\\s2_srvr.c", 1013);
        goto end_15;
      }
      s->s2->tmp.clen = v16[1] | (*v16 << 8);
      s->s2->tmp.rlen = v16[3] | (v16[2] << 8);
      s->state = 8307;
    }
    v17 = s->init_buf->data;
    v18 = s->s2->tmp.rlen + s->s2->tmp.clen + 6;
    v36 = v18;
    if ( v18 > 0x3FFF )
    {
      ERR_put_error((int)v17, 0x14u, 113, 296, ".\\ssl\\s2_srvr.c", 1026);
      goto end_15;
    }
    v19 = s->init_num;
    v20 = v18 - v19;
    v9 = ssl2_read(s, (unsigned __int8 *)&v17[v19], v20);
    if ( v9 < v20 )
      goto LABEL_10;
    v21 = s->msg_callback;
    if ( v21 )
      v21(0, s->version, 0, v17, v36, s, s->msg_callback_arg);
    s2 = s->s2;
    v34 = (unsigned __int8 *)(v17 + 6);
    v23 = (engine_st *)d2i_X509(0, &v34, (const unsigned __int8 *)s2->tmp.clen);
    a = (x509_st *)v23;
    if ( !v23 )
    {
      ERR_put_error(0, 0x14u, 113, 11, ".\\ssl\\s2_srvr.c", 1044);
      goto msg_end;
    }
    v24 = sk_new_null();
    v25 = (stack_st_X509 *)v24;
    st = v24;
    if ( v24 && sk_push(v24, (char *)v23) )
    {
      if ( ssl_verify_cert_chain(s, v25) <= 0 )
        goto msg_end;
      EVP_MD_CTX_init(&ctx);
      EVP_DigestInit_ex(v23, &ctx, s->ctx->rsa_md5, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      v26 = i2d_X509(s->cert->pkeys[0].x509, 0);
      v27 = (unsigned __int8 *)CRYPTO_malloc(v26, ".\\ssl\\s2_srvr.c", 1068);
      if ( v27 )
      {
        cert = s->cert;
        out = v27;
        i2d_X509(cert->pkeys[0].x509, &out);
        EVP_DigestUpdate(&ctx);
        CRYPTO_free(v27);
        pubkey = X509_get_pubkey((x509_st *)v23);
        if ( !pubkey )
          goto end_15;
        v30 = EVP_VerifyFinal(&ctx, v34, s->s2->tmp.rlen, pubkey);
        EVP_PKEY_free((int)pubkey, pubkey);
        EVP_MD_CTX_cleanup((int)pubkey, v30, &ctx);
        if ( v30 > 0 )
        {
          if ( s->session->peer )
            X509_free(s->session->peer);
          s->session->peer = a;
          CRYPTO_add_lock(&a->references, 1, 3, ".\\ssl\\s2_srvr.c", 1090);
          s->session->verify_result = s->verify_result;
          goto LABEL_45;
        }
        ERR_put_error(v30, 0x14u, 113, 104, ".\\ssl\\s2_srvr.c", 1097);
msg_end:
        ssl2_return_error(s, 4);
        goto end_15;
      }
      v31 = 1071;
    }
    else
    {
      v31 = 1050;
    }
    ERR_put_error((int)v23, 0x14u, 113, 65, ".\\ssl\\s2_srvr.c", v31);
    goto msg_end;
  }
  v7 = ssl2_do_write(s);
  if ( v7 > 0 )
  {
    s->init_num = 0;
    s->state = 8306;
    goto LABEL_8;
  }
LABEL_11:
  v32 = v7;
end_15:
  sk_free(st);
  X509_free(a);
  return v32;
}
