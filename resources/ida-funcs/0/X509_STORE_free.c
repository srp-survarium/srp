void __cdecl X509_STORE_free(x509_store_st *vfy)
{
  stack_st_X509_LOOKUP *get_cert_methods; // ebx
  int i; // edi
  char *v3; // esi
  int v4; // eax
  void (__cdecl *v5)(char *); // eax
  int v6; // eax
  void (__cdecl *v7)(char *); // eax

  if ( vfy )
  {
    get_cert_methods = vfy->get_cert_methods;
    for ( i = 0; i < sk_num(&get_cert_methods->stack); ++i )
    {
      v3 = sk_value(&get_cert_methods->stack, i);
      v4 = *((_DWORD *)v3 + 2);
      if ( v4 )
      {
        v5 = *(void (__cdecl **)(char *))(v4 + 16);
        if ( v5 )
          v5(v3);
      }
      v6 = *((_DWORD *)v3 + 2);
      if ( v6 )
      {
        v7 = *(void (__cdecl **)(char *))(v6 + 8);
        if ( v7 )
          v7(v3);
      }
      CRYPTO_free(v3);
    }
    sk_free(&get_cert_methods->stack);
    sk_pop_free(&vfy->objs->stack, (void (__cdecl *)(void *))cleanup);
    CRYPTO_free_ex_data(i);
    if ( vfy->param )
      X509_VERIFY_PARAM_free(vfy->param);
    CRYPTO_free(vfy);
  }
}
