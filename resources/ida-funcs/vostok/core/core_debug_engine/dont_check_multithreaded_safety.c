BOOL __thiscall vostok::core::core_debug_engine::dont_check_multithreaded_safety(vostok::core::core_debug_engine *this)
{
  return vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_dont_check_multithreaded_safety);
}
