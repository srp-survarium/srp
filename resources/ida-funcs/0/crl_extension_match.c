BOOL __usercall crl_extension_match@<eax>(stack_st_X509_ATTRIBUTE *a@<ecx>, int nid@<edi>, stack_st_X509_ATTRIBUTE *b)
{
  int ext_by_NID; // eax
  int v5; // esi
  ui_string_st *ext; // eax
  ui_string_st *data; // ebx
  int v8; // eax
  int v9; // esi
  ui_string_st *v10; // eax
  ui_string_st *v11; // eax

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
    ext = (ui_string_st *)X509_CRL_get_ext((X509_crl_st *)a, v5);
    data = X509_EXTENSION_get_data(ext);
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
    v10 = (ui_string_st *)X509_CRL_get_ext((X509_crl_st *)b, v9);
    v11 = X509_EXTENSION_get_data(v10);
  }
  if ( data )
  {
    if ( v11 )
      return ASN1_OCTET_STRING_cmp((const asn1_string_st *)data, (const asn1_string_st *)v11) == 0;
  }
  else if ( !v11 )
  {
    return 1;
  }
  return 0;
}
