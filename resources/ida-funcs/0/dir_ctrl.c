int __usercall dir_ctrl@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        x509_lookup_st *ctx,
        int cmd,
        const char *argp,
        int argl)
{
  char *method_data; // esi
  int result; // eax
  char *default_cert_dir_env; // eax
  char *default_cert_dir; // eax
  int v10; // esi

  method_data = ctx->method_data;
  result = 0;
  if ( cmd == 2 )
  {
    if ( argl == 3 )
    {
      default_cert_dir_env = (char *)X509_get_default_cert_dir_env();
      default_cert_dir = getenv(a1, a2, default_cert_dir_env);
      if ( !default_cert_dir )
        default_cert_dir = (char *)X509_get_default_cert_dir();
      v10 = add_cert_dir((lookup_dir_st *)method_data, default_cert_dir, 1);
      if ( !v10 )
        ERR_put_error(0xBu, 102, 103, ".\\crypto\\x509\\by_dir.c", 146);
      return v10;
    }
    else
    {
      return add_cert_dir((lookup_dir_st *)method_data, argp, argl);
    }
  }
  return result;
}
