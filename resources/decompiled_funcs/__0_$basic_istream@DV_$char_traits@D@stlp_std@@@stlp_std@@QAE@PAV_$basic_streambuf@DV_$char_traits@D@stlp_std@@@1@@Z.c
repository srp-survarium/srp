void __thiscall stlp_std::basic_istream<char,stlp_std::char_traits<char>>::basic_istream<char,stlp_std::char_traits<char>>(
        stlp_std::basic_istream<char,stlp_std::char_traits<char> > *this,
        stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *__buf,
        int a3)
{
  if ( a3 )
  {
    *(_DWORD *)this->gap0 = &stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbtable';
    stlp_std::basic_ios<char,stlp_std::char_traits<char>>::basic_ios<char,stlp_std::char_traits<char>>((stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)this->gap10);
  }
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)] = &stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vftable';
  LODWORD(this->_M_gcount) = 0;
  HIDWORD(this->_M_gcount) = 0;
  stlp_std::basic_ios<char,stlp_std::char_traits<char>>::init(
    (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)],
    __buf);
}
