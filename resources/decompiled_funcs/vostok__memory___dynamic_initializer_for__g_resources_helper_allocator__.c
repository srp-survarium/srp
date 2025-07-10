int vostok::memory::_dynamic_initializer_for__g_resources_helper_allocator__()
{
  vostok::memory::g_resources_helper_allocator.m_user_thread_id = GetCurrentThreadId();
  vostok::memory::g_resources_helper_allocator.m_crash_after_out_of_memory = 1;
  vostok::memory::g_resources_helper_allocator.m_return_null_after_out_of_memory = 0;
  vostok::memory::g_resources_helper_allocator.m_out_of_memory = 0;
  vostok::memory::g_resources_helper_allocator.m_use_guards = 1;
  return atexit(vostok::memory::_dynamic_atexit_destructor_for__g_resources_helper_allocator__);
}
