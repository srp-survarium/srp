void __cdecl CONF_modules_unload(int all)
{
  int i; // edi
  char *v2; // eax
  char *v3; // esi

  CONF_modules_finish();
  for ( i = sk_num(&supported_modules->stack) - 1; i >= 0; --i )
  {
    v2 = sk_value(&supported_modules->stack, i);
    v3 = v2;
    if ( *((int *)v2 + 4) <= 0 && *(_DWORD *)v2 || all )
    {
      sk_delete(&supported_modules->stack, i);
      if ( *(_DWORD *)v3 )
        DSO_free(*(dso_st **)v3);
      CRYPTO_free(*((void **)v3 + 1));
      CRYPTO_free(v3);
    }
  }
  if ( !sk_num(&supported_modules->stack) )
  {
    sk_free(&supported_modules->stack);
    supported_modules = 0;
  }
}
