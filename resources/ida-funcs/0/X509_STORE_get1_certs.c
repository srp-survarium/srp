stack_st_X509 *__usercall X509_STORE_get1_certs@<eax>(
        int a1@<edi>,
        int a2@<ebx>,
        x509_store_ctx_st *ctx,
        X509_name_st *nm)
{
  x509_store_ctx_st *v4; // ebp
  stack_st_X509_OBJECT *objs; // edi
  int v6; // esi
  X509_name_st *v7; // esi
  int v9; // ebx
  stack_st *st; // [esp+10h] [ebp-Ch]
  x509_object_st v11; // [esp+14h] [ebp-8h] BYREF

  st = sk_new_null();
  CRYPTO_lock(a1, a2, 9, 11, ".\\crypto\\x509\\x509_lu.c", 495);
  v4 = ctx;
  objs = ctx->ctx->objs;
  v6 = x509_object_idx_cnt(objs, nm, (int *)&ctx, 1);
  if ( v6 >= 0 )
    goto LABEL_10;
  CRYPTO_lock((int)objs, (int)&ctx, 10, 11, ".\\crypto\\x509\\x509_lu.c", 503);
  v7 = nm;
  if ( !X509_STORE_get_by_subject((int)objs, (int)&ctx, v4, 1, nm, &v11) )
  {
    sk_free(st);
    return 0;
  }
  if ( v11.type == 1 )
  {
    X509_free(v11.data.x509);
  }
  else if ( v11.type == 2 )
  {
    X509_CRL_free(v11.data.crl);
  }
  CRYPTO_lock((int)objs, (int)&ctx, 9, 11, ".\\crypto\\x509\\x509_lu.c", 510);
  objs = v4->ctx->objs;
  v6 = x509_object_idx_cnt(objs, v7, (int *)&ctx, 1);
  if ( v6 >= 0 )
  {
LABEL_10:
    v11.type = 0;
    if ( (int)ctx <= 0 )
    {
      v9 = (int)st;
LABEL_16:
      CRYPTO_lock((int)objs, v9, 10, 11, ".\\crypto\\x509\\x509_lu.c", 532);
      return (stack_st_X509 *)v9;
    }
    else
    {
      while ( 1 )
      {
        objs = (stack_st_X509_OBJECT *)*((_DWORD *)sk_value(&v4->ctx->objs->stack, v6) + 1);
        CRYPTO_add_lock((int *)&objs->stack.comp, 1, 3, ".\\crypto\\x509\\x509_lu.c", 523);
        v9 = (int)st;
        if ( !sk_push(st, (char *)objs) )
          break;
        ++v6;
        if ( ++v11.type >= (int)ctx )
          goto LABEL_16;
      }
      CRYPTO_lock((int)objs, (int)st, 10, 11, ".\\crypto\\x509\\x509_lu.c", 526);
      X509_free((x509_st *)objs);
      sk_pop_free(st, (void (__cdecl *)(void *))X509_free);
      return 0;
    }
  }
  else
  {
    CRYPTO_lock((int)objs, (int)&ctx, 10, 11, ".\\crypto\\x509\\x509_lu.c", 514);
    sk_free(st);
    return 0;
  }
}
