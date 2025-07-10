void __usercall stlp_std::priv::_Init_timeinfo_0(stlp_std::priv::_WTime_Info *table@<ebx>)
{
  wchar_t *v1; // esi
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *M_dayname; // edi
  wchar_t *v3; // eax
  wchar_t *v5; // esi
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *M_monthname; // edi
  wchar_t *v7; // eax

  v1 = (wchar_t *)&default_wdayname;
  M_dayname = table->_M_dayname;
  do
  {
    v3 = v1;
    while ( *v3++ )
      ;
    stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_assign(
      M_dayname,
      v1,
      &v1[v3 - (v1 + 1)]);
    v1 += 14;
    ++M_dayname;
  }
  while ( (int)v1 < (int)&default_wmonthname );
  v5 = (wchar_t *)&default_wmonthname;
  M_monthname = table->_M_monthname;
  do
  {
    v7 = v5;
    while ( *v7++ )
      ;
    stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_assign(
      M_monthname,
      v5,
      &v5[v7 - (v5 + 1)]);
    v5 += 24;
    ++M_monthname;
  }
  while ( (int)v5 < (int)"%m/%d/%y" );
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_assign(
    table->_M_am_pm,
    (wchar_t *)L"AM",
    (wchar_t *)L"");
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_assign(
    &table->_M_am_pm[1],
    (wchar_t *)L"PM",
    (wchar_t *)L"");
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_assign(
    &table->_M_time_format,
    "%H:%M:%S",
    "");
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_assign(
    &table->_M_date_format,
    "%m/%d/%y",
    "");
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_assign(
    &table->_M_date_time_format,
    "%m/%d/%y",
    "");
}
