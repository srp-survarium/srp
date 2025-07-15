BOOL __usercall by_file_ctrl@<eax>(int a1@<ebx>, int a2@<edi>, x509_lookup_st *ctx, int cmd, char *argp, int argl)
{
  BOOL result; // eax
  char *default_cert_file_env; // eax
  char *v8; // eax
  int cert_crl_file; // eax
  BOOL v10; // esi
  char *default_cert_file; // [esp-Ch] [ebp-Ch]

  result = 0;
  if ( cmd == 1 )
  {
    if ( argl == 3 )
    {
      default_cert_file_env = (char *)X509_get_default_cert_file_env();
      v8 = getenv(a1, a2, default_cert_file_env);
      if ( v8 )
      {
        cert_crl_file = X509_load_cert_crl_file(a1, ctx, v8, 1);
      }
      else
      {
        default_cert_file = (char *)X509_get_default_cert_file();
        cert_crl_file = X509_load_cert_crl_file(a1, ctx, default_cert_file, 1);
      }
      v10 = cert_crl_file != 0;
      if ( !cert_crl_file )
        ERR_put_error(a1, 0xBu, 101, 104, ".\\crypto\\x509\\by_file.c", 114);
      return v10;
    }
    else if ( argl == 1 )
    {
      return X509_load_cert_crl_file(a1, ctx, argp, 1) != 0;
    }
    else
    {
      return X509_load_cert_file(ctx, argp, argl) != 0;
    }
  }
  return result;
}
