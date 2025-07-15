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


void __thiscall stlp_std::basic_istream<wchar_t,stlp_std::char_traits<wchar_t>>::basic_istream<wchar_t,stlp_std::char_traits<wchar_t>>(
        stlp_std::basic_istream<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *__buf,
        int a3)
{
  _BYTE *v4; // edi
  int v5; // ecx

  if ( a3 )
  {
    v4 = this->gap10;
    *(_DWORD *)this->gap0 = &stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbtable';
    stlp_std::ios_base::ios_base((stlp_std::ios_base *)this->gap10);
    *(_DWORD *)v4 = &stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
    *(_WORD *)&this->gap10[84] = 0;
    *(_DWORD *)&this->gap10[88] = 0;
    *(_DWORD *)&this->gap10[92] = 0;
  }
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)] = &stlp_std::basic_istream<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  v5 = *(_DWORD *)this->gap0;
  LODWORD(this->_M_gcount) = 0;
  HIDWORD(this->_M_gcount) = 0;
  stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::init(
    (stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t> > *)&this->gap0[*(_DWORD *)(v5 + 4)],
    __buf);
}
