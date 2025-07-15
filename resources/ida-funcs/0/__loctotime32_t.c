int __cdecl __loctotime32_t(int yr, int mo, int dy, unsigned int hr, unsigned int mn, unsigned int sc, int dstflag)
{
  int v7; // esi
  int v8; // ebx
  int *v9; // eax
  int v10; // ecx
  unsigned int v11; // ecx
  int v12; // edi
  int v13; // edi
  tm tb; // [esp+Ch] [ebp-30h] BYREF
  int _Daylight_savings_bias; // [esp+30h] [ebp-Ch] BYREF
  int _Daylight; // [esp+34h] [ebp-8h] BYREF
  int _Timezone; // [esp+38h] [ebp-4h] BYREF
  int v19; // [esp+44h] [ebp+8h]

  v7 = yr - 1900;
  _Daylight = 0;
  _Daylight_savings_bias = 0;
  _Timezone = 0;
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
    v19 = dy + v10;
    if ( (!(v7 % 4) && v7 % 100 || !((v7 + 1900) % 400)) && v8 > 2 )
      ++v19;
    v11 = 60 * (mn + 60 * (hr + 24 * ((v7 + 299) / 400 - (v7 - 1) / 100 + v19 + (v7 - 1) / 4 + 365 * v7)));
    v12 = v11 + sc + 2085978496;
    __tzset(v11);
    if ( _get_daylight(sc, v12, &_Daylight) )
      _invoke_watson(sc, v12, v7);
    if ( _get_dstbias(sc, v12, &_Daylight_savings_bias) )
      _invoke_watson(sc, v12, v7);
    if ( _get_timezone(sc, v12, &_Timezone) )
      _invoke_watson(sc, v12, v7);
    v13 = _Timezone + v12;
    tb.tm_yday = v19;
    tb.tm_mon = mo - 1;
    tb.tm_hour = hr;
    tb.tm_year = v7;
    tb.tm_min = mn;
    tb.tm_sec = sc;
    if ( dstflag == 1 || dstflag == -1 && _Daylight && _isindst(&tb) )
      v13 += _Daylight_savings_bias;
    return v13;
  }
}
