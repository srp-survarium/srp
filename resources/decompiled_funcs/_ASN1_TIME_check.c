int __cdecl ASN1_TIME_check(asn1_string_st *t)
{
  int type; // eax

  type = t->type;
  if ( type == 24 )
    return ASN1_GENERALIZEDTIME_check(t);
  if ( type == 23 )
    return ASN1_UTCTIME_check(t);
  return 0;
}
