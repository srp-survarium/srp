int vostok::logging::_dynamic_initializer_for__s_log_callback__()
{
  return atexit(vostok::logging::_dynamic_atexit_destructor_for__s_log_callback__);
}
