int __cdecl ASN1_TYPE_set1(asn1_object_st *a, const char *type, asn1_object_st *value)
{
  asn1_object_st *v3; // esi
  asn1_object_st *v4; // eax
  int result; // eax
  asn1_string_st *v6; // eax

  v3 = value;
  if ( !value || type == (const char *)1 )
  {
    value = a;
    if ( a->ln )
      ASN1_primitive_free((struct ASN1_VALUE_st **)&value, 0);
    value->sn = type;
    if ( type == (const char *)1 )
    {
      result = 1;
      value->ln = (const char *)(unsigned __int8)-(v3 != 0);
    }
    else
    {
      value->ln = (const char *)v3;
      return 1;
    }
  }
  else if ( type == (const char *)6 )
  {
    v4 = OBJ_dup(value);
    if ( !v4 )
      return 0;
    ASN1_TYPE_set((asn1_type_st *)a, 6, v4);
    return 1;
  }
  else
  {
    v6 = ASN1_STRING_dup((const asn1_string_st *)value);
    if ( !v6 )
      return 0;
    ASN1_TYPE_set((asn1_type_st *)a, (int)type, v6);
    return 1;
  }
  return result;
}
