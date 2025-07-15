void __cdecl vostok::logging::fill_local_time(char (*dest)[512], bool brief)
{
  _SYSTEMTIME date_time; // [esp+0h] [ebp-10h] BYREF

  GetLocalTime(&date_time);
  if ( brief )
    vostok::sprintf<512>(dest, "%02d:%02d:%02d", date_time.wHour, date_time.wMinute, date_time.wSecond);
  else
    vostok::sprintf<512>(
      dest,
      "%02d:%02d:%02d:%03d",
      date_time.wHour,
      date_time.wMinute,
      date_time.wSecond,
      date_time.wMilliseconds);
}
