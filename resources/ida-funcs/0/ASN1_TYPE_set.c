void __cdecl ASN1_TYPE_set(asn1_type_st *a, int type, int value)
{
  int v3; // eax

  if ( a->value.boolean )
    ASN1_primitive_free((struct ASN1_VALUE_st **)&a, 0);
  v3 = type;
  a->type = type;
  if ( v3 == 1 )
    a->value.boolean = (unsigned __int8)-(value != 0);
  else
    a->value.boolean = value;
}
