boost::posix_time::ptime *__cdecl boost::date_time::microsec_clock<boost::posix_time::ptime>::create_time(
        boost::posix_time::ptime *result)
{
  unsigned __int64 v1; // rax
  tm *v2; // ebx
  __int16 tm_mon; // ax
  int v4; // ecx
  boost::gregorian::date *v5; // ecx
  int v7; // [esp-Ch] [ebp-60h] BYREF
  int v8; // [esp-8h] [ebp-5Ch] BYREF
  tm *p_resulta; // [esp-4h] [ebp-58h] BYREF
  tm resulta; // [esp+Ch] [ebp-48h] BYREF
  boost::posix_time::time_duration time_of_day; // [esp+30h] [ebp-24h] BYREF
  __int64 t; // [esp+38h] [ebp-1Ch] BYREF
  _FILETIME SystemTimeAsFileTime; // [esp+44h] [ebp-10h] BYREF
  boost::gregorian::greg_year y[2]; // [esp+4Ch] [ebp-8h] BYREF

  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  v1 = (*(_QWORD *)&SystemTimeAsFileTime - 116444736000000000LL) / 0xAuLL;
  v7 = HIDWORD(v1);
  t = v1 / (unsigned int)&loc_F4240;
  p_resulta = &resulta;
  time_of_day.ticks_.value_ = v1 % (unsigned int)&loc_F4240;
  v2 = boost::date_time::c_time::gmtime(&t);
  boost::gregorian::greg_day::greg_day((boost::gregorian::greg_day *)&p_resulta, v2->tm_mday);
  tm_mon = v2->tm_mon;
  v8 = v4;
  v7 = v4;
  boost::gregorian::greg_month::greg_month((boost::gregorian::greg_month *)&v8, tm_mon + 1);
  boost::gregorian::greg_year::greg_year((boost::gregorian::greg_year *)&v7, LOWORD(v2->tm_year) + 1900);
  boost::gregorian::date::date(v5, y, (boost::gregorian::greg_month)v7, (boost::gregorian::greg_day)v8, (int)p_resulta);
  time_of_day.ticks_.value_ = boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
                                v2->tm_hour,
                                v2->tm_min,
                                v2->tm_sec,
                                LODWORD(time_of_day.ticks_.value_));
  boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>(
    &result->time_,
    (const boost::gregorian::date *)y,
    &time_of_day);
  return result;
}
