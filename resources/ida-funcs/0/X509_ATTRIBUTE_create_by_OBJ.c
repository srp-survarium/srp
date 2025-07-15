x509_attributes_st *__usercall X509_ATTRIBUTE_create_by_OBJ@<eax>(
        int a1@<ebx>,
        x509_attributes_st **attr,
        const asn1_object_st *obj,
        int atrtype,
        __m128i *data,
        int len)
{
  x509_attributes_st *v6; // esi

  if ( attr && (v6 = *attr) != 0 || (v6 = X509_ATTRIBUTE_new()) != 0 )
  {
    if ( obj
      && (ASN1_OBJECT_free(v6->object),
          v6->object = OBJ_dup((int)obj, obj),
          X509_ATTRIBUTE_set1_data(v6, atrtype, data, len)) )
    {
      if ( attr && !*attr )
        *attr = v6;
      return v6;
    }
    else
    {
      if ( !attr || v6 != *attr )
        X509_ATTRIBUTE_free(v6);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0xBu, 137, 65, ".\\crypto\\x509\\x509_att.c", 237);
    return 0;
  }
}
