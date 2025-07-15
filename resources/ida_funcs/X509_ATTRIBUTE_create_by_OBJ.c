x509_attributes_st *__cdecl X509_ATTRIBUTE_create_by_OBJ(
        x509_attributes_st **attr,
        const asn1_object_st *obj,
        int atrtype,
        unsigned __int8 *data,
        int len)
{
  x509_attributes_st *v5; // esi

  if ( attr && (v5 = *attr) != 0 || (v5 = X509_ATTRIBUTE_new()) != 0 )
  {
    if ( obj
      && (ASN1_OBJECT_free(v5->object), v5->object = OBJ_dup(obj), X509_ATTRIBUTE_set1_data(v5, atrtype, data, len)) )
    {
      if ( attr && !*attr )
        *attr = v5;
      return v5;
    }
    else
    {
      if ( !attr || v5 != *attr )
        X509_ATTRIBUTE_free(v5);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0xBu, 137, 65, ".\\crypto\\x509\\x509_att.c", 237);
    return 0;
  }
}
