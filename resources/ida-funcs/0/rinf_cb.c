int __cdecl rinf_cb(int operation, struct ASN1_VALUE_st **pval)
{
  int v2; // esi
  int result; // eax

  v2 = (int)*pval;
  if ( operation != 1 )
    return 1;
  result = (int)sk_new_null();
  *(_DWORD *)(v2 + 24) = result;
  if ( result )
    return 1;
  return result;
}
