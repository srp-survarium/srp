int __cdecl ssl_check_serverhello_tlsext(ssl_st *s)
{
  bool v1; // zf
  ssl_session_st *session; // eax
  unsigned __int8 *tlsext_ecpointformatlist; // ecx
  const ssl_cipher_st *new_cipher; // eax
  int v5; // eax
  ssl_ctx_st *ctx; // eax
  int v9; // edi
  int (__cdecl *tlsext_servername_callback)(ssl_st *, int *, void *); // ecx
  ssl_ctx_st *v11; // eax
  ssl_ctx_st *v12; // eax
  int v13; // eax
  int desc; // [esp+4h] [ebp-4h] BYREF

  v1 = s->tlsext_ecpointformatlist == 0;
  desc = 112;
  if ( !v1 )
  {
    if ( s->tlsext_ecpointformatlist_length )
    {
      session = s->session;
      tlsext_ecpointformatlist = session->tlsext_ecpointformatlist;
      if ( tlsext_ecpointformatlist )
      {
        if ( session->tlsext_ecpointformatlist_length )
        {
          new_cipher = s->s3->tmp.new_cipher;
          if ( (new_cipher->algorithm_mkey & 0xE0) != 0 || (new_cipher->algorithm_auth & 0x40) != 0 )
          {
            v5 = 0;
            while ( *tlsext_ecpointformatlist++ )
            {
              if ( ++v5 >= s->session->tlsext_ecpointformatlist_length )
              {
                ERR_put_error(0x14u, 280, 157, ".\\ssl\\t1_lib.c", 1492);
                return -1;
              }
            }
          }
        }
      }
    }
  }
  ctx = s->ctx;
  v9 = 0;
  if ( ctx && (tlsext_servername_callback = ctx->tlsext_servername_callback) != 0
    || (ctx = s->initial_ctx) != 0 && (tlsext_servername_callback = ctx->tlsext_servername_callback) != 0 )
  {
    v9 = tlsext_servername_callback(s, &desc, ctx->tlsext_servername_arg);
  }
  if ( s->tlsext_status_type != -1 && !s->tlsext_status_expected )
  {
    v11 = s->ctx;
    if ( v11 )
    {
      if ( v11->tlsext_status_cb )
      {
        if ( s->tlsext_ocsp_resp )
        {
          CRYPTO_free(s->tlsext_ocsp_resp);
          s->tlsext_ocsp_resp = 0;
        }
        v12 = s->ctx;
        s->tlsext_ocsp_resplen = -1;
        v13 = v12->tlsext_status_cb(s, v12->tlsext_status_arg);
        if ( v13 )
        {
          if ( v13 >= 0 )
            goto LABEL_27;
          desc = 80;
        }
        else
        {
          desc = 113;
        }
        v9 = 2;
      }
    }
  }
LABEL_27:
  switch ( v9 )
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
