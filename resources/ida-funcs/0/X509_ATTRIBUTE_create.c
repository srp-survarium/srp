x509_attributes_st *__usercall X509_ATTRIBUTE_create@<eax>(int a1@<ebx>, unsigned int nid, int atrtype, int value)
{
  asn1_type_st *v4; // edi
  struct ASN1_VALUE_st *v5; // esi
  stack_st *v6; // eax
  char *v7; // eax

  v4 = 0;
  v5 = ASN1_item_new(&local_it_43);
  if ( !v5 )
    return 0;
  *(_DWORD *)v5 = OBJ_nid2obj(a1, nid);
  *((_DWORD *)v5 + 1) = 0;
  v6 = sk_new_null();
  *((_DWORD *)v5 + 2) = v6;
  if ( !v6 || (v7 = (char *)ASN1_TYPE_new(), (v4 = (asn1_type_st *)v7) == 0) || !sk_push(*((stack_st **)v5 + 2), v7) )
  {
    ASN1_item_free(v5, &local_it_43);
    if ( v4 )
      ASN1_TYPE_free(v4);
    return 0;
  }
  ASN1_TYPE_set(v4, atrtype, value);
  return (x509_attributes_st *)v5;
}
