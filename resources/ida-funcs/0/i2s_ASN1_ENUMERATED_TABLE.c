char *__usercall i2s_ASN1_ENUMERATED_TABLE@<eax>(int a1@<ebx>, v3_ext_method *method, asn1_string_st *e)
{
  int v3; // eax
  char *usr_data; // ecx

  v3 = ASN1_ENUMERATED_get(e);
  usr_data = (char *)method->usr_data;
  if ( !*((_DWORD *)usr_data + 1) )
    return i2s_ASN1_ENUMERATED(a1, method, e);
  while ( v3 != *(_DWORD *)usr_data )
  {
    usr_data += 12;
    if ( !*((_DWORD *)usr_data + 1) )
      return i2s_ASN1_ENUMERATED(a1, method, e);
  }
  return BUF_strdup(*((char **)usr_data + 1));
}
