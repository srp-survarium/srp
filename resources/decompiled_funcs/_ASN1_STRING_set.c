int __cdecl ASN1_STRING_set(asn1_string_st *str, char *_data, int len)
{
  int v3; // edi
  unsigned __int8 *data; // eax
  unsigned __int8 *v6; // ebx

  v3 = len;
  if ( len < 0 )
  {
    if ( !_data )
      return 0;
    v3 = strlen(_data);
  }
  if ( str->length >= v3 && (data = str->data) != 0
    || ((v6 = str->data) != 0
      ? (data = (unsigned __int8 *)CRYPTO_realloc(v6, v3 + 1, ".\\crypto\\asn1\\asn1_lib.c", 388))
      : (data = (unsigned __int8 *)CRYPTO_malloc(v3 + 1, ".\\crypto\\asn1\\asn1_lib.c", 386)),
        (str->data = data) != 0) )
  {
    str->length = v3;
    if ( _data )
    {
      memcpy(data, (unsigned __int8 *)_data, v3);
      str->data[v3] = 0;
    }
    return 1;
  }
  else
  {
    ERR_put_error(0xDu, 186, 65, ".\\crypto\\asn1\\asn1_lib.c", 392);
    str->data = v6;
    return 0;
  }
}
