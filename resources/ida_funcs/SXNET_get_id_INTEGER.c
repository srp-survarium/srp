asn1_string_st *__cdecl SXNET_get_id_INTEGER(SXNET_st *sx, asn1_string_st *zone)
{
  int v2; // esi
  char *v3; // edi

  v2 = 0;
  if ( sk_num(&sx->ids->stack) <= 0 )
    return 0;
  while ( 1 )
  {
    v3 = sk_value(&sx->ids->stack, v2);
    if ( !ASN1_STRING_cmp(*(const asn1_string_st **)v3, zone) )
      break;
    if ( ++v2 >= sk_num(&sx->ids->stack) )
      return 0;
  }
  return (asn1_string_st *)*((_DWORD *)v3 + 1);
}
