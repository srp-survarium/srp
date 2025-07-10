int __cdecl asn1_do_lock(struct ASN1_VALUE_st **pval, int op, const ASN1_ITEM_st *it)
{
  const void *funcs; // ecx
  int *v4; // eax

  if ( it->itype != 1 && it->itype != 6 )
    return 0;
  funcs = it->funcs;
  if ( !funcs || (*((_BYTE *)funcs + 4) & 1) == 0 )
    return 0;
  v4 = (int *)((char *)*pval + *((_DWORD *)funcs + 2));
  if ( op )
    return CRYPTO_add_lock(v4, op, *((_DWORD *)funcs + 3), ".\\crypto\\asn1\\tasn_utl.c", 117);
  *v4 = 1;
  return 1;
}
