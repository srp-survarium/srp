asn1_string_st *__cdecl ASN1_UTCTIME_adj(asn1_string_st *s, __int64 t, int offset_day, int offset_sec)
{
  asn1_string_st *v4; // ebx
  asn1_string_st *v5; // eax
  tm *v6; // esi
  int tm_year; // eax
  char *data; // edi
  tm result; // [esp+4h] [ebp-24h] BYREF

  v4 = s;
  if ( s || (v5 = ASN1_STRING_type_new(23), (v4 = v5) != 0) )
  {
    v6 = OPENSSL_gmtime(&t, &result);
    if ( !v6 || (offset_day || offset_sec) && !OPENSSL_gmtime_adj(v6, offset_day, offset_sec) )
      return 0;
    tm_year = v6->tm_year;
    if ( tm_year < 50 || tm_year >= 150 )
    {
      return 0;
    }
    else
    {
      data = (char *)v4->data;
      if ( !data || v4->length < 0x14u )
      {
        data = (char *)CRYPTO_malloc(20, ".\\crypto\\asn1\\a_utctm.c", 221);
        if ( !data )
        {
          ERR_put_error(0xDu, 218, 65, ".\\crypto\\asn1\\a_utctm.c", 224);
          return 0;
        }
        if ( v4->data )
          CRYPTO_free(v4->data);
        v4->data = (unsigned __int8 *)data;
      }
      BIO_snprintf(
        data,
        0x14u,
        "%02d%02d%02d%02d%02d%02dZ",
        v6->tm_year % 100,
        v6->tm_mon + 1,
        v6->tm_mday,
        v6->tm_hour,
        v6->tm_min,
        v6->tm_sec);
      v4->length = strlen(data);
      v4->type = 23;
      return v4;
    }
  }
  return v5;
}
