int __cdecl __loctotime64_t(int yr, int mo, int dy, unsigned int hr, unsigned int mn, unsigned int sc, int dstflag)
{
  int v7; // esi
  int v8; // ebx
  int *v9; // eax
  int v10; // ecx
  __int64 v11; // kr10_8
  int v12; // edi
  tm tb; // [esp+Ch] [ebp-34h] BYREF
  int v15; // [esp+30h] [ebp-10h]
  int dstbias; // [esp+34h] [ebp-Ch] BYREF
  int daylight; // [esp+38h] [ebp-8h] BYREF
  int timezone; // [esp+3Ch] [ebp-4h] BYREF
  int tmpdays; // [esp+48h] [ebp+8h]

  v7 = yr - 1900;
  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( yr - 1900 < 70
    || v7 > 1100
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
    v15 = (unsigned __int64)(365 * (v7 - 70LL) + (v7 + 299) / 400 - (v7 - 1) / 100 + (v7 - 1) / 4 - 17) >> 32;
    v11 = (int)sc
        + 60
        * ((int)mn
         + 60 * ((int)hr + 24 * (tmpdays + 365 * (v7 - 70LL) + (v7 + 299) / 400 - (v7 - 1) / 100 + (v7 - 1) / 4 - 17)));
    __tzset(v11);
    if ( _get_daylight(HIDWORD(v11), v11, &daylight) )
      _invoke_watson(HIDWORD(v11), v11, v7);
    if ( _get_dstbias(HIDWORD(v11), v11, &dstbias) )
      _invoke_watson(HIDWORD(v11), v11, v7);
    if ( _get_timezone(HIDWORD(v11), v11, &timezone) )
      _invoke_watson(HIDWORD(v11), v11, v7);
    tb.tm_yday = tmpdays;
    v12 = timezone + v11;
    tb.tm_mon = mo - 1;
    tb.tm_hour = hr;
    tb.tm_min = mn;
    tb.tm_year = v7;
    tb.tm_sec = sc;
    if ( dstflag == 1 || dstflag == -1 && daylight && _isindst((unsigned __int64)(timezone + v11) >> 32, &tb) )
      v12 += dstbias;
    return v12;
  }
}
