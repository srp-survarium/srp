char *__cdecl i2s_ASN1_ENUMERATED_TABLE(v3_ext_method *method, asn1_string_st *e)
{
  int v2; // eax
  char *usr_data; // ecx

  v2 = ASN1_ENUMERATED_get(e);
  usr_data = (char *)method->usr_data;
  if ( !*((_DWORD *)usr_data + 1) )
    return i2s_ASN1_ENUMERATED(method, e);
  while ( v2 != *(_DWORD *)usr_data )
  {
    usr_data += 12;
    if ( !*((_DWORD *)usr_data + 1) )
      return i2s_ASN1_ENUMERATED(method, e);
  }
  return BUF_strdup(*((const char **)usr_data + 1));
}
