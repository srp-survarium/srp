void vostok::core::logging_preinitialize()
{
  if ( !vostok::core::g_log_callback )
  {
    vostok::core::g_log_callback = (void (__cdecl *)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag))vostok::core::logging_callback;
    s_log_callback = (void (__cdecl *)(const char *, bool, bool, const char *))vostok::core::debug_log_callback;
  }
}
