void __thiscall stlp_std::basic_istream<char,stlp_std::char_traits<char>>::_M_skip_whitespace(
        stlp_std::basic_istream<char,stlp_std::char_traits<char> > *this,
        bool __set_failbit)
{
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *__buf; // [esp+34h] [ebp-4h]

  __buf = *(stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > **)&this->gap10[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)
                                                                                       + 72];
  if ( __buf )
  {
    if ( __buf->_M_gnext == __buf->_M_gend )
      stlp_std::_M_ignore_unbuffered<char,stlp_std::char_traits<char>,stlp_std::priv::_Is_not_wspace<stlp_std::char_traits<char>>>(
        this,
        __buf,
        *(stlp_std::priv::_Is_not_wspace<stlp_std::char_traits<char> > *)&this->gap10[*(_DWORD *)(*(_DWORD *)this->gap0
                                                                                                + 4)
                                                                                    + 64],
        0,
        __set_failbit);
    else
      stlp_std::_M_ignore_buffered<char,stlp_std::char_traits<char>,stlp_std::priv::_Is_not_wspace<stlp_std::char_traits<char>>,stlp_std::priv::_Scan_for_not_wspace<stlp_std::char_traits<char>>>(
        this,
        __buf,
        *(stlp_std::priv::_Is_not_wspace<stlp_std::char_traits<char> > *)&this->gap10[*(_DWORD *)(*(_DWORD *)this->gap0
                                                                                                + 4)
                                                                                    + 64],
        *(stlp_std::priv::_Scan_for_not_wspace<stlp_std::char_traits<char> > *)&this->gap10[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)
                                                                                          + 64],
        0,
        __set_failbit);
  }
  else
  {
    stlp_std::basic_ios<char,stlp_std::char_traits<char>>::setstate(
      (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)],
      1);
  }
}
