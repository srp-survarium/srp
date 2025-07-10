BOOL __thiscall vostok::core::core_debug_engine::dont_check_multithreaded_safety(vostok::core::core_debug_engine *this)
{
  if ( s_dont_check_multithreaded_safety.m_type == type_unset )
  {
    s_dont_check_multithreaded_safety.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  return s_dont_check_multithreaded_safety.m_type != type_recursive;
}
