int __usercall X509_STORE_CTX_get1_issuer@<eax>(int a1@<ebx>, x509_st **issuer, x509_store_ctx_st *ctx, x509_st *x)
{
  X509_name_st *issuer_name; // ebp
  int v5; // eax
  char *ptr; // ebx
  int i; // ebx
  x509_object_st *v9; // edi
  X509_name_st *subject_name; // eax
  x509_object_st v11; // [esp+Ch] [ebp-8h] BYREF

  issuer_name = X509_get_issuer_name(x);
  v5 = X509_STORE_get_by_subject((int)x, a1, ctx, 1, issuer_name, &v11);
  if ( v5 == 1 )
  {
    ptr = v11.data.ptr;
    if ( ctx->check_issued(ctx, x, (x509_st *)v11.data.ptr) )
    {
      *issuer = (x509_st *)ptr;
      return 1;
    }
    else
    {
      if ( v11.type == 1 )
      {
        X509_free((x509_st *)ptr);
      }
      else if ( v11.type == 2 )
      {
        X509_CRL_free((X509_crl_st *)ptr);
      }
      v11.type = 0;
      CRYPTO_lock((int)x, (int)ptr, 9, 11, ".\\crypto\\x509\\x509_lu.c", 657);
      i = 0;
      v9 = (x509_object_st *)x509_object_idx_cnt(ctx->ctx->objs, issuer_name, 0, 1);
      if ( v9 != (x509_object_st *)-1 )
      {
        for ( i = (int)v9; i < sk_num(&ctx->ctx->objs->stack); ++i )
        {
          v9 = (x509_object_st *)sk_value(&ctx->ctx->objs->stack, i);
          if ( v9->type != 1 )
            break;
          subject_name = X509_get_subject_name(v9->data.x509);
          if ( X509_NAME_cmp(issuer_name, subject_name) )
            break;
          if ( ctx->check_issued(ctx, x, (x509_st *)v9->data.ptr) )
          {
            *issuer = v9->data.x509;
            X509_OBJECT_up_ref_count(v9);
            v11.type = 1;
            break;
          }
        }
      }
      CRYPTO_lock((int)v9, i, 10, 11, ".\\crypto\\x509\\x509_lu.c", 679);
      return v11.type;
    }
  }
  else if ( v5 == -1 )
  {
    if ( v11.type == 1 )
    {
      X509_free(v11.data.x509);
    }
    else if ( v11.type == 2 )
    {
      X509_CRL_free(v11.data.crl);
    }
    ERR_put_error(a1, 0xBu, 146, 106, ".\\crypto\\x509\\x509_lu.c", 636);
    return -1;
  }
  else if ( v5 )
  {
    if ( v11.type == 1 )
    {
      X509_free(v11.data.x509);
    }
    else if ( v11.type == 2 )
    {
      X509_CRL_free(v11.data.crl);
      return -1;
    }
    return -1;
  }
  else
  {
    return 0;
  }
}
