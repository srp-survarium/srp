int __cdecl ASN1_STRING_to_UTF8(unsigned __int8 **out, asn1_string_st *in)
{
  unsigned int type; // eax
  int v3; // eax
  int result; // eax
  unsigned __int8 *data; // [esp-10h] [ebp-24h]
  int length; // [esp-Ch] [ebp-20h]
  asn1_string_st *outa; // [esp+0h] [ebp-14h] BYREF
  int v8; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v9; // [esp+Ch] [ebp-8h]

  outa = (asn1_string_st *)&v8;
  if ( !in )
    return -1;
  type = in->type;
  if ( type > 0x1E )
    return -1;
  v3 = tag2nbyte[type];
  if ( v3 == -1 )
    return -1;
  length = in->length;
  data = in->data;
  v9 = 0;
  result = ASN1_mbstring_copy(&outa, data, length, v3 | 0x1000, 0x2000u);
  if ( result >= 0 )
  {
    *out = v9;
    return v8;
  }
  return result;
}
