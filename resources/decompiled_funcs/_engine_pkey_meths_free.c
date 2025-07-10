void __cdecl engine_pkey_meths_free(engine_st *e)
{
  engine_st *v1; // edi
  int (__cdecl *pkey_meths)(engine_st *, evp_pkey_method_st **, const int **, int); // eax
  int v3; // ebx
  int i; // esi
  evp_pkey_method_st *pmeth; // [esp+4h] [ebp-4h] BYREF

  v1 = e;
  pkey_meths = e->pkey_meths;
  if ( pkey_meths )
  {
    v3 = pkey_meths(e, 0, (const int **)&e, 0);
    for ( i = 0; i < v3; ++i )
    {
      if ( v1->pkey_meths(v1, &pmeth, 0, *((_DWORD *)&e->id + i)) )
        EVP_PKEY_meth_free(pmeth);
    }
  }
}
