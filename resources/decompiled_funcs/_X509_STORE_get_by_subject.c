int __usercall X509_STORE_get_by_subject@<eax>(
        unsigned int a1@<edi>,
        x509_store_ctx_st *vs,
        int type,
        X509_name_st *name,
        x509_object_st *ret)
{
  x509_store_st *ctx; // esi
  stack_st_X509_OBJECT *objs; // edi
  int *v7; // ebx
  int v8; // eax
  int current_method; // edi
  char *v10; // eax
  int v11; // ecx
  int (__cdecl *v12)(char *, int, X509_name_st *, _BYTE *); // ecx
  int result; // eax
  int v14; // ecx
  _BYTE v15[8]; // [esp+10h] [ebp-8h] BYREF

  ctx = vs->ctx;
  CRYPTO_lock(a1, 9, 11, ".\\crypto\\x509\\x509_lu.c", 297);
  objs = ctx->objs;
  v7 = 0;
  v8 = x509_object_idx_cnt(objs, name, 0, type);
  if ( v8 != -1 )
    v7 = (int *)sk_value(&objs->stack, v8);
  CRYPTO_lock((unsigned int)objs, 10, 11, ".\\crypto\\x509\\x509_lu.c", 299);
  if ( v7 && type != 2 )
    goto LABEL_17;
  current_method = vs->current_method;
  if ( current_method < sk_num(&ctx->get_cert_methods->stack) )
  {
    while ( 1 )
    {
      v10 = sk_value(&ctx->get_cert_methods->stack, current_method);
      v11 = *((_DWORD *)v10 + 2);
      if ( v11 )
      {
        v12 = *(int (__cdecl **)(char *, int, X509_name_st *, _BYTE *))(v11 + 24);
        if ( v12 )
        {
          if ( !*((_DWORD *)v10 + 1) )
          {
            result = v12(v10, type, name, v15);
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
    v7 = (int *)v15;
  }
LABEL_15:
  vs->current_method = 0;
  if ( !v7 )
    return 0;
LABEL_17:
  ret->type = *v7;
  v14 = v7[1];
  ret->data.ptr = (char *)v14;
  if ( ret->type == 1 )
  {
    CRYPTO_add_lock((int *)(v14 + 16), 1, 3, ".\\crypto\\x509\\x509_lu.c", 405);
  }
  else if ( ret->type == 2 )
  {
    CRYPTO_add_lock((int *)(v14 + 12), 1, 6, ".\\crypto\\x509\\x509_lu.c", 408);
  }
  return 1;
}
