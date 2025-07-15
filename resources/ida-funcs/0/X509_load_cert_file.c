int __cdecl X509_load_cert_file(x509_lookup_st *ctx, char *file, int type)
{
  int v3; // ebx
  bio_method_st *v5; // eax
  bio_st *v6; // eax
  bio_st *v7; // edi
  x509_st *bio_X509_AUX; // esi
  x509_st *v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-4h]

  v3 = 0;
  v11 = 0;
  if ( !file )
    return 1;
  v5 = BIO_s_file();
  v6 = BIO_new(0, v5);
  v7 = v6;
  if ( v6 && BIO_ctrl(0, v6, 108, 3, file) > 0 )
  {
    if ( type == 1 )
    {
      bio_X509_AUX = PEM_read_bio_X509_AUX(0, v7, 0, 0, 0);
      if ( bio_X509_AUX )
      {
        while ( X509_STORE_add_cert(ctx->store_ctx, bio_X509_AUX) )
        {
          ++v3;
          X509_free(bio_X509_AUX);
          bio_X509_AUX = PEM_read_bio_X509_AUX(v3, v7, 0, 0, 0);
          if ( !bio_X509_AUX )
            goto LABEL_9;
        }
      }
      else
      {
LABEL_9:
        if ( (ERR_peek_last_error() & 0xFFF) == 0x6C && v3 > 0 )
        {
          ERR_clear_error(v3);
          v11 = v3;
        }
        else
        {
          ERR_put_error(v3, 0xBu, 111, 9, ".\\crypto\\x509\\by_file.c", 162);
        }
      }
      goto err_252;
    }
    if ( type == 2 )
    {
      v9 = d2i_X509_bio(v7, 0);
      bio_X509_AUX = v9;
      if ( v9 )
      {
        v10 = X509_STORE_add_cert(ctx->store_ctx, v9);
        if ( v10 )
          v11 = v10;
      }
      else
      {
        ERR_put_error(0, 0xBu, 111, 13, ".\\crypto\\x509\\by_file.c", 179);
      }
err_252:
      if ( bio_X509_AUX )
        X509_free(bio_X509_AUX);
      goto LABEL_14;
    }
    ERR_put_error(0, 0xBu, 111, 100, ".\\crypto\\x509\\by_file.c", 188);
  }
  else
  {
    ERR_put_error(0, 0xBu, 111, 2, ".\\crypto\\x509\\by_file.c", 142);
  }
LABEL_14:
  if ( v7 )
    BIO_free((int)v7, v3, v7);
  return v11;
}
