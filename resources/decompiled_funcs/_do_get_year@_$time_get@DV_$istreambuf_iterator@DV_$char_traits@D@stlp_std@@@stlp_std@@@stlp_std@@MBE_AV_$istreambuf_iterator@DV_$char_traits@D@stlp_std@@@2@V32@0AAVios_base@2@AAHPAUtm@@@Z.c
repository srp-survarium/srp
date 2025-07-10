stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get_year(
        stlp_std::time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        stlp_std::ios_base *__formal,
        int *__err,
        tm *__t)
{
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *v7; // eax
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *M_buf; // edx
  int v9; // ecx
  int *p_tm_year; // esi
  bool v11; // al
  int *v12; // esi
  int v13; // edx

  if ( stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(&__s, &__end) )
  {
    v7 = result;
    M_buf = __s._M_buf;
    *__err = 6;
    v9 = *(_DWORD *)&__s._M_c;
    result->_M_buf = M_buf;
    *(_DWORD *)&result->_M_c = v9;
  }
  else
  {
    p_tm_year = &__t->tm_year;
    v11 = stlp_std::priv::__get_decimal_integer<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,int,char>(
            &__s,
            &__end,
            &__t->tm_year);
    *p_tm_year -= 1900;
    v12 = __err;
    *__err = v11 ? 0 : 4;
    if ( stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(&__s, &__end) )
      *v12 |= 2u;
    v7 = result;
    v13 = *(_DWORD *)&__s._M_c;
    result->_M_buf = __s._M_buf;
    *(_DWORD *)&result->_M_c = v13;
  }
  return v7;
}
