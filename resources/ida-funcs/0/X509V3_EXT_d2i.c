struct ASN1_VALUE_st *__usercall X509V3_EXT_d2i@<eax>(int a1@<edi>, X509_extension_st *ext)
{
  void *v2; // eax
  const v3_ext_method *nid; // eax
  asn1_string_st *value; // ecx
  int (*it)(void); // edx
  const ASN1_ITEM_st *v7; // eax
  unsigned __int8 *in; // [esp+4h] [ebp-4h] BYREF

  v2 = OBJ_obj2nid(ext->object);
  if ( !v2 )
    return 0;
  nid = X509V3_EXT_get_nid(a1, (int)v2);
  if ( !nid )
    return 0;
  value = ext->value;
  in = value->data;
  it = (int (*)(void))nid->it;
  if ( !it )
    return (struct ASN1_VALUE_st *)nid->d2i(0, (const unsigned __int8 **)&in, value->length);
  v7 = (const ASN1_ITEM_st *)it();
  return ASN1_item_d2i(0, &in, (const unsigned __int8 *)ext->value->length, v7);
}
