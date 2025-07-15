int __usercall _ftime64_s@<eax>(unsigned int a1@<ebx>, __timeb64 *tp)
{
  FT v3; // kr00_8
  DWORD TimeZoneInformation; // eax
  unsigned __int64 t; // [esp+8h] [ebp-C4h]
  FT nt_time; // [esp+10h] [ebp-BCh] BYREF
  int timezone; // [esp+18h] [ebp-B4h] BYREF
  _TIME_ZONE_INFORMATION tzinfo; // [esp+1Ch] [ebp-B0h] BYREF

  timezone = 0;
  if ( tp )
  {
    __tzset(0);
    if ( _get_timezone(a1, 0, &timezone) )
      _invoke_watson(a1, 0, (unsigned int)tp);
    tp->timezone = timezone / 60;
    GetSystemTimeAsFileTime((LPFILETIME)&nt_time);
    v3.ft_scalar = nt_time.ft_scalar;
    t = nt_time.ft_scalar / 0x23C34600;
    if ( nt_time.ft_scalar / 0x23C34600 != elapsed_minutes_cache )
    {
      TimeZoneInformation = GetTimeZoneInformation(&tzinfo);
      if ( TimeZoneInformation == -1 )
        dstflag_cache = -1;
      else
        dstflag_cache = TimeZoneInformation == 2 && tzinfo.DaylightDate.wMonth && tzinfo.DaylightBias;
      elapsed_minutes_cache = t;
      v3.ft_scalar = nt_time.ft_scalar;
    }
    tp->dstflag = dstflag_cache;
    tp->millitm = v3.ft_scalar / 0x2710 % 0x3E8;
    tp->time = __PAIR64__(
                 __CFADD__(v3.ft_struct.dwLowDateTime, 717324288) + v3.ft_struct.dwHighDateTime - 27111903,
                 v3.ft_struct.dwLowDateTime + 717324288)
             / (unsigned int)&stru_984D24.m_working_macro_list.m_buffer[33].m_store[300];
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, 0x16u);
    return 22;
  }
}
