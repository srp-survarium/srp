char __cdecl stlp_std::_M_init_skip<char,stlp_std::char_traits<char>>(
        stlp_std::basic_istream<char,stlp_std::char_traits<char> > *__istr)
{
  if ( !*(_DWORD *)&__istr->gap0[*(_DWORD *)(*(_DWORD *)__istr->gap0 + 4) + 12] )
  {
    if ( *(_DWORD *)&__istr->gap10[*(_DWORD *)(*(_DWORD *)__istr->gap0 + 4) + 76] )
      stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::flush(*(stlp_std::basic_ostream<char,stlp_std::char_traits<char> > **)&__istr->gap10[*(_DWORD *)(*(_DWORD *)__istr->gap0 + 4) + 76]);
    stlp_std::basic_istream<char,stlp_std::char_traits<char>>::_M_skip_whitespace(__istr, 1);
  }
  if ( !*(_DWORD *)&__istr->gap0[*(_DWORD *)(*(_DWORD *)__istr->gap0 + 4) + 12] )
    return 1;
  stlp_std::basic_ios<char,stlp_std::char_traits<char>>::setstate(
    (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)&__istr->gap0[*(_DWORD *)(*(_DWORD *)__istr->gap0 + 4)],
    4);
  return 0;
}
