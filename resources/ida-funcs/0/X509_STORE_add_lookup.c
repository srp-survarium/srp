x509_lookup_st *__cdecl X509_STORE_add_lookup(x509_store_st *v, x509_lookup_method_st *m)
{
  stack_st_X509_LOOKUP *get_cert_methods; // edi
  int v3; // esi
  x509_lookup_st *result; // eax
  x509_lookup_st *v5; // eax
  x509_lookup_st *v6; // esi
  int (__cdecl *new_item)(x509_lookup_st *); // ebx
  x509_lookup_method_st *method; // eax
  void (__cdecl *free)(x509_lookup_st *); // eax

  get_cert_methods = v->get_cert_methods;
  v3 = 0;
  if ( sk_num(&get_cert_methods->stack) <= 0 )
  {
LABEL_4:
    v5 = (x509_lookup_st *)CRYPTO_malloc(20, ".\\crypto\\x509\\x509_lu.c", 69);
    v6 = v5;
    if ( v5 )
    {
      v5->init = 0;
      v5->skip = 0;
      v5->method = m;
      v5->method_data = 0;
      v5->store_ctx = 0;
      new_item = m->new_item;
      if ( !new_item || new_item(v5) )
      {
        v6->store_ctx = v;
        if ( sk_push(&v->get_cert_methods->stack, (char *)v6) )
          return v6;
        method = v6->method;
        if ( method )
        {
          free = method->free;
          if ( free )
            free(v6);
        }
      }
      CRYPTO_free(v6);
    }
    return 0;
  }
  else
  {
    while ( 1 )
    {
      result = (x509_lookup_st *)sk_value(&get_cert_methods->stack, v3);
      if ( m == result->method )
        break;
      if ( ++v3 >= sk_num(&get_cert_methods->stack) )
        goto LABEL_4;
    }
  }
  return result;
}
