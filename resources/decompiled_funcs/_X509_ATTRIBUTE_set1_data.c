int __cdecl X509_ATTRIBUTE_set1_data(x509_attributes_st *attr, int attrtype, unsigned __int8 *data, int len)
{
  asn1_string_st *v4; // esi
  int v6; // eax
  int v7; // ebp
  asn1_string_st *v8; // eax
  char *v9; // eax
  asn1_type_st *v10; // eax
  char *v11; // ebx
  int type; // [esp+8h] [ebp-8h]

  v4 = 0;
  type = 0;
  if ( !attr )
    return 0;
  if ( (attrtype & 0x1000) != 0 )
  {
    v6 = OBJ_obj2nid(attr->object);
    v7 = len;
    v8 = ASN1_STRING_set_by_NID(0, data, len, attrtype, v6);
    v4 = v8;
    if ( !v8 )
    {
      ERR_put_error(0xBu, 138, 13, ".\\crypto\\x509\\x509_att.c", 295);
      return 0;
    }
    type = v8->type;
  }
  else
  {
    v7 = len;
    if ( len != -1 )
    {
      v4 = ASN1_STRING_type_new(attrtype);
      if ( !v4 || !ASN1_STRING_set(v4, (char *)data, len) )
        goto err_136;
      type = attrtype;
    }
  }
  v9 = (char *)sk_new_null();
  attr->value.ptr = v9;
  if ( !v9 )
    goto err_136;
  attr->single = 0;
  if ( !attrtype )
    return 1;
  v10 = ASN1_TYPE_new();
  v11 = (char *)v10;
  if ( !v10 )
    goto err_136;
  if ( v7 != -1 || (attrtype & 0x1000) != 0 )
  {
    ASN1_TYPE_set(v10, type, v4);
    goto LABEL_19;
  }
  if ( !ASN1_TYPE_set1((asn1_object_st *)v10, (const char *)attrtype, (asn1_object_st *)data) )
  {
err_136:
    ERR_put_error(0xBu, 138, 65, ".\\crypto\\x509\\x509_att.c", 323);
    return 0;
  }
LABEL_19:
  if ( !sk_push((stack_st *)attr->value.ptr, v11) )
    goto err_136;
  return 1;
}
