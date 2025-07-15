int __cdecl nc_dns(asn1_string_st *dns)
{
  asn1_string_st *base; // ecx
  unsigned __int8 *data; // edx
  const char *v3; // esi
  int length; // ecx

  data = dns->data;
  v3 = (const char *)base->data;
  if ( !*v3 )
    return 0;
  length = base->length;
  if ( dns->length <= length )
    return _stricmp(v3, (const char *)data) != 0 ? 0x2F : 0;
  data += dns->length - length;
  if ( *(data - 1) == 46 )
    return _stricmp(v3, (const char *)data) != 0 ? 0x2F : 0;
  else
    return 47;
}
