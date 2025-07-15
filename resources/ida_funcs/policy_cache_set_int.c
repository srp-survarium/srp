int __cdecl policy_cache_set_int(int *out, asn1_string_st *value)
{
  if ( value )
  {
    if ( value->type == 258 )
      return 0;
    *out = ASN1_INTEGER_get(value);
  }
  return 1;
}
