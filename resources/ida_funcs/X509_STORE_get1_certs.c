stack_st_X509 *__usercall X509_STORE_get1_certs@<eax>(unsigned int a1@<edi>, x509_store_ctx_st *ctx, X509_name_st *nm)
{
  x509_store_ctx_st *v3; // ebp
  stack_st_X509_OBJECT *objs; // edi
  int v5; // esi
  X509_name_st *v6; // esi
  stack_st *v8; // ebx
  stack_st *st; // [esp+10h] [ebp-Ch]
  x509_object_st ret; // [esp+14h] [ebp-8h] BYREF

  st = sk_new_null();
  CRYPTO_lock(a1, 9, 11, ".\\crypto\\x509\\x509_lu.c", 495);
  v3 = ctx;
  objs = ctx->ctx->objs;
  v5 = x509_object_idx_cnt(objs, nm, (int *)&ctx, 1);
  if ( v5 >= 0 )
    goto LABEL_10;
  CRYPTO_lock((unsigned int)objs, 10, 11, ".\\crypto\\x509\\x509_lu.c", 503);
  v6 = nm;
  if ( !X509_STORE_get_by_subject((unsigned int)objs, v3, 1, nm, &ret) )
  {
    sk_free(st);
    return 0;
  }
  if ( ret.type == 1 )
  {
    X509_free(ret.data.x509);
  }
  else if ( ret.type == 2 )
  {
    X509_CRL_free(ret.data.crl);
  }
  CRYPTO_lock((unsigned int)objs, 9, 11, ".\\crypto\\x509\\x509_lu.c", 510);
  objs = v3->ctx->objs;
  v5 = x509_object_idx_cnt(objs, v6, (int *)&ctx, 1);
  if ( v5 >= 0 )
  {
LABEL_10:
    ret.type = 0;
    if ( (int)ctx <= 0 )
    {
      v8 = st;
LABEL_16:
      CRYPTO_lock((unsigned int)objs, 10, 11, ".\\crypto\\x509\\x509_lu.c", 532);
      return (stack_st_X509 *)v8;
    }
    else
    {
      while ( 1 )
      {
        objs = (stack_st_X509_OBJECT *)*((_DWORD *)sk_value(&v3->ctx->objs->stack, v5) + 1);
        CRYPTO_add_lock((int *)&objs->stack.comp, 1, 3, ".\\crypto\\x509\\x509_lu.c", 523);
        v8 = st;
        if ( !sk_push(st, (char *)objs) )
          break;
        ++v5;
        if ( ++ret.type >= (int)ctx )
          goto LABEL_16;
      }
      CRYPTO_lock((unsigned int)objs, 10, 11, ".\\crypto\\x509\\x509_lu.c", 526);
      X509_free((x509_st *)objs);
      sk_pop_free(st, (void (__cdecl *)(void *))X509_free);
      return 0;
    }
  }
  else
  {
    CRYPTO_lock((unsigned int)objs, 10, 11, ".\\crypto\\x509\\x509_lu.c", 514);
    sk_free(st);
    return 0;
  }
}
