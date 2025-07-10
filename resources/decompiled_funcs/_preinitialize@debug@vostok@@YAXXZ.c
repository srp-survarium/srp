void __cdecl vostok::debug::preinitialize()
{
  if ( !s_debug_preinitialized )
  {
    s_debug_preinitialized = 1;
    vostok::debug::bugtrap::change_usage(error_mode_verbose, native_bugtrap);
    vostok::debug::platform::setup_storage_access_handler(error_mode_verbose);
    signal(22, (void (__cdecl *)(int))abort_handler);
    signal(6, (void (__cdecl *)(int))abort_handler);
    signal(8, (void (__cdecl *)(int))floating_point_handler);
    signal(4, (void (__cdecl *)(int))illegal_instruction_handler);
    signal(2, 0);
    signal(15, (void (__cdecl *)(int))termination_handler);
    _set_abort_behavior(0, 3u);
    _set_invalid_parameter_handler((void (__cdecl *)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))invalid_parameter_handler);
    _set_new_mode(1u);
    _set_new_handler((int (__cdecl *)(unsigned int))out_of_memory_handler);
    _set_purecall_handler((void (__cdecl *)())pure_call_handler);
    vostok::debug::g_assertion_message[0] = 0;
  }
}
