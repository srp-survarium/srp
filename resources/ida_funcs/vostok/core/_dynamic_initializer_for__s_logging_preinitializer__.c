void vostok::core::_dynamic_initializer_for__s_logging_preinitializer__()
{
  vostok::debug::preinitialize();
  if ( !vostok::core::g_log_callback )
  {
    vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
    vostok::debug::set_log_callback(vostok::core::debug_log_callback);
  }
}
