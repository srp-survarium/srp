int stlp_std::_dynamic_initializer_for__wcin__()
{
  stlp_std::basic_istream<wchar_t,stlp_std::char_traits<wchar_t>>::basic_istream<wchar_t,stlp_std::char_traits<wchar_t>>(
    &stlp_std::wcin,
    0,
    1);
  return atexit(stlp_std::_dynamic_atexit_destructor_for__wcin__);
}
