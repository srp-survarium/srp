void __usercall tzset_nolock(unsigned int a1@<edi>, unsigned int a2@<esi>)
{
  unsigned __int8 *v2; // eax
  unsigned __int8 *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  char **v7; // edi
  const char *v8; // esi
  char v9; // al
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // esi
  int negdiff; // [esp+14h] [ebp-38h]
  UINT lc_cp; // [esp+18h] [ebp-34h]
  int defused; // [esp+1Ch] [ebp-30h] BYREF
  int nochange; // [esp+20h] [ebp-2Ch]
  int dstbias; // [esp+24h] [ebp-28h] BYREF
  int daylight; // [esp+28h] [ebp-24h] BYREF
  char **tzname; // [esp+2Ch] [ebp-20h]
  int timezone; // [esp+30h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  negdiff = 0;
  nochange = 0;
  timezone = 0;
  daylight = 0;
  dstbias = 0;
  _lock(7);
  ms_exc.registration.TryLevel = 0;
  tzname = __tzname();
  if ( _get_timezone(&timezone) )
    _invoke_watson(0, a1, a2);
  if ( _get_daylight(&daylight) )
    _invoke_watson(0, a1, a2);
  if ( _get_dstbias(&dstbias) )
    _invoke_watson(0, a1, a2);
  lc_cp = ___lc_codepage_func();
  tzapiused = 0;
  dstend.yr = -1;
  dststart.yr = -1;
  v2 = (unsigned __int8 *)_getenv_helper_nolock("TZ");
  v3 = v2;
  if ( !v2 || !*v2 )
  {
    if ( lastTZ )
    {
      free(lastTZ);
      lastTZ = 0;
    }
    if ( GetTimeZoneInformation(&tzinfo) != -1 )
    {
      tzapiused = 1;
      timezone = 60 * tzinfo.Bias;
      if ( tzinfo.StandardDate.wMonth )
        timezone = 60 * tzinfo.StandardBias + 60 * tzinfo.Bias;
      if ( tzinfo.DaylightDate.wMonth && tzinfo.DaylightBias )
      {
        daylight = 1;
        dstbias = 60 * (tzinfo.DaylightBias - tzinfo.StandardBias);
      }
      else
      {
        daylight = 0;
        dstbias = 0;
      }
      if ( !WideCharToMultiByte(lc_cp, 0, tzinfo.StandardName, -1, *tzname, 63, 0, &defused) || defused )
        **tzname = 0;
      else
        (*tzname)[63] = 0;
      if ( !WideCharToMultiByte(lc_cp, 0, tzinfo.DaylightName, -1, tzname[1], 63, 0, &defused) || defused )
        *tzname[1] = 0;
      else
        tzname[1][63] = 0;
    }
    goto LABEL_33;
  }
  if ( lastTZ )
  {
    strcmp(v2, (unsigned __int8 *)lastTZ);
    if ( !v4 )
    {
LABEL_33:
      nochange = 1;
      goto LABEL_34;
    }
    if ( lastTZ )
      free(lastTZ);
  }
  strlen(v3);
  lastTZ = (char *)_malloc_crt(v5 + 1);
  if ( !lastTZ )
    goto LABEL_33;
  strlen(v3);
  if ( strcpy_s(lastTZ, v6 + 1, (const char *)v3) )
    _invoke_watson(0, 0xFFFFFFFF, (unsigned int)v3);
LABEL_34:
  _set_timezone(timezone);
  _set_daylight(daylight);
  _set_dstbias(dstbias);
  ms_exc.registration.TryLevel = -2;
  _unlock(7);
  if ( !nochange )
  {
    v7 = tzname;
    if ( strncpy_s(*tzname, 0x40u, (const char *)v3, 3u) )
      _invoke_watson(0, (unsigned int)v7, (unsigned int)v3);
    v8 = (const char *)(v3 + 3);
    if ( *v8 == 45 )
    {
      negdiff = 1;
      ++v8;
    }
    timezone = 3600 * atol(v8);
    while ( 1 )
    {
      v9 = *v8;
      if ( *v8 != 43 && (v9 < 48 || v9 > 57) )
        break;
      ++v8;
    }
    if ( *v8 == 58 )
    {
      v10 = atol(++v8);
      timezone += 60 * v10;
      while ( *v8 >= 48 && *v8 <= 57 )
        ++v8;
      if ( *v8 == 58 )
      {
        v11 = atol(++v8);
        timezone += v11;
        while ( *v8 >= 48 && *v8 <= 57 )
          ++v8;
      }
    }
    if ( negdiff )
      timezone = -timezone;
    daylight = *v8;
    if ( daylight )
    {
      if ( strncpy_s(v7[1], 0x40u, v8, 3u) )
        _invoke_watson(0, (unsigned int)v7, (unsigned int)v8);
    }
    else
    {
      *v7[1] = 0;
    }
    v12 = timezone;
    *__timezone() = v12;
    v13 = daylight;
    *__daylight() = v13;
  }
}
