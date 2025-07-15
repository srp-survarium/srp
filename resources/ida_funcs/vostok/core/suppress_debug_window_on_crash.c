bool __cdecl vostok::core::suppress_debug_window_on_crash()
{
  unsigned int is_set; // eax
  bool result; // al

  is_set = s_out_result_0;
  if ( s_out_result_0 != -1 )
    return is_set != 0;
  if ( !s_command_line_initialized )
  {
    is_set = vostok::command_line::key_is_set("suppress_debug_window_on_crash");
    s_out_result_0 = (unsigned __int8)is_set;
    return is_set != 0;
  }
  if ( s_suppress_debug_window_on_crash.m_type == type_unset )
  {
    s_suppress_debug_window_on_crash.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  result = s_suppress_debug_window_on_crash.m_type != type_recursive;
  s_out_result_0 = s_suppress_debug_window_on_crash.m_type != type_recursive;
  return result;
}
