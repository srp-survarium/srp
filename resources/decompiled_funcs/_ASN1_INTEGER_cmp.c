int __cdecl ASN1_INTEGER_cmp(const asn1_string_st *x, const asn1_string_st *y)
{
  int v2; // esi
  int result; // eax

  v2 = x->type & 0x100;
  if ( v2 != (y->type & 0x100) )
    return 2 * (v2 == 0) - 1;
  result = ASN1_STRING_cmp(x, y);
  if ( v2 )
    return -result;
  return result;
}
