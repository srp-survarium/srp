int stlp_std::_dynamic_initializer_for____oom_handler_lock__()
{
  stlp_std::__oom_handler_lock._M_lock = 0;
  return atexit(stlp_std::_dynamic_atexit_destructor_for____oom_handler_lock__);
}
