int __usercall X509_STORE_get_by_subject@<eax>(
        int a1@<edi>,
        int a2@<ebx>,
        x509_store_ctx_st *vs,
        int type,
        X509_name_st *name,
        x509_object_st *ret)
{
  x509_store_st *ctx; // esi
  stack_st_X509_OBJECT *objs; // edi
  int *v8; // ebx
  int v9; // eax
  int current_method; // edi
  char *v11; // eax
  int v12; // ecx
  int (__cdecl *v13)(char *, int, X509_name_st *, _BYTE *); // ecx
  int result; // eax
  int v15; // ecx
  _BYTE v16[8]; // [esp+10h] [ebp-8h] BYREF

  ctx = vs->ctx;
  CRYPTO_lock(a1, a2, 9, 11, ".\\crypto\\x509\\x509_lu.c", 297);
  objs = ctx->objs;
  v8 = 0;
  v9 = x509_object_idx_cnt(objs, name, 0, type);
  if ( v9 != -1 )
    v8 = (int *)sk_value(&objs->stack, v9);
  CRYPTO_lock((int)objs, (int)v8, 10, 11, ".\\crypto\\x509\\x509_lu.c", 299);
  if ( v8 && type != 2 )
    goto LABEL_17;
  current_method = vs->current_method;
  if ( current_method < sk_num(&ctx->get_cert_methods->stack) )
  {
    while ( 1 )
    {
      v11 = sk_value(&ctx->get_cert_methods->stack, current_method);
      v12 = *((_DWORD *)v11 + 2);
      if ( v12 )
      {
        v13 = *(int (__cdecl **)(char *, int, X509_name_st *, _BYTE *))(v12 + 24);
        if ( v13 )
        {
          if ( !*((_DWORD *)v11 + 1) )
          {
            result = v13(v11, type, name, v16);
            if ( result < 0 )
            {
              vs->current_method = result;
              return result;
            }
            if ( result )
              break;
          }
        }
      }
      if ( ++current_method >= sk_num(&ctx->get_cert_methods->stack) )
        goto LABEL_15;
    }
    v8 = (int *)v16;
  }
LABEL_15:
  vs->current_method = 0;
  if ( !v8 )
    return 0;
LABEL_17:
  ret->type = *v8;
  v15 = v8[1];
  ret->data.ptr = (char *)v15;
  if ( ret->type == 1 )
  {
    CRYPTO_add_lock((int *)(v15 + 16), 1, 3, ".\\crypto\\x509\\x509_lu.c", 405);
  }
  else if ( ret->type == 2 )
  {
    CRYPTO_add_lock((int *)(v15 + 12), 1, 6, ".\\crypto\\x509\\x509_lu.c", 408);
  }
  return 1;
}
