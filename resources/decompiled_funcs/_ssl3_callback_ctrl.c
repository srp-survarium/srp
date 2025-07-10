int __cdecl ssl3_callback_ctrl(ssl_st *s, int cmd, void (__cdecl *fp)())
{
  int result; // eax

  if ( (cmd == 5 || cmd == 6) && !ssl_cert_inst(&s->cert) )
  {
    ERR_put_error(0x14u, 233, 65, ".\\ssl\\s3_lib.c", 2512);
    return 0;
  }
  else
  {
    switch ( cmd )
    {
      case 5:
        s->cert->rsa_tmp_cb = (rsa_st *(__cdecl *)(ssl_st *, int, int))fp;
        result = 0;
        break;
      case 6:
        s->cert->dh_tmp_cb = (dh_st *(__cdecl *)(ssl_st *, int, int))fp;
        result = 0;
        break;
      case 7:
        s->cert->ecdh_tmp_cb = (ec_key_st *(__cdecl *)(ssl_st *, int, int))fp;
        result = 0;
        break;
      case 56:
        s->tlsext_debug_cb = (void (__cdecl *)(ssl_st *, int, int, unsigned __int8 *, int, void *))fp;
        goto LABEL_10;
      default:
LABEL_10:
        result = 0;
        break;
    }
  }
  return result;
}
