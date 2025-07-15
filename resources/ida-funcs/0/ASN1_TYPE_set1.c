int __usercall ASN1_TYPE_set1@<eax>(int a1@<ebx>, asn1_object_st *a, const char *type, asn1_object_st *value)
{
  const char *v4; // esi
  asn1_object_st *v5; // eax
  int result; // eax
  asn1_string_st *v7; // eax

  v4 = (const char *)value;
  if ( !value || type == (const char *)1 )
  {
    value = a;
    if ( a->ln )
      ASN1_primitive_free((struct ASN1_VALUE_st **)&value, 0);
    value->sn = type;
    if ( type == (const char *)1 )
    {
      result = 1;
      value->ln = (const char *)(unsigned __int8)-(v4 != 0);
    }
    else
    {
      value->ln = v4;
      return 1;
    }
  }
  else if ( type == (const char *)6 )
  {
    v5 = OBJ_dup(a1, value);
    if ( !v5 )
      return 0;
    ASN1_TYPE_set((asn1_type_st *)a, 6, (int)v5);
    return 1;
  }
  else
  {
    v7 = ASN1_STRING_dup(a1, (const asn1_string_st *)value);
    if ( !v7 )
      return 0;
    ASN1_TYPE_set((asn1_type_st *)a, (int)type, (int)v7);
    return 1;
  }
  return result;
}
