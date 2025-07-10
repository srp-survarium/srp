struct ASN1_VALUE_st *__cdecl X509V3_EXT_d2i(X509_extension_st *ext)
{
  int v1; // eax
  const v3_ext_method *nid; // eax
  asn1_string_st *value; // ecx
  int (*it)(void); // edx
  const ASN1_ITEM_st *v6; // eax
  unsigned __int8 *in; // [esp+4h] [ebp-4h] BYREF

  v1 = OBJ_obj2nid(ext->object);
  if ( !v1 )
    return 0;
  nid = X509V3_EXT_get_nid(v1);
  if ( !nid )
    return 0;
  value = ext->value;
  in = value->data;
  it = (int (*)(void))nid->it;
  if ( !it )
    return (struct ASN1_VALUE_st *)nid->d2i(0, (const unsigned __int8 **)&in, value->length);
  v6 = (const ASN1_ITEM_st *)it();
  return ASN1_item_d2i(0, (const unsigned __int8 **)&in, ext->value->length, v6);
}
