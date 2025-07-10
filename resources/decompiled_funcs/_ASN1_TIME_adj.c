asn1_string_st *__cdecl ASN1_TIME_adj(asn1_string_st *s, __int64 t, int offset_day, int offset_sec)
{
  tm *v4; // eax
  tm *v5; // ebx
  asn1_string_st *v6; // eax
  int v7; // esi
  int v8; // edi
  int tm_year; // ebx
  tm result; // [esp+4h] [ebp-24h] BYREF

  v4 = OPENSSL_gmtime(&t, &result);
  v5 = v4;
  if ( v4 )
  {
    v7 = offset_day;
    v8 = offset_sec;
    if ( !offset_day && !offset_sec || (v6 = (asn1_string_st *)OPENSSL_gmtime_adj(v4, offset_day, offset_sec)) != 0 )
    {
      tm_year = v5->tm_year;
      if ( tm_year < 50 || tm_year >= 150 )
        return ASN1_GENERALIZEDTIME_adj(s, t, v7, v8);
      else
        return ASN1_UTCTIME_adj(s, t, v7, v8);
    }
  }
  else
  {
    ERR_put_error(0xDu, 217, 173, ".\\crypto\\asn1\\a_time.c", 115);
    return 0;
  }
  return v6;
}
