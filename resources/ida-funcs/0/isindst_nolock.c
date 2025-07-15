BOOL __usercall isindst_nolock@<eax>(tm *tb@<edi>, unsigned int a2@<ebx>)
{
  int tm_year; // edx
  int v4; // eax
  int v5; // ecx
  int tm_yday; // edx
  int v7; // eax
  int endmonth; // [esp+4h] [ebp-Ch]
  int endweek; // [esp+8h] [ebp-8h]
  int daylight; // [esp+Ch] [ebp-4h] BYREF

  daylight = 0;
  if ( _get_daylight(&daylight) )
    _invoke_watson(a2, (unsigned int)tb, 0);
  if ( !daylight )
    return 0;
  tm_year = tb->tm_year;
  if ( tm_year != dststart.yr || tm_year != dstend.yr )
  {
    if ( tzapiused )
    {
      if ( tzinfo.DaylightDate.wYear )
        cvtdate(
          tzinfo.DaylightDate.wMonth,
          tzinfo.DaylightDate.wHour,
          1,
          0,
          tm_year,
          0,
          0,
          tzinfo.DaylightDate.wDay,
          tzinfo.DaylightDate.wMinute,
          tzinfo.DaylightDate.wSecond,
          tzinfo.DaylightDate.wMilliseconds);
      else
        cvtdate(
          tzinfo.DaylightDate.wMonth,
          tzinfo.DaylightDate.wHour,
          1,
          1,
          tm_year,
          tzinfo.DaylightDate.wDay,
          tzinfo.DaylightDate.wDayOfWeek,
          0,
          tzinfo.DaylightDate.wMinute,
          tzinfo.DaylightDate.wSecond,
          tzinfo.DaylightDate.wMilliseconds);
      if ( tzinfo.StandardDate.wYear )
        cvtdate(
          tzinfo.StandardDate.wMonth,
          tzinfo.StandardDate.wHour,
          0,
          0,
          tb->tm_year,
          0,
          0,
          tzinfo.StandardDate.wDay,
          tzinfo.StandardDate.wMinute,
          tzinfo.StandardDate.wSecond,
          tzinfo.StandardDate.wMilliseconds);
      else
        cvtdate(
          tzinfo.StandardDate.wMonth,
          tzinfo.StandardDate.wHour,
          0,
          1,
          tb->tm_year,
          tzinfo.StandardDate.wDay,
          tzinfo.StandardDate.wDayOfWeek,
          0,
          tzinfo.StandardDate.wMinute,
          tzinfo.StandardDate.wSecond,
          tzinfo.StandardDate.wMilliseconds);
    }
    else
    {
      v4 = 3;
      v5 = 2;
      endmonth = 11;
      endweek = 1;
      if ( tm_year < 107 )
      {
        v4 = 4;
        v5 = 1;
        endmonth = 10;
        endweek = 5;
      }
      cvtdate(v4, 2, 1, 1, tm_year, v5, 0, 0, 0, 0, 0);
      cvtdate(endmonth, 2, 0, 1, tb->tm_year, endweek, 0, 0, 0, 0, 0);
    }
  }
  tm_yday = tb->tm_yday;
  if ( dststart.yd >= dstend.yd )
  {
    if ( tm_yday < dstend.yd || tm_yday > dststart.yd )
      return 1;
    if ( tm_yday <= dstend.yd || tm_yday >= dststart.yd )
      goto LABEL_28;
    return 0;
  }
  if ( tm_yday < dststart.yd || tm_yday > dstend.yd )
    return 0;
  if ( tm_yday > dststart.yd && tm_yday < dstend.yd )
    return 1;
LABEL_28:
  v7 = 1000 * (tb->tm_sec + 60 * (tb->tm_min + 60 * tb->tm_hour));
  if ( tm_yday == dststart.yd )
    return v7 >= dststart.ms;
  else
    return v7 < dstend.ms;
}
