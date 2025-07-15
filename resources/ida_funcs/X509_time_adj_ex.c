asn1_string_st *__cdecl X509_time_adj_ex(asn1_string_st *s, int offset_day, int offset_sec, __int64 *in_tm)
{
  __int64 v4; // kr00_8
  int type; // esi
  __int64 timeptr; // [esp+0h] [ebp-8h] BYREF

  if ( in_tm )
  {
    v4 = *in_tm;
    LODWORD(timeptr) = *(_DWORD *)in_tm;
    HIDWORD(timeptr) = HIDWORD(v4);
  }
  else
  {
    _time64(&timeptr);
    v4 = timeptr;
  }
  if ( !s || (s->flags & 0x40) != 0 )
    return ASN1_TIME_adj(s, v4, offset_day, offset_sec);
  type = s->type;
  if ( type == 23 )
    return ASN1_UTCTIME_adj(s, v4, offset_day, offset_sec);
  if ( type == 24 )
    return ASN1_GENERALIZEDTIME_adj(s, v4, offset_day, offset_sec);
  else
    return ASN1_TIME_adj(s, v4, offset_day, offset_sec);
}
