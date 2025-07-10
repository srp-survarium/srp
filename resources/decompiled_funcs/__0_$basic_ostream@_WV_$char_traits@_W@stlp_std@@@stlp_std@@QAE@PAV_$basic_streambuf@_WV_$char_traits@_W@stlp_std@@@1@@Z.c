void __thiscall stlp_std::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>(
        stlp_std::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t> > *this,
        stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *__buf,
        int a3)
{
  _DWORD *v4; // esi

  if ( a3 )
  {
    v4 = &this->gap0[8];
    *(_DWORD *)this->gap0 = &stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::`vbtable';
    stlp_std::ios_base::ios_base((stlp_std::ios_base *)&this->gap0[8]);
    *v4 = &stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
    *(_WORD *)&this->gap0[92] = 0;
    *(_DWORD *)&this->gap0[96] = 0;
    *(_DWORD *)&this->gap0[100] = 0;
  }
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)] = &stlp_std::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::init(
    (stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t> > *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)],
    __buf);
}
