void __cdecl stlp_std::_dynamic_atexit_destructor_for__wclog__()
{
  *(_DWORD *)&stlp_std::wclog.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wclog.gap0 + 4)] = &stlp_std::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  *(_DWORD *)&stlp_std::wclog.gap0[8] = &stlp_std::basic_ios<wchar_t,stlp_std::char_traits<wchar_t>>::`vftable';
  stlp_std::ios_base::~ios_base((stlp_std::ios_base *)&stlp_std::wclog.gap0[8]);
}
