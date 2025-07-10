x509_attributes_st *__cdecl X509_ATTRIBUTE_create(unsigned int nid, int atrtype, void *value)
{
  asn1_type_st *v3; // edi
  struct ASN1_VALUE_st *v4; // esi
  stack_st *v5; // eax
  char *v6; // eax

  v3 = 0;
  v4 = ASN1_item_new(&local_it_43);
  if ( !v4 )
    return 0;
  *(_DWORD *)v4 = OBJ_nid2obj(nid);
  *((_DWORD *)v4 + 1) = 0;
  v5 = sk_new_null();
  *((_DWORD *)v4 + 2) = v5;
  if ( !v5 || (v6 = (char *)ASN1_TYPE_new(), (v3 = (asn1_type_st *)v6) == 0) || !sk_push(*((stack_st **)v4 + 2), v6) )
  {
    ASN1_item_free(v4, &local_it_43);
    if ( v3 )
      ASN1_TYPE_free(v3);
    return 0;
  }
  ASN1_TYPE_set(v3, atrtype, value);
  return (x509_attributes_st *)v4;
}
