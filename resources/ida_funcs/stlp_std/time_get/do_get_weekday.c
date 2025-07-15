stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get_weekday(
        stlp_std::time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        tm *__t)
{
  unsigned int v7; // eax
  int v8; // edx
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *v9; // eax
  int *v10; // esi
  int v11; // edx

  v7 = stlp_std::priv::__match<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>> const *>(
         &__s,
         &__end,
         this->_M_timeinfo._M_dayname,
         this->_M_timeinfo._M_monthname);
  if ( v7 == 14 )
  {
    v10 = __err;
    *__err = 4;
    if ( stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(&__s, &__end) )
      *v10 |= 2u;
    v9 = result;
    v11 = *(_DWORD *)&__s._M_c;
    result->_M_buf = __s._M_buf;
    *(_DWORD *)&result->_M_c = v11;
  }
  else
  {
    v8 = *(_DWORD *)&__s._M_c;
    __t->tm_wday = v7 % 7;
    v9 = result;
    *__err = 0;
    result->_M_buf = __s._M_buf;
    *(_DWORD *)&result->_M_c = v8;
  }
  return v9;
}
