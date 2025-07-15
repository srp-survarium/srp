void __cdecl CONF_modules_unload(int all)
{
  int i; // edi
  dso_st **v2; // eax
  dso_st **v3; // esi

  CONF_modules_finish();
  for ( i = sk_num(&supported_modules->stack) - 1; i >= 0; --i )
  {
    v2 = (dso_st **)sk_value(&supported_modules->stack, i);
    v3 = v2;
    if ( (int)v2[4] <= 0 && *v2 || all )
    {
      sk_delete(&supported_modules->stack, i);
      if ( *v3 )
        DSO_free(*v3);
      CRYPTO_free(v3[1]);
      CRYPTO_free(v3);
    }
  }
  if ( !sk_num(&supported_modules->stack) )
  {
    sk_free(&supported_modules->stack);
    supported_modules = 0;
  }
}
