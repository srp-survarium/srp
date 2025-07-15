BOOL __usercall crl_extension_match@<eax>(X509_crl_st *a@<ecx>, int nid@<edi>, X509_crl_st *b)
{
  int ext_by_NID; // eax
  int v5; // esi
  ui_string_st *ext; // eax
  const asn1_string_st *data; // ebx
  int v8; // eax
  int v9; // esi
  ui_string_st *v10; // eax
  const asn1_string_st *v11; // eax

  ext_by_NID = X509_CRL_get_ext_by_NID(a, nid, 0);
  v5 = ext_by_NID;
  if ( ext_by_NID < 0 )
  {
    data = 0;
  }
  else
  {
    if ( X509_CRL_get_ext_by_NID(a, nid, ext_by_NID) != -1 )
      return 0;
    ext = (ui_string_st *)X509_CRL_get_ext(a, v5);
    data = (const asn1_string_st *)X509_EXTENSION_get_data(ext);
  }
  v8 = X509_CRL_get_ext_by_NID(b, nid, 0);
  v9 = v8;
  if ( v8 < 0 )
  {
    v11 = 0;
  }
  else
  {
    if ( X509_CRL_get_ext_by_NID(b, nid, v8) != -1 )
      return 0;
    v10 = (ui_string_st *)X509_CRL_get_ext(b, v9);
    v11 = (const asn1_string_st *)X509_EXTENSION_get_data(v10);
  }
  if ( data )
  {
    if ( v11 )
      return ASN1_OCTET_STRING_cmp(data, v11) == 0;
  }
  else if ( !v11 )
  {
    return 1;
  }
  return 0;
}
