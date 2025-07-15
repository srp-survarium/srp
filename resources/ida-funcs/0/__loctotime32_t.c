unsigned int __cdecl __loctotime32_t(
        int yr,
        int mo,
        int dy,
        unsigned int hr,
        unsigned int mn,
        unsigned int sc,
        int dstflag)
{
  int v7; // esi
  int v8; // ebx
  int *v9; // eax
  int v10; // ecx
  unsigned int v11; // edi
  unsigned int v12; // edi
  tm tb; // [esp+Ch] [ebp-30h] BYREF
  int dstbias; // [esp+30h] [ebp-Ch] BYREF
  int daylight; // [esp+34h] [ebp-8h] BYREF
  int timezone; // [esp+38h] [ebp-4h] BYREF
  int tmpdays; // [esp+44h] [ebp+8h]

  v7 = yr - 1900;
  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( yr - 1900 < 70
    || v7 > 138
    || (v8 = mo, (unsigned int)(mo - 1) > 0xB)
    || hr > 0x17
    || mn > 0x3B
    || sc > 0x3B
    || dy < 1
    || (v9 = &_days[mo], v10 = *(v9 - 1), *v9 - v10 < dy)
    && ((v7 % 4 || !(v7 % 100)) && yr % 400 || (v8 = mo, mo != 2) || dy > 29) )
  {
    *_errno() = 22;
    return -1;
  }
  else
  {
    tmpdays = dy + v10;
    if ( (!(v7 % 4) && v7 % 100 || !((v7 + 1900) % 400)) && v8 > 2 )
      ++tmpdays;
    v11 = 60 * (mn + 60 * (hr + 24 * ((v7 + 299) / 400 - (v7 - 1) / 100 + tmpdays + (v7 - 1) / 4 + 365 * v7)))
        + sc
        + 2085978496;
    __tzset();
    if ( _get_daylight(&daylight) )
      _invoke_watson(sc, v11, v7);
    if ( _get_dstbias(&dstbias) )
      _invoke_watson(sc, v11, v7);
    if ( _get_timezone(&timezone) )
      _invoke_watson(sc, v11, v7);
    v12 = timezone + v11;
    tb.tm_yday = tmpdays;
    tb.tm_mon = mo - 1;
    tb.tm_hour = hr;
    tb.tm_year = v7;
    tb.tm_min = mn;
    tb.tm_sec = sc;
    if ( dstflag == 1 || dstflag == -1 && daylight && _isindst(&tb) )
      v12 += dstbias;
    return v12;
  }
}
