void __cdecl stlp_std::_dynamic_atexit_destructor_for__cerr__()
{
  *(_DWORD *)&stlp_std::cerr.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cerr.gap0 + 4)] = &stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::`vftable';
  *(_DWORD *)&stlp_std::cerr.gap0[8] = &stlp_std::basic_ios<char,stlp_std::char_traits<char>>::`vftable';
  stlp_std::ios_base::~ios_base((stlp_std::ios_base *)&stlp_std::cerr.gap0[8]);
}
