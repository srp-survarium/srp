int __cdecl __loctotime64_t(int yr, int mo, int dy, int hr, int mn, int sc, int dstflag)
{
  int v7; // esi
  int v8; // ebx
  int *v9; // eax
  int v10; // ecx
  __int64 v11; // kr10_8
  int v12; // edi
  tm tb; // [esp+Ch] [ebp-34h] BYREF
  int v15; // [esp+30h] [ebp-10h]
  int v16; // [esp+34h] [ebp-Ch] BYREF
  int v17; // [esp+38h] [ebp-8h] BYREF
  int v18; // [esp+3Ch] [ebp-4h] BYREF
  int v19; // [esp+48h] [ebp+8h]

  v7 = yr - 1900;
  v17 = 0;
  v16 = 0;
  v18 = 0;
  if ( yr - 1900 < 70
    || v7 > 1100
    || (v8 = mo, (unsigned int)(mo - 1) > 0xB)
    || (unsigned int)hr > 0x17
    || (unsigned int)mn > 0x3B
    || (unsigned int)sc > 0x3B
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
    v15 = (unsigned __int64)(365 * (v7 - 70LL) + (v7 + 299) / 400 - (v7 - 1) / 100 + (v7 - 1) / 4 - 17) >> 32;
    v11 = sc
        + 60 * (mn + 60 * (hr + 24 * (v19 + 365 * (v7 - 70LL) + (v7 + 299) / 400 - (v7 - 1) / 100 + (v7 - 1) / 4 - 17)));
    __tzset(v11);
    if ( _get_daylight(SHIDWORD(v11), v11, &v17) )
      _invoke_watson(SHIDWORD(v11), v11, v7);
    if ( _get_dstbias(SHIDWORD(v11), v11, &v16) )
      _invoke_watson(SHIDWORD(v11), v11, v7);
    if ( _get_timezone(SHIDWORD(v11), v11, &v18) )
      _invoke_watson(SHIDWORD(v11), v11, v7);
    tb.tm_yday = v19;
    v12 = v18 + v11;
    tb.tm_mon = mo - 1;
    tb.tm_hour = hr;
    tb.tm_min = mn;
    tb.tm_year = v7;
    tb.tm_sec = sc;
    if ( dstflag == 1 || dstflag == -1 && v17 && _isindst((unsigned __int64)(v18 + v11) >> 32, &tb) )
      v12 += v16;
    return v12;
  }
}
