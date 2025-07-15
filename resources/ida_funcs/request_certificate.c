int __usercall request_certificate@<eax>(ssl_st *s@<esi>)
{
  unsigned __int8 *ccl; // ebp
  bool v2; // zf
  char *data; // edi
  char *v4; // edi
  int v6; // eax
  char *v7; // edi
  int v8; // eax
  int init_num; // ecx
  int v10; // eax
  void (__cdecl *msg_callback)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  char v12; // cl
  unsigned __int8 *v13; // edi
  int v14; // eax
  unsigned __int8 *v15; // edi
  char *v16; // ebx
  unsigned int v17; // edi
  int v18; // eax
  int v19; // edi
  void (__cdecl *v20)(int, int, int, const void *, unsigned int, ssl_st *, void *); // eax
  ssl2_state_st *s2; // edx
  x509_st *v22; // ebx
  stack_st *v23; // eax
  stack_st_X509 *v24; // edi
  int v25; // eax
  unsigned __int8 *v26; // edi
  cert_st *cert; // ecx
  evp_pkey_st *pubkey; // edi
  int v29; // ebx
  int v30; // [esp-8h] [ebp-40h]
  int v31; // [esp+8h] [ebp-30h]
  x509_st *a; // [esp+Ch] [ebp-2Ch]
  unsigned __int8 *in; // [esp+10h] [ebp-28h] BYREF
  stack_st *st; // [esp+14h] [ebp-24h]
  unsigned int v35; // [esp+18h] [ebp-20h]
  unsigned __int8 *out; // [esp+1Ch] [ebp-1Ch] BYREF
  env_md_ctx_st ctx; // [esp+20h] [ebp-18h] BYREF

  ccl = s->s2->tmp.ccl;
  v2 = s->state == 8304;
  v31 = -1;
  a = 0;
  st = 0;
  if ( v2 )
  {
    data = s->init_buf->data;
    *data = 7;
    v4 = data + 1;
    *v4 = 1;
    if ( RAND_pseudo_bytes() <= 0 )
      return -1;
    *(_DWORD *)(v4 + 1) = *(_DWORD *)ccl;
    *(_DWORD *)(v4 + 5) = *((_DWORD *)ccl + 1);
    *(_DWORD *)(v4 + 9) = *((_DWORD *)ccl + 2);
    *(_DWORD *)(v4 + 13) = *((_DWORD *)ccl + 3);
    s->state = 8305;
    s->init_num = 18;
    s->init_off = 0;
  }
  if ( s->state != 8305 )
  {
LABEL_8:
    if ( s->state == 8306 )
    {
      v7 = s->init_buf->data;
      v8 = ssl2_read(s, &v7[s->init_num], 6 - s->init_num);
      init_num = s->init_num;
      if ( v8 < 3 - init_num )
      {
LABEL_10:
        v6 = ssl2_part_read(s, 0x71u, v8);
        goto LABEL_11;
      }
      v10 = init_num + v8;
      s->init_num = v10;
      if ( v10 >= 3 && !*v7 )
      {
        if ( v7[1] != 2 )
        {
          s->init_num = v10 - 3;
          v31 = ssl2_part_read(s, 0x71u, 3);
          goto end_15;
        }
        msg_callback = s->msg_callback;
        if ( msg_callback )
          msg_callback(0, s->version, 0, v7 + 2, 3u, s, s->msg_callback_arg);
        if ( (s->verify_mode & 2) != 0 )
        {
          ssl2_return_error(s, 4);
          ERR_put_error(0x14u, 113, 199, ".\\ssl\\s2_srvr.c", 989);
          goto end_15;
        }
LABEL_45:
        v31 = 1;
        goto end_15;
      }
      v12 = *v7;
      v13 = (unsigned __int8 *)(v7 + 1);
      if ( v12 != 8 || v10 < 6 )
      {
        ssl2_return_error(s, 0);
        ERR_put_error(0x14u, 113, 219, ".\\ssl\\s2_srvr.c", 998);
        goto end_15;
      }
      if ( v10 != 6 )
      {
        ERR_put_error(0x14u, 113, 68, ".\\ssl\\s2_srvr.c", 1003);
        goto end_15;
      }
      v14 = *v13;
      v15 = v13 + 1;
      if ( v14 != 1 )
      {
        ssl2_return_error(s, 6);
        ERR_put_error(0x14u, 113, 117, ".\\ssl\\s2_srvr.c", 1013);
        goto end_15;
      }
      s->s2->tmp.clen = v15[1] | (*v15 << 8);
      s->s2->tmp.rlen = v15[3] | (v15[2] << 8);
      s->state = 8307;
    }
    v16 = s->init_buf->data;
    v17 = s->s2->tmp.rlen + s->s2->tmp.clen + 6;
    v35 = v17;
    if ( v17 > 0x3FFF )
    {
      ERR_put_error(0x14u, 113, 296, ".\\ssl\\s2_srvr.c", 1026);
      goto end_15;
    }
    v18 = s->init_num;
    v19 = v17 - v18;
    v8 = ssl2_read(s, &v16[v18], v19);
    if ( v8 < v19 )
      goto LABEL_10;
    v20 = s->msg_callback;
    if ( v20 )
      v20(0, s->version, 0, v16, v35, s, s->msg_callback_arg);
    s2 = s->s2;
    in = (unsigned __int8 *)(v16 + 6);
    v22 = d2i_X509(0, (const unsigned __int8 **)&in, s2->tmp.clen);
    a = v22;
    if ( !v22 )
    {
      ERR_put_error(0x14u, 113, 11, ".\\ssl\\s2_srvr.c", 1044);
      goto msg_end;
    }
    v23 = sk_new_null();
    v24 = (stack_st_X509 *)v23;
    st = v23;
    if ( v23 && sk_push(v23, (char *)v22) )
    {
      if ( ssl_verify_cert_chain(s, v24) <= 0 )
        goto msg_end;
      EVP_MD_CTX_init(&ctx);
      EVP_DigestInit_ex(&ctx, s->ctx->rsa_md5, 0);
      EVP_DigestUpdate(&ctx);
      EVP_DigestUpdate(&ctx);
      v25 = i2d_X509(s->cert->pkeys[0].x509, 0);
      v26 = (unsigned __int8 *)CRYPTO_malloc(v25, ".\\ssl\\s2_srvr.c", 1068);
      if ( v26 )
      {
        cert = s->cert;
        out = v26;
        i2d_X509(cert->pkeys[0].x509, &out);
        EVP_DigestUpdate(&ctx);
        CRYPTO_free(v26);
        pubkey = X509_get_pubkey(v22);
        if ( !pubkey )
          goto end_15;
        v29 = EVP_VerifyFinal(&ctx, in, s->s2->tmp.rlen, pubkey);
        EVP_PKEY_free(pubkey);
        EVP_MD_CTX_cleanup((unsigned int)pubkey, &ctx);
        if ( v29 > 0 )
        {
          if ( s->session->peer )
            X509_free(s->session->peer);
          s->session->peer = a;
          CRYPTO_add_lock(&a->references, 1, 3, ".\\ssl\\s2_srvr.c", 1090);
          s->session->verify_result = s->verify_result;
          goto LABEL_45;
        }
        ERR_put_error(0x14u, 113, 104, ".\\ssl\\s2_srvr.c", 1097);
msg_end:
        ssl2_return_error(s, 4);
        goto end_15;
      }
      v30 = 1071;
    }
    else
    {
      v30 = 1050;
    }
    ERR_put_error(0x14u, 113, 65, ".\\ssl\\s2_srvr.c", v30);
    goto msg_end;
  }
  v6 = ssl2_do_write(s);
  if ( v6 > 0 )
  {
    s->init_num = 0;
    s->state = 8306;
    goto LABEL_8;
  }
LABEL_11:
  v31 = v6;
end_15:
  sk_free(st);
  X509_free(a);
  return v31;
}
