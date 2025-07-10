int __cdecl X509_load_cert_crl_file(x509_lookup_st *ctx, char *file, int type)
{
  int v3; // ebp
  bio_st *v5; // eax
  bio_st *v6; // esi
  stack_st_X509_INFO *bio; // edi
  int i; // ebx
  char *v9; // esi
  X509_crl_st *v10; // esi

  v3 = 0;
  if ( type != 1 )
    return X509_load_cert_file(ctx, file, type);
  v5 = BIO_new_file(file, "r");
  v6 = v5;
  if ( v5 )
  {
    bio = PEM_X509_INFO_read_bio(v5, 0, 0, 0);
    BIO_free((unsigned int)bio, v6);
    if ( bio )
    {
      for ( i = 0; i < sk_num(&bio->stack); ++i )
      {
        v9 = sk_value(&bio->stack, i);
        if ( *(_DWORD *)v9 )
        {
          X509_STORE_add_cert(ctx->store_ctx, *(x509_st **)v9);
          ++v3;
        }
        v10 = (X509_crl_st *)*((_DWORD *)v9 + 1);
        if ( v10 )
        {
          X509_STORE_add_crl(ctx->store_ctx, v10);
          ++v3;
        }
      }
      sk_pop_free(&bio->stack, (void (__cdecl *)(void *))X509_INFO_free);
      return v3;
    }
    else
    {
      ERR_put_error(0xBu, 132, 9, ".\\crypto\\x509\\by_file.c", 280);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0xBu, 132, 2, ".\\crypto\\x509\\by_file.c", 274);
    return 0;
  }
}
