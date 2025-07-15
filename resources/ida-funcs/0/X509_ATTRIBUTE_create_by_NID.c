x509_attributes_st *__usercall X509_ATTRIBUTE_create_by_NID@<eax>(
        int a1@<ebx>,
        x509_attributes_st **attr,
        unsigned int nid,
        int atrtype,
        __m128i *data,
        int len)
{
  asn1_object_st *v6; // esi
  x509_attributes_st *v8; // edi

  v6 = OBJ_nid2obj(a1, nid);
  if ( v6 )
  {
    v8 = X509_ATTRIBUTE_create_by_OBJ(a1, attr, v6, atrtype, data, len);
    if ( !v8 )
      ASN1_OBJECT_free(v6);
    return v8;
  }
  else
  {
    ERR_put_error(a1, 0xBu, 136, 109, ".\\crypto\\x509\\x509_att.c", 220);
    return 0;
  }
}
