int __cdecl X509_ATTRIBUTE_set1_data(x509_attributes_st *attr, int attrtype, __m128i *data, int len)
{
  char *v4; // ebx
  asn1_string_st *v5; // esi
  void *v7; // eax
  int v8; // ebp
  asn1_string_st *v9; // eax
  char *v10; // eax
  asn1_type_st *v11; // eax
  int type; // [esp+8h] [ebp-8h]

  v4 = (char *)attr;
  v5 = 0;
  type = 0;
  if ( !attr )
    return 0;
  if ( (attrtype & 0x1000) != 0 )
  {
    v7 = OBJ_obj2nid(attr->object);
    v8 = len;
    v9 = ASN1_STRING_set_by_NID(attrtype, 0, (unsigned __int8 *)data, len, attrtype, (int)v7);
    v5 = v9;
    if ( !v9 )
    {
      ERR_put_error((int)attr, 0xBu, 138, 13, ".\\crypto\\x509\\x509_att.c", 295);
      return 0;
    }
    type = v9->type;
  }
  else
  {
    v8 = len;
    if ( len != -1 )
    {
      v5 = ASN1_STRING_type_new((int)attr, attrtype);
      if ( !v5 || !ASN1_STRING_set(v5, data, len) )
        goto err_138;
      type = attrtype;
    }
  }
  v10 = (char *)sk_new_null();
  attr->value.ptr = v10;
  if ( !v10 )
    goto err_138;
  attr->single = 0;
  if ( !attrtype )
    return 1;
  v11 = ASN1_TYPE_new();
  v4 = (char *)v11;
  if ( !v11 )
    goto err_138;
  if ( v8 != -1 || (attrtype & 0x1000) != 0 )
  {
    ASN1_TYPE_set(v11, type, (int)v5);
    goto LABEL_19;
  }
  if ( !ASN1_TYPE_set1((int)v11, (asn1_object_st *)v11, (const char *)attrtype, (asn1_object_st *)data) )
  {
err_138:
    ERR_put_error((int)v4, 0xBu, 138, 65, ".\\crypto\\x509\\x509_att.c", 323);
    return 0;
  }
LABEL_19:
  if ( !sk_push((stack_st *)attr->value.ptr, v4) )
    goto err_138;
  return 1;
}
