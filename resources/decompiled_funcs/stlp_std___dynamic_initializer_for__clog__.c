int stlp_std::_dynamic_initializer_for__clog__()
{
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::basic_ostream<char,stlp_std::char_traits<char>>(
    &stlp_std::clog,
    0,
    1);
  return atexit(stlp_std::_dynamic_atexit_destructor_for__clog__);
}
