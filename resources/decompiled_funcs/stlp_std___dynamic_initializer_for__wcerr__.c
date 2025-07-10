int stlp_std::_dynamic_initializer_for__wcerr__()
{
  stlp_std::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>::basic_ostream<wchar_t,stlp_std::char_traits<wchar_t>>(
    &stlp_std::wcerr,
    0,
    1);
  return atexit(stlp_std::_dynamic_atexit_destructor_for__wcerr__);
}
