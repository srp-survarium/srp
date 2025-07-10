bool __cdecl stlp_std::priv::__init_bostr<char,stlp_std::char_traits<char>>(
        stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *__str)
{
  if ( *(_DWORD *)&__str->gap0[*(_DWORD *)(*(_DWORD *)__str->gap0 + 4) + 12] )
    return 0;
  if ( !*(_DWORD *)&__str->gap0[*(_DWORD *)(*(_DWORD *)__str->gap0 + 4) + 88] )
    stlp_std::basic_ios<char,stlp_std::char_traits<char>>::setstate(
      (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)&__str->gap0[*(_DWORD *)(*(_DWORD *)__str->gap0 + 4)],
      1);
  if ( *(_DWORD *)&__str->gap0[*(_DWORD *)(*(_DWORD *)__str->gap0 + 4) + 92] )
    stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::flush(*(stlp_std::basic_ostream<char,stlp_std::char_traits<char> > **)&__str->gap0[*(_DWORD *)(*(_DWORD *)__str->gap0 + 4) + 92]);
  return *(_DWORD *)&__str->gap0[*(_DWORD *)(*(_DWORD *)__str->gap0 + 4) + 12] == 0;
}
