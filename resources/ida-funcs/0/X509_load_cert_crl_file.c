int __usercall X509_load_cert_crl_file@<eax>(int a1@<ebx>, x509_lookup_st *ctx, char *file, int type)
{
  int v4; // ebp
  bio_st *v6; // eax
  bio_st *v7; // esi
  stack_st_X509_INFO *bio; // edi
  int i; // ebx
  char *v10; // esi
  X509_crl_st *v11; // esi

  v4 = 0;
  if ( type != 1 )
    return X509_load_cert_file(ctx, file, type);
  v6 = BIO_new_file(file, "r");
  v7 = v6;
  if ( v6 )
  {
    bio = PEM_X509_INFO_read_bio(v6, 0, 0, 0);
    BIO_free((int)bio, a1, v7);
    if ( bio )
    {
      for ( i = 0; i < sk_num(&bio->stack); ++i )
      {
        v10 = sk_value(&bio->stack, i);
        if ( *(_DWORD *)v10 )
        {
          X509_STORE_add_cert(ctx->store_ctx, *(x509_st **)v10);
          ++v4;
        }
        v11 = (X509_crl_st *)*((_DWORD *)v10 + 1);
        if ( v11 )
        {
          X509_STORE_add_crl(ctx->store_ctx, v11);
          ++v4;
        }
      }
      sk_pop_free(&bio->stack, (void (__cdecl *)(void *))X509_INFO_free);
      return v4;
    }
    else
    {
      ERR_put_error(a1, 0xBu, 132, 9, ".\\crypto\\x509\\by_file.c", 280);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0xBu, 132, 2, ".\\crypto\\x509\\by_file.c", 274);
    return 0;
  }
}
