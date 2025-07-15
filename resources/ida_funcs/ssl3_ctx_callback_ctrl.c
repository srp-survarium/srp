int __cdecl ssl3_ctx_callback_ctrl(ssl_ctx_st *ctx, int cmd, void (__cdecl *fp)())
{
  cert_st *cert; // edx
  int result; // eax

  cert = ctx->cert;
  switch ( cmd )
  {
    case 5:
      cert->rsa_tmp_cb = (rsa_st *(__cdecl *)(ssl_st *, int, int))fp;
      result = 1;
      break;
    case 6:
      cert->dh_tmp_cb = (dh_st *(__cdecl *)(ssl_st *, int, int))fp;
      result = 1;
      break;
    case 7:
      cert->ecdh_tmp_cb = (ec_key_st *(__cdecl *)(ssl_st *, int, int))fp;
      result = 1;
      break;
    case 53:
      ctx->tlsext_servername_callback = (int (__cdecl *)(ssl_st *, int *, void *))fp;
      result = 1;
      break;
    case 63:
      ctx->tlsext_status_cb = (int (__cdecl *)(ssl_st *, void *))fp;
      result = 1;
      break;
    case 72:
      ctx->tlsext_ticket_key_cb = (int (__cdecl *)(ssl_st *, unsigned __int8 *, unsigned __int8 *, evp_cipher_ctx_st *, hmac_ctx_st *, int))fp;
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
