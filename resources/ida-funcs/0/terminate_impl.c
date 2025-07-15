void __cdecl __noreturn terminate_impl(int exit_code, const char *message)
{
  if ( (s_log_disable_counter == 0 ? (unsigned int)s_log_callback : 0) != 0 )
    ((void (__cdecl *)(const vostok::logging::filter_tree *, _DWORD, _DWORD, const char *))(s_log_disable_counter == 0
                                                                                          ? (unsigned int)s_log_callback
                                                                                          : 0))(
      &stru_802CB8,
      0,
      0,
      uri);
  vostok::debug::dump_call_stack(0, (char *)&stru_802CB8, 1u, 0, 0);
  s_debug_engine->on_terminate(s_debug_engine);
  vostok::debug::platform::terminate(exit_code, message);
}
