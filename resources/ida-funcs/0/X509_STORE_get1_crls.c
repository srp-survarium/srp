stack_st_X509_CRL *__usercall X509_STORE_get1_crls@<eax>(
        int a1@<edi>,
        int a2@<ebx>,
        x509_store_ctx_st *ctx,
        X509_name_st *nm)
{
  x509_store_ctx_st *v4; // ebp
  X509_name_st *v5; // esi
  stack_st_X509_OBJECT *objs; // edi
  x509_store_ctx_st **p_ctx; // ebx
  int v9; // edi
  int v10; // esi
  stack_st *st; // [esp+10h] [ebp-Ch]
  x509_object_st v12; // [esp+14h] [ebp-8h] BYREF

  st = sk_new_null();
  CRYPTO_lock(a1, a2, 9, 11, ".\\crypto\\x509\\x509_lu.c", 544);
  v4 = ctx;
  v5 = nm;
  objs = ctx->ctx->objs;
  x509_object_idx_cnt(objs, nm, (int *)&ctx, 2);
  CRYPTO_lock((int)objs, (int)&ctx, 10, 11, ".\\crypto\\x509\\x509_lu.c", 550);
  if ( X509_STORE_get_by_subject((int)objs, (int)&ctx, v4, 2, v5, &v12) )
  {
    if ( v12.type == 1 )
    {
      X509_free(v12.data.x509);
    }
    else if ( v12.type == 2 )
    {
      X509_CRL_free(v12.data.crl);
    }
    CRYPTO_lock((int)objs, (int)&ctx, 9, 11, ".\\crypto\\x509\\x509_lu.c", 557);
    p_ctx = &ctx;
    v9 = x509_object_idx_cnt(v4->ctx->objs, v5, (int *)&ctx, 2);
    if ( v9 >= 0 )
    {
      v12.type = 0;
      if ( (int)ctx <= 0 )
      {
LABEL_12:
        CRYPTO_lock(v9, (int)p_ctx, 10, 11, ".\\crypto\\x509\\x509_lu.c", 579);
        return (stack_st_X509_CRL *)st;
      }
      else
      {
        while ( 1 )
        {
          v10 = *((_DWORD *)sk_value(&v4->ctx->objs->stack, v9) + 1);
          CRYPTO_add_lock((int *)(v10 + 12), 1, 6, ".\\crypto\\x509\\x509_lu.c", 570);
          p_ctx = (x509_store_ctx_st **)st;
          if ( !sk_push(st, (char *)v10) )
            break;
          ++v9;
          if ( ++v12.type >= (int)ctx )
            goto LABEL_12;
        }
        CRYPTO_lock(v9, (int)st, 10, 11, ".\\crypto\\x509\\x509_lu.c", 573);
        X509_CRL_free((X509_crl_st *)v10);
        sk_pop_free(st, (void (__cdecl *)(void *))X509_CRL_free);
        return 0;
      }
    }
    else
    {
      CRYPTO_lock(v9, (int)&ctx, 10, 11, ".\\crypto\\x509\\x509_lu.c", 561);
      sk_free(st);
      return 0;
    }
  }
  else
  {
    sk_free(st);
    return 0;
  }
}
