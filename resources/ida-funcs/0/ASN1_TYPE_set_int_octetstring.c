int __usercall ASN1_TYPE_set_int_octetstring@<eax>(
        int a1@<ebx>,
        asn1_type_st *a,
        int num,
        unsigned __int8 *data,
        int len)
{
  int v5; // edi
  int v6; // edi
  int v7; // ebx
  asn1_string_st *v8; // eax
  asn1_string_st *v9; // esi
  unsigned __int8 *v11; // ecx
  unsigned __int8 *out; // [esp+10h] [ebp-48h] BYREF
  asn1_string_st aa; // [esp+14h] [ebp-44h] BYREF
  asn1_string_st v14; // [esp+24h] [ebp-34h] BYREF
  char v15; // [esp+34h] [ebp-24h] BYREF

  v14.data = data;
  aa.data = (unsigned __int8 *)&v15;
  aa.length = 32;
  v14.type = 4;
  v14.length = len;
  ASN1_INTEGER_set(a1, &aa, num);
  v5 = i2d_ASN1_INTEGER(&aa, 0);
  v6 = i2d_ASN1_bytes(&v14, 0, 4, 0) + v5;
  v7 = ASN1_object_size(1, v6, 16);
  v8 = ASN1_STRING_new(v7);
  v9 = v8;
  if ( !v8 )
    return 0;
  if ( !ASN1_STRING_set(v8, 0, v7) )
  {
    ASN1_STRING_free(v9);
    return 0;
  }
  v11 = v9->data;
  v9->length = v7;
  out = v11;
  ASN1_put_object(&out, 1, v6, 16, 0);
  i2d_ASN1_INTEGER(&aa, &out);
  i2d_ASN1_bytes(&v14, &out, 4, 0);
  ASN1_TYPE_set(a, 16, (int)v9);
  return 1;
}
