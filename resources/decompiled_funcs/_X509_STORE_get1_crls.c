stack_st_X509_CRL *__usercall X509_STORE_get1_crls@<eax>(
        unsigned int a1@<edi>,
        x509_store_ctx_st *ctx,
        X509_name_st *nm)
{
  x509_store_ctx_st *v3; // ebp
  X509_name_st *v4; // esi
  stack_st_X509_OBJECT *objs; // edi
  int v7; // edi
  int v8; // esi
  stack_st *st; // [esp+10h] [ebp-Ch]
  x509_object_st ret; // [esp+14h] [ebp-8h] BYREF

  st = sk_new_null();
  CRYPTO_lock(a1, 9, 11, ".\\crypto\\x509\\x509_lu.c", 544);
  v3 = ctx;
  v4 = nm;
  objs = ctx->ctx->objs;
  x509_object_idx_cnt(objs, nm, (int *)&ctx, 2);
  CRYPTO_lock((unsigned int)objs, 10, 11, ".\\crypto\\x509\\x509_lu.c", 550);
  if ( X509_STORE_get_by_subject((unsigned int)objs, v3, 2, v4, &ret) )
  {
    if ( ret.type == 1 )
    {
      X509_free(ret.data.x509);
    }
    else if ( ret.type == 2 )
    {
      X509_CRL_free(ret.data.crl);
    }
    CRYPTO_lock((unsigned int)objs, 9, 11, ".\\crypto\\x509\\x509_lu.c", 557);
    v7 = x509_object_idx_cnt(v3->ctx->objs, v4, (int *)&ctx, 2);
    if ( v7 >= 0 )
    {
      ret.type = 0;
      if ( (int)ctx <= 0 )
      {
LABEL_12:
        CRYPTO_lock(v7, 10, 11, ".\\crypto\\x509\\x509_lu.c", 579);
        return (stack_st_X509_CRL *)st;
      }
      else
      {
        while ( 1 )
        {
          v8 = *((_DWORD *)sk_value(&v3->ctx->objs->stack, v7) + 1);
          CRYPTO_add_lock((int *)(v8 + 12), 1, 6, ".\\crypto\\x509\\x509_lu.c", 570);
          if ( !sk_push(st, (char *)v8) )
            break;
          ++v7;
          if ( ++ret.type >= (int)ctx )
            goto LABEL_12;
        }
        CRYPTO_lock(v7, 10, 11, ".\\crypto\\x509\\x509_lu.c", 573);
        X509_CRL_free((X509_crl_st *)v8);
        sk_pop_free(st, (void (__cdecl *)(void *))X509_CRL_free);
        return 0;
      }
    }
    else
    {
      CRYPTO_lock(v7, 10, 11, ".\\crypto\\x509\\x509_lu.c", 561);
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
