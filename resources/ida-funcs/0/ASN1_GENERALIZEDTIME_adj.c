asn1_string_st *__cdecl ASN1_GENERALIZEDTIME_adj(asn1_string_st *s, __int64 t, int offset_day, int offset_sec)
{
  asn1_string_st *v4; // ebx
  asn1_string_st *v5; // eax
  tm *v6; // esi
  char *data; // edi
  tm result; // [esp+4h] [ebp-24h] BYREF

  v4 = s;
  if ( s || (v5 = ASN1_STRING_type_new(24), (v4 = v5) != 0) )
  {
    v6 = OPENSSL_gmtime((int)v4, &t, &result);
    if ( !v6 || (offset_day || offset_sec) && !OPENSSL_gmtime_adj(v6, offset_day, offset_sec) )
      return 0;
    data = (char *)v4->data;
    if ( !data || v4->length < 0x14u )
    {
      data = (char *)CRYPTO_malloc(20, ".\\crypto\\asn1\\a_gentm.c", 243);
      if ( !data )
      {
        ERR_put_error((int)v4, 0xDu, 216, 65, ".\\crypto\\asn1\\a_gentm.c", 247);
        return 0;
      }
      if ( v4->data )
        CRYPTO_free(v4->data);
      v4->data = (unsigned __int8 *)data;
    }
    BIO_snprintf(
      data,
      0x14u,
      "%04d%02d%02d%02d%02d%02dZ",
      v6->tm_year + 1900,
      v6->tm_mon + 1,
      v6->tm_mday,
      v6->tm_hour,
      v6->tm_min,
      v6->tm_sec);
    v4->length = strlen(data);
    v4->type = 24;
    return v4;
  }
  return v5;
}
