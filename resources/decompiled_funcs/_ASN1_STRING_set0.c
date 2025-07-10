void __cdecl ASN1_STRING_set0(asn1_string_st *str, unsigned __int8 *data, int len)
{
  if ( str->data )
    CRYPTO_free(str->data);
  str->data = data;
  str->length = len;
}
