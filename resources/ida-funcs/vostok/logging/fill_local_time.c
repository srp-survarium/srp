void __cdecl vostok::logging::fill_local_time(char (*dest)[512], bool brief)
{
  _SYSTEMTIME SystemTime; // [esp+0h] [ebp-10h] BYREF

  GetLocalTime(&SystemTime);
  if ( brief )
    vostok::sprintf<512>(dest, "%02d:%02d:%02d", SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond);
  else
    vostok::sprintf<512>(
      dest,
      "%02d:%02d:%02d.%03d",
      SystemTime.wHour,
      SystemTime.wMinute,
      SystemTime.wSecond,
      SystemTime.wMilliseconds);
}
