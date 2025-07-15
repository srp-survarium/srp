unsigned int __cdecl ssl3_get_cert_status(ssl_st *s)
{
  ssl_st *v1; // edi
  unsigned int result; // eax
  int v3; // esi
  _BYTE *init_msg; // ebx
  char v5; // cl
  unsigned __int8 *v6; // ebx
  unsigned int v7; // esi
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // eax
  ssl_ctx_st *ctx; // eax
  int (__cdecl *tlsext_status_cb)(ssl_st *, void *); // ecx
  int v12; // eax
  int v13; // [esp-Ch] [ebp-10h]

  v1 = s;
  result = s->method->ssl_get_message(s, 4592, 4593, 22, 0x4000, (int *)&s);
  if ( s )
  {
    if ( result < 4 )
    {
      v3 = 50;
      ERR_put_error(0x14u, 289, 159, ".\\ssl\\s3_clnt.c", 1916);
LABEL_18:
      ssl3_send_alert(v1, 2, v3);
      return -1;
    }
    init_msg = v1->init_msg;
    v5 = *init_msg;
    v6 = init_msg + 1;
    if ( v5 != 1 )
    {
      v3 = 50;
      ERR_put_error(0x14u, 289, 329, ".\\ssl\\s3_clnt.c", 1923);
      goto LABEL_18;
    }
    v7 = v6[2] | ((v6[1] | (*v6 << 8)) << 8);
    v8 = v6 + 3;
    if ( v7 + 4 != result )
    {
      v3 = 50;
      ERR_put_error(0x14u, 289, 159, ".\\ssl\\s3_clnt.c", 1930);
      goto LABEL_18;
    }
    if ( v1->tlsext_ocsp_resp )
      CRYPTO_free(v1->tlsext_ocsp_resp);
    BUF_memdup(v8, v7);
    v1->tlsext_ocsp_resp = v9;
    if ( !v9 )
    {
      v13 = 1939;
LABEL_17:
      v3 = 80;
      ERR_put_error(0x14u, 289, 65, ".\\ssl\\s3_clnt.c", v13);
      goto LABEL_18;
    }
    ctx = v1->ctx;
    v1->tlsext_ocsp_resplen = v7;
    tlsext_status_cb = ctx->tlsext_status_cb;
    if ( tlsext_status_cb )
    {
      v12 = tlsext_status_cb(v1, ctx->tlsext_status_arg);
      if ( !v12 )
      {
        v3 = 113;
        ERR_put_error(0x14u, 289, 328, ".\\ssl\\s3_clnt.c", 1950);
        goto LABEL_18;
      }
      if ( v12 < 0 )
      {
        v13 = 1956;
        goto LABEL_17;
      }
    }
    return 1;
  }
  return result;
}
