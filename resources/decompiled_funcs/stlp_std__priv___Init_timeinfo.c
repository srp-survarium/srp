void __usercall stlp_std::priv::_Init_timeinfo(stlp_std::priv::_Time_Info *table@<ebx>)
{
  char *v1; // esi
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *M_dayname; // edi
  char *v3; // esi
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *M_monthname; // edi

  v1 = (char *)default_dayname[0];
  M_dayname = table->_M_dayname;
  do
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_assign(
      M_dayname,
      v1,
      &v1[strlen(v1)]);
    v1 += 14;
    ++M_dayname;
  }
  while ( (int)v1 < (int)byte_816D5C );
  v3 = (char *)default_monthname[0];
  M_monthname = table->_M_monthname;
  do
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_assign(
      M_monthname,
      v3,
      &v3[strlen(v3)]);
    v3 += 24;
    ++M_monthname;
  }
  while ( (int)v3 < (int)&default_wdayname );
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_assign(
    table->_M_am_pm,
    "AM",
    "");
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_assign(
    &table->_M_am_pm[1],
    "PM",
    "");
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
