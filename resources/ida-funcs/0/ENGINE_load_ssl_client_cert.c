int __usercall ENGINE_load_ssl_client_cert@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        engine_st *e,
        ssl_st *s,
        stack_st_X509_NAME *ca_dn,
        x509_st **pcert,
        evp_pkey_st **ppkey,
        stack_st_X509 **pother,
        ui_method_st *ui_method,
        void *callback_data)
{
  int (__cdecl *load_ssl_client_cert)(engine_st *, ssl_st *, stack_st_X509_NAME *, x509_st **, evp_pkey_st **, stack_st_X509 **, ui_method_st *, void *); // eax

  if ( e )
  {
    CRYPTO_lock(a2, a1, 9, 30, ".\\crypto\\engine\\eng_pkey.c", 179);
    if ( e->funct_ref )
    {
      CRYPTO_lock(a2, a1, 10, 30, ".\\crypto\\engine\\eng_pkey.c", 187);
      load_ssl_client_cert = e->load_ssl_client_cert;
      if ( load_ssl_client_cert )
      {
        return load_ssl_client_cert(e, s, ca_dn, pcert, ppkey, pother, ui_method, callback_data);
      }
      else
      {
        ERR_put_error(a1, 0x26u, 194, 125, ".\\crypto\\engine\\eng_pkey.c", 191);
        return 0;
      }
    }
    else
    {
      CRYPTO_lock(a2, a1, 10, 30, ".\\crypto\\engine\\eng_pkey.c", 182);
      ERR_put_error(a1, 0x26u, 194, 117, ".\\crypto\\engine\\eng_pkey.c", 184);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x26u, 194, 67, ".\\crypto\\engine\\eng_pkey.c", 176);
    return 0;
  }
}
