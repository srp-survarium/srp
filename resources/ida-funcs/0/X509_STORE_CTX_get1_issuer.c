int __cdecl X509_STORE_CTX_get1_issuer(x509_st **issuer, x509_store_ctx_st *ctx, x509_st *x)
{
  X509_name_st *issuer_name; // ebp
  int v4; // eax
  char *ptr; // ebx
  x509_object_st *v7; // edi
  int i; // ebx
  X509_name_st *subject_name; // eax
  x509_object_st ret; // [esp+Ch] [ebp-8h] BYREF

  issuer_name = X509_get_issuer_name(x);
  v4 = X509_STORE_get_by_subject((unsigned int)x, ctx, 1, issuer_name, &ret);
  if ( v4 == 1 )
  {
    ptr = ret.data.ptr;
    if ( ctx->check_issued(ctx, x, (x509_st *)ret.data.ptr) )
    {
      *issuer = (x509_st *)ptr;
      return 1;
    }
    else
    {
      if ( ret.type == 1 )
      {
        X509_free((x509_st *)ptr);
      }
      else if ( ret.type == 2 )
      {
        X509_CRL_free((X509_crl_st *)ptr);
      }
      ret.type = 0;
      CRYPTO_lock((unsigned int)x, 9, 11, ".\\crypto\\x509\\x509_lu.c", 657);
      v7 = (x509_object_st *)x509_object_idx_cnt(ctx->ctx->objs, issuer_name, 0, 1);
      if ( v7 != (x509_object_st *)-1 )
      {
        for ( i = (int)v7; i < sk_num(&ctx->ctx->objs->stack); ++i )
        {
          v7 = (x509_object_st *)sk_value(&ctx->ctx->objs->stack, i);
          if ( v7->type != 1 )
            break;
          subject_name = X509_get_subject_name(v7->data.x509);
          if ( X509_NAME_cmp(issuer_name, subject_name) )
            break;
          if ( ctx->check_issued(ctx, x, (x509_st *)v7->data.ptr) )
          {
            *issuer = v7->data.x509;
            X509_OBJECT_up_ref_count(v7);
            ret.type = 1;
            break;
          }
        }
      }
      CRYPTO_lock((unsigned int)v7, 10, 11, ".\\crypto\\x509\\x509_lu.c", 679);
      return ret.type;
    }
  }
  else if ( v4 == -1 )
  {
    if ( ret.type == 1 )
    {
      X509_free(ret.data.x509);
    }
    else if ( ret.type == 2 )
    {
      X509_CRL_free(ret.data.crl);
    }
    ERR_put_error(0xBu, 146, 106, ".\\crypto\\x509\\x509_lu.c", 636);
    return -1;
  }
  else if ( v4 )
  {
    if ( ret.type == 1 )
    {
      X509_free(ret.data.x509);
    }
    else if ( ret.type == 2 )
    {
      X509_CRL_free(ret.data.crl);
      return -1;
    }
    return -1;
  }
  else
  {
    return 0;
  }
}
