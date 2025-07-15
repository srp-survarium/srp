int stlp_std::_dynamic_initializer_for__cin__()
{
  stlp_std::basic_istream<char,stlp_std::char_traits<char>>::basic_istream<char,stlp_std::char_traits<char>>(
    &stlp_std::cin,
    0,
    1);
  return atexit(stlp_std::_dynamic_atexit_destructor_for__cin__);
}
