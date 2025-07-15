int __cdecl pkey_cb(int operation, struct ASN1_VALUE_st **pval)
{
  int v2; // ecx

  if ( operation == 2 )
  {
    v2 = *((_DWORD *)*pval + 3);
    if ( *(_DWORD *)(v2 + 4) )
      OPENSSL_cleanse(*(_DWORD *)(*(_DWORD *)(v2 + 4) + 8), **(_DWORD **)(v2 + 4));
  }
  return 1;
}
