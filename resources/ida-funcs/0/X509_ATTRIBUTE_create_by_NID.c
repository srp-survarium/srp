x509_attributes_st *__cdecl X509_ATTRIBUTE_create_by_NID(
        x509_attributes_st **attr,
        unsigned int nid,
        int atrtype,
        unsigned __int8 *data,
        int len)
{
  asn1_object_st *v5; // esi
  x509_attributes_st *v7; // edi

  v5 = OBJ_nid2obj(nid);
  if ( v5 )
  {
    v7 = X509_ATTRIBUTE_create_by_OBJ(attr, v5, atrtype, data, len);
    if ( !v7 )
      ASN1_OBJECT_free(v5);
    return v7;
  }
  else
  {
    ERR_put_error(0xBu, 136, 109, ".\\crypto\\x509\\x509_att.c", 220);
    return 0;
  }
}
