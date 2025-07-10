boost::posix_time::ptime *__cdecl boost::date_time::microsec_clock<boost::posix_time::ptime>::create_time(
        boost::posix_time::ptime *result,
        tm *(__cdecl *converter)(const __int64 *, tm *))
{
  int v2; // kr00_4
  __int16 v3; // ecx^2
  unsigned __int64 v5; // [esp-10h] [ebp-478h] BYREF
  __int64 v6; // [esp-8h] [ebp-470h] BYREF
  boost::gregorian::date v7; // [esp+0h] [ebp-468h] BYREF
  boost::posix_time::time_duration time_of_day; // [esp+4h] [ebp-464h] BYREF
  int v9; // [esp+Ch] [ebp-45Ch]
  boost::posix_time::time_duration *p_time_of_day; // [esp+60h] [ebp-408h]
  int seconds; // [esp+64h] [ebp-404h]
  int minutes; // [esp+68h] [ebp-400h]
  int hours; // [esp+6Ch] [ebp-3FCh]
  __int64 v14; // [esp+70h] [ebp-3F8h]
  unsigned __int16 v15; // [esp+1B2h] [ebp-2B6h]
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1400,10000,boost::gregorian::bad_year> > *v16; // [esp+1B4h] [ebp-2B4h]
  __int16 v17; // [esp+2CEh] [ebp-19Ah]
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,12,boost::gregorian::bad_month> > *v18; // [esp+2D0h] [ebp-198h]
  unsigned __int16 tm_mday; // [esp+3EAh] [ebp-7Eh]
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month> > *v20; // [esp+3ECh] [ebp-7Ch]
  int v21; // [esp+3F0h] [ebp-78h]
  unsigned __int8 *v22; // [esp+3F4h] [ebp-74h]
  unsigned int v23; // [esp+3F8h] [ebp-70h]
  unsigned int v24; // [esp+3FCh] [ebp-6Ch]
  __int64 t; // [esp+410h] [ebp-58h] BYREF
  boost::gregorian::date d; // [esp+418h] [ebp-50h] BYREF
  unsigned int sub_sec; // [esp+41Ch] [ebp-4Ch]
  int adjust; // [esp+420h] [ebp-48h]
  tm *curr_ptr; // [esp+424h] [ebp-44h]
  unsigned __int64 micros; // [esp+428h] [ebp-40h]
  boost::posix_time::time_duration td; // [esp+430h] [ebp-38h]
  tm curr; // [esp+43Ch] [ebp-2Ch] BYREF
  boost::date_time::winapi::FILETIME ft; // [esp+460h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime((LPFILETIME)&ft);
  v21 = -717324288;
  v22 = &vostok::memory::s_CRT_arena[15908886];
  v23 = ft.dwLowDateTime + 717324288;
  v24 = ft.dwHighDateTime - (_DWORD)&vostok::memory::s_CRT_arena[(ft.dwLowDateTime < 0xD53E8000) + 15908886];
  HIDWORD(v5) = v24;
  LODWORD(v5) = ft.dwLowDateTime + 717324288;
  micros = v5 / 0xA;
  t = v5 / 0xA / (unsigned int)&off_F4240;
  HIDWORD(v5) = (v5 / 0xA) >> 32;
  sub_sec = micros % (unsigned int)&off_F4240;
  curr_ptr = converter(&t, &curr);
  tm_mday = curr_ptr->tm_mday;
  HIWORD(v6) = HIWORD(curr_ptr);
  v20 = (boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month> > *)&v6
      + 2;
  WORD2(v6) = 1;
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month>>::assign(
    (boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month> > *)&v6
  + 2,
    tm_mday);
  v2 = curr_ptr->tm_mon + 1;
  WORD1(v6) = HIWORD(v2);
  v17 = v2;
  v18 = (boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,12,boost::gregorian::bad_month> > *)&v6;
  LOWORD(v6) = 1;
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,12,boost::gregorian::bad_month>>::assign(
    (boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,12,boost::gregorian::bad_month> > *)&v6,
    v2);
  v15 = curr_ptr->tm_year + 1900;
  HIWORD(v5) = v3;
  v16 = (boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1400,10000,boost::gregorian::bad_year> > *)&v5
      + 2;
  WORD2(v5) = 1400;
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1400,10000,boost::gregorian::bad_year>>::assign(
    (boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1400,10000,boost::gregorian::bad_year> > *)&v5
  + 2,
    v15);
  boost::gregorian::date::date(
    &d,
    *(boost::gregorian::greg_year *)((char *)&v5 + 4),
    (boost::gregorian::greg_month)v6,
    *(boost::gregorian::greg_day *)((char *)&v6 + 4));
  v6 = (unsigned int)&off_F4240;
  v5 = (unsigned int)&off_F4240;
  adjust = (unsigned int)&off_F4240 / (__int64)(unsigned int)&off_F4240;
  seconds = curr_ptr->tm_sec;
  minutes = curr_ptr->tm_min;
  hours = curr_ptr->tm_hour;
  v14 = boost::date_time::time_resolution_traits<boost::date_time::time_resolution_traits_adapted64_impl,5,1000000,6,int>::to_tick_count(
          hours,
          minutes,
          seconds,
          adjust * sub_sec);
  td.ticks_.value_ = v14;
  p_time_of_day = &time_of_day;
  time_of_day.ticks_.value_ = v14;
  v7.days_ = d.days_;
  v9 = 0;
  boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>(
    &result->time_,
    &v7,
    &time_of_day);
  return result;
}
