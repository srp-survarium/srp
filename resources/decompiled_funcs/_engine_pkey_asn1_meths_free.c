void __cdecl engine_pkey_asn1_meths_free(engine_st *e)
{
  engine_st *v1; // edi
  int (__cdecl *pkey_asn1_meths)(engine_st *, evp_pkey_asn1_method_st **, const int **, int); // eax
  int v3; // ebx
  int i; // esi
  evp_pkey_asn1_method_st *ameth; // [esp+4h] [ebp-4h] BYREF

  v1 = e;
  pkey_asn1_meths = e->pkey_asn1_meths;
  if ( pkey_asn1_meths )
  {
    v3 = pkey_asn1_meths(e, 0, (const int **)&e, 0);
    for ( i = 0; i < v3; ++i )
    {
      if ( v1->pkey_asn1_meths(v1, &ameth, 0, *((_DWORD *)&e->id + i)) )
        EVP_PKEY_asn1_free(ameth);
    }
  }
}
