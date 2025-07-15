int __cdecl ASN1_TYPE_set_int_octetstring(asn1_type_st *a, int num, unsigned __int8 *data, int len)
{
  int v4; // edi
  int v5; // edi
  int v6; // ebx
  asn1_string_st *v7; // eax
  asn1_string_st *v8; // esi
  unsigned __int8 *v10; // ecx
  unsigned __int8 *pp; // [esp+10h] [ebp-48h] BYREF
  asn1_string_st aa; // [esp+14h] [ebp-44h] BYREF
  asn1_string_st v13; // [esp+24h] [ebp-34h] BYREF
  char v14; // [esp+34h] [ebp-24h] BYREF

  v13.data = data;
  aa.data = (unsigned __int8 *)&v14;
  aa.length = 32;
  v13.type = 4;
  v13.length = len;
  ASN1_INTEGER_set(&aa, num);
  v4 = i2d_ASN1_INTEGER(&aa, 0);
  v5 = i2d_ASN1_bytes(&v13, 0, 4, 0) + v4;
  v6 = ASN1_object_size(1, v5, 16);
  v7 = ASN1_STRING_new();
  v8 = v7;
  if ( !v7 )
    return 0;
  if ( !ASN1_STRING_set(v7, 0, v6) )
  {
    ASN1_STRING_free(v8);
    return 0;
  }
  v10 = v8->data;
  v8->length = v6;
  pp = v10;
  ASN1_put_object(&pp, 1, v5, 16, 0);
  i2d_ASN1_INTEGER(&aa, &pp);
  i2d_ASN1_bytes(&v13, &pp, 4, 0);
  ASN1_TYPE_set(a, 16, v8);
  return 1;
}
