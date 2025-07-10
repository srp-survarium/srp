int vostok::engine::_dynamic_initializer_for__g_allocator__()
{
  vostok::engine::g_allocator.m_user_thread_id = GetCurrentThreadId();
  vostok::engine::g_allocator.m_crash_after_out_of_memory = 1;
  vostok::engine::g_allocator.m_return_null_after_out_of_memory = 0;
  vostok::engine::g_allocator.m_out_of_memory = 0;
  vostok::engine::g_allocator.m_use_guards = 1;
  return atexit(vostok::engine::_dynamic_atexit_destructor_for__g_allocator__);
}
