stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *__thiscall stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::flush(
        stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *this)
{
  if ( *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88]
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88] + 16))(*(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88]) == -1 )
  {
    stlp_std::basic_ios<char,stlp_std::char_traits<char>>::setstate(
      (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)],
      1);
  }
  return this;
}
