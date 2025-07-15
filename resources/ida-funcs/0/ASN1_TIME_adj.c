asn1_string_st *__usercall ASN1_TIME_adj@<eax>(
        int a1@<ebx>,
        asn1_string_st *s,
        __int64 t,
        int offset_day,
        int offset_sec)
{
  tm *v5; // eax
  tm *v6; // ebx
  asn1_string_st *v7; // eax
  int v8; // esi
  int v9; // edi
  int tm_year; // ebx
  tm result; // [esp+4h] [ebp-24h] BYREF

  v5 = OPENSSL_gmtime(a1, &t, &result);
  v6 = v5;
  if ( v5 )
  {
    v8 = offset_day;
    v9 = offset_sec;
    if ( !offset_day && !offset_sec || (v7 = (asn1_string_st *)OPENSSL_gmtime_adj(v5, offset_day, offset_sec)) != 0 )
    {
      tm_year = v6->tm_year;
      if ( tm_year < 50 || tm_year >= 150 )
        return ASN1_GENERALIZEDTIME_adj(s, t, v8, v9);
      else
        return ASN1_UTCTIME_adj(s, t, v8, v9);
    }
  }
  else
  {
    ERR_put_error(0, 0xDu, 217, 173, ".\\crypto\\asn1\\a_time.c", 115);
    return 0;
  }
  return v7;
}
