int __cdecl asn1_enc_restore(int *len, unsigned __int8 **out, struct ASN1_VALUE_st **pval, const ASN1_ITEM_st *it)
{
  _BYTE *funcs; // eax
  char *v5; // esi

  if ( !pval )
    return 0;
  if ( !*pval )
    return 0;
  funcs = it->funcs;
  if ( !funcs )
    return 0;
  if ( (funcs[4] & 2) == 0 )
    return 0;
  v5 = (char *)*pval + *((_DWORD *)funcs + 5);
  if ( !v5 || *((_DWORD *)v5 + 2) )
    return 0;
  if ( out )
  {
    memcpy(*out, *(unsigned __int8 **)v5, *((_DWORD *)v5 + 1));
    *out += *((_DWORD *)v5 + 1);
  }
  if ( len )
    *len = *((_DWORD *)v5 + 1);
  return 1;
}
