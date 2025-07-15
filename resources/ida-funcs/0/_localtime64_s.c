int __usercall _localtime64_s@<eax>(int a1@<edi>, tm *ptm, __int64 *ptime)
{
  int result; // eax
  int v4; // eax
  unsigned int v5; // ecx
  __int64 v6; // kr00_8
  __int64 v7; // kr10_8
  __int64 v8; // kr20_8
  __int64 v9; // rax
  int v10; // ecx
  int v11; // edx
  __int64 timp; // [esp+8h] [ebp-14h] BYREF
  int _Daylight_savings_bias; // [esp+10h] [ebp-Ch] BYREF
  int _Daylight; // [esp+14h] [ebp-8h] BYREF
  int _Timezone; // [esp+18h] [ebp-4h] BYREF

  _Daylight = 0;
  _Daylight_savings_bias = 0;
  _Timezone = 0;
  if ( !ptm )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, 22);
    return 22;
  }
  memset((int)ptm, 255, sizeof(tm));
  if ( !ptime )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 22);
    return 22;
  }
  v4 = *((_DWORD *)ptime + 1);
  v5 = *(_DWORD *)ptime;
  if ( v4 < 0 || __SPAIR64__(v4, v5) > 0x793406FFFLL )
  {
    *_errno() = 22;
    return 22;
  }
  __tzset(v5);
  if ( _get_daylight(0, (int)ptime, &_Daylight) )
    _invoke_watson(0, (int)ptime, (int)ptm);
  if ( _get_dstbias(0, (int)ptime, &_Daylight_savings_bias) )
    _invoke_watson(0, (int)ptime, (int)ptm);
  if ( _get_timezone(0, (int)ptime, &_Timezone) )
    _invoke_watson(0, (int)ptime, (int)ptm);
  if ( *ptime > 259200 )
  {
    timp = *ptime - _Timezone;
    result = _gmtime64_s(0, ptm, &timp);
    if ( result )
      return result;
    if ( _Daylight && _isindst(ptm) )
    {
      timp -= _Daylight_savings_bias;
      result = _gmtime64_s(0, ptm, &timp);
      if ( result )
        return result;
      ptm->tm_isdst = 1;
    }
    return 0;
  }
  result = _gmtime64_s(0, ptm, ptime);
  if ( result )
    return result;
  if ( _Daylight && _isindst(ptm) )
  {
    v6 = ptm->tm_sec - (__int64)(_Daylight_savings_bias + _Timezone);
    ptm->tm_isdst = 1;
  }
  else
  {
    v6 = ptm->tm_sec - (__int64)_Timezone;
  }
  ptm->tm_sec = v6 % 60;
  if ( v6 % 60 < 0 )
  {
    ptm->tm_sec = v6 % 60 + 60;
    v6 = __PAIR64__((unsigned int)__CFADD__((_DWORD)v6, -60) + HIDWORD(v6) - 1, (int)v6 - 60);
  }
  v7 = ptm->tm_min + v6 / 60;
  ptm->tm_min = v7 % 60;
  if ( v7 % 60 < 0 )
  {
    ptm->tm_min = v7 % 60 + 60;
    v7 -= 60;
  }
  v8 = ptm->tm_hour + v7 / 60;
  ptm->tm_hour = v8 % 24;
  if ( v8 % 24 < 0 )
  {
    ptm->tm_hour = v8 % 24 + 24;
    v8 -= 24;
  }
  v9 = v8 / 24;
  v10 = v8 / 24;
  if ( (((unsigned __int64)(v8 / 24) >> 32) & 0x80000000) != 0LL )
  {
    HIDWORD(v9) = ((int)v9 + ptm->tm_wday + 7) % 7;
    ptm->tm_mday += v9;
    LODWORD(v9) = ptm->tm_mday;
    ptm->tm_wday = HIDWORD(v9);
    if ( (int)v9 <= 0 )
    {
      ptm->tm_yday += v10 + 365;
      --ptm->tm_year;
      ptm->tm_mday = v9 + 31;
      ptm->tm_mon = 11;
      return 0;
    }
  }
  else
  {
    if ( v9 <= 0 )
      return 0;
    v11 = (v10 + ptm->tm_wday) % 7;
    ptm->tm_mday += v10;
    ptm->tm_wday = v11;
  }
  ptm->tm_yday += v10;
  return 0;
}
