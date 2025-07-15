int __usercall _ftime64_s@<eax>(int a1@<ebx>, __timeb64 *tp)
{
  unsigned int dwLowDateTime; // ebx
  unsigned int dwHighDateTime; // edi
  DWORD v5; // eax
  unsigned __int64 v6; // [esp+8h] [ebp-C4h]
  _FILETIME SystemTimeAsFileTime; // [esp+10h] [ebp-BCh] BYREF
  int v8; // [esp+18h] [ebp-B4h] BYREF
  _TIME_ZONE_INFORMATION TimeZoneInformation; // [esp+1Ch] [ebp-B0h] BYREF

  v8 = 0;
  if ( tp )
  {
    __tzset(0);
    if ( _get_timezone(a1, 0, &v8) )
      _invoke_watson(a1, 0, (int)tp);
    tp->timezone = v8 / 60;
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    dwLowDateTime = SystemTimeAsFileTime.dwLowDateTime;
    dwHighDateTime = SystemTimeAsFileTime.dwHighDateTime;
    v6 = *(unsigned __int64 *)&SystemTimeAsFileTime / 0x23C34600;
    if ( *(unsigned __int64 *)&SystemTimeAsFileTime / 0x23C34600 != elapsed_minutes_cache )
    {
      v5 = GetTimeZoneInformation(&TimeZoneInformation);
      if ( v5 == -1 )
        dstflag_cache = -1;
      else
        dstflag_cache = v5 == 2 && TimeZoneInformation.DaylightDate.wMonth && TimeZoneInformation.DaylightBias;
      dwHighDateTime = SystemTimeAsFileTime.dwHighDateTime;
      dwLowDateTime = SystemTimeAsFileTime.dwLowDateTime;
      elapsed_minutes_cache = v6;
    }
    tp->dstflag = dstflag_cache;
    tp->millitm = __PAIR64__(dwHighDateTime, dwLowDateTime) / 0x2710 % 0x3E8;
    tp->time = __PAIR64__(__CFADD__(dwLowDateTime, 717324288) + dwHighDateTime - 27111903, dwLowDateTime + 717324288)
             / (unsigned int)&vostok::memory::s_CRT_arena[613496];
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, 22);
    return 22;
  }
}
