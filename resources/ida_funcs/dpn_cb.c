int __cdecl dpn_cb(int operation, struct ASN1_VALUE_st **pval)
{
  int v2; // ecx
  X509_name_st *v3; // ecx

  v2 = (int)*pval;
  if ( operation == 1 )
  {
    *(_DWORD *)(v2 + 8) = 0;
  }
  else if ( operation == 3 )
  {
    v3 = *(X509_name_st **)(v2 + 8);
    if ( v3 )
    {
      X509_NAME_free(v3);
      return 1;
    }
  }
  return 1;
}
