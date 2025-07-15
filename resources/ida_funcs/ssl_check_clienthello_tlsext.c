int __cdecl ssl_check_clienthello_tlsext(ssl_st *s)
{
  ssl_ctx_st *ctx; // eax
  int v2; // edi
  int (__cdecl *tlsext_servername_callback)(ssl_st *, int *, void *); // ecx
  ssl_ctx_st *v4; // eax
  int (__cdecl *tlsext_status_cb)(ssl_st *, void *); // ecx
  int v6; // eax
  int v7; // eax
  int desc; // [esp+8h] [ebp-4h] BYREF

  ctx = s->ctx;
  v2 = 3;
  desc = 112;
  if ( ctx && (tlsext_servername_callback = ctx->tlsext_servername_callback) != 0
    || (ctx = s->initial_ctx) != 0 && (tlsext_servername_callback = ctx->tlsext_servername_callback) != 0 )
  {
    v2 = tlsext_servername_callback(s, &desc, ctx->tlsext_servername_arg);
  }
  if ( s->tlsext_status_type == -1 || (v4 = s->ctx) == 0 || (tlsext_status_cb = v4->tlsext_status_cb) == 0 )
  {
LABEL_12:
    s->tlsext_status_expected = 0;
    goto err_242;
  }
  v6 = tlsext_status_cb(s, v4->tlsext_status_arg);
  if ( v6 )
  {
    v7 = v6 - 2;
    if ( v7 )
    {
      if ( v7 != 1 )
        goto err_242;
      goto LABEL_12;
    }
    v2 = 2;
    desc = 80;
  }
  else
  {
    s->tlsext_status_expected = s->tlsext_ocsp_resp != 0;
  }
err_242:
  switch ( v2 )
  {
    case 1:
      ssl3_send_alert(s, 1, desc);
      break;
    case 2:
      ssl3_send_alert(s, 2, desc);
      return -1;
    case 3:
      s->servername_done = 0;
      return 1;
  }
  return 1;
}
