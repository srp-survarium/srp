int stlp_std::_dynamic_initializer_for___IosInit__()
{
  stlp_std::ios_base::Init::Init(&IosInit);
  return atexit(stlp_std::_dynamic_atexit_destructor_for___IosInit__);
}
