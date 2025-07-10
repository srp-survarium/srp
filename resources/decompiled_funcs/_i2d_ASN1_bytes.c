int __cdecl i2d_ASN1_bytes(asn1_string_st *a, unsigned __int8 **pp, int tag, char xclass)
{
  asn1_string_st *v4; // esi
  int result; // eax
  int v6; // ebx
  int length; // edi
  unsigned __int8 **v8; // ebp
  BOOL v9; // eax
  int v10; // [esp+4h] [ebp-4h]

  v4 = a;
  if ( !a )
    return 0;
  v6 = tag;
  if ( tag == 3 )
    return i2d_ASN1_BIT_STRING(a, pp);
  length = a->length;
  result = ASN1_object_size(0, a->length, tag);
  v8 = pp;
  v10 = result;
  if ( pp )
  {
    a = (asn1_string_st *)*pp;
    v9 = v6 == 16 || v6 == 17;
    ASN1_put_object((unsigned __int8 **)&a, v9, length, v6, xclass);
    memcpy((unsigned __int8 *)a, v4->data, v4->length);
    result = v10;
    *v8 = (unsigned __int8 *)a + v4->length;
  }
  return result;
}
