void __thiscall vostok::tasks::register_current_thread_as_core_user(vostok::tasks::thread_pool *ecx0)
{
  if ( s_thread_pool.m_initialized )
    vostok::tasks::thread_pool::register_current_thread_as_core_user(ecx0, (DWORD *)s_thread_pool.m_variable);
}
