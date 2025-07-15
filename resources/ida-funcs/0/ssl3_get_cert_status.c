unsigned int __usercall ssl3_get_cert_status@<eax>(int a1@<ebx>, ssl_st *s)
{
  ssl_st *v2; // edi
  unsigned int result; // eax
  int v4; // esi
  _BYTE *init_msg; // ebx
  char v6; // cl
  unsigned __int8 *v7; // ebx
  unsigned int v8; // esi
  const __m128i *v9; // ebx
  unsigned __int8 *v10; // eax
  ssl_ctx_st *ctx; // eax
  int (__cdecl *tlsext_status_cb)(ssl_st *, void *); // ecx
  int v13; // eax
  int v14; // [esp-Ch] [ebp-10h]

  v2 = s;
  result = s->method->ssl_get_message(s, 4592, 4593, 22, 0x4000, (int *)&s);
  if ( s )
  {
    if ( result < 4 )
    {
      v4 = 50;
      ERR_put_error(a1, 0x14u, 289, 159, ".\\ssl\\s3_clnt.c", 1916);
LABEL_18:
      ssl3_send_alert(v2, 2, v4);
      return -1;
    }
    init_msg = v2->init_msg;
    v6 = *init_msg;
    v7 = init_msg + 1;
    if ( v6 != 1 )
    {
      v4 = 50;
      ERR_put_error((int)v7, 0x14u, 289, 329, ".\\ssl\\s3_clnt.c", 1923);
      goto LABEL_18;
    }
    v8 = v7[2] | ((v7[1] | (*v7 << 8)) << 8);
    v9 = (const __m128i *)(v7 + 3);
    if ( v8 + 4 != result )
    {
      v4 = 50;
      ERR_put_error((int)v9, 0x14u, 289, 159, ".\\ssl\\s3_clnt.c", 1930);
      goto LABEL_18;
    }
    if ( v2->tlsext_ocsp_resp )
      CRYPTO_free(v2->tlsext_ocsp_resp);
    BUF_memdup((int)v9, v9, v8);
    v2->tlsext_ocsp_resp = v10;
    if ( !v10 )
    {
      v14 = 1939;
LABEL_17:
      v4 = 80;
      ERR_put_error((int)v9, 0x14u, 289, 65, ".\\ssl\\s3_clnt.c", v14);
      goto LABEL_18;
    }
    ctx = v2->ctx;
    v2->tlsext_ocsp_resplen = v8;
    tlsext_status_cb = ctx->tlsext_status_cb;
    if ( tlsext_status_cb )
    {
      v13 = tlsext_status_cb(v2, ctx->tlsext_status_arg);
      if ( !v13 )
      {
        v4 = 113;
        ERR_put_error((int)v9, 0x14u, 289, 328, ".\\ssl\\s3_clnt.c", 1950);
        goto LABEL_18;
      }
      if ( v13 < 0 )
      {
        v14 = 1956;
        goto LABEL_17;
      }
    }
    return 1;
  }
  return result;
}
