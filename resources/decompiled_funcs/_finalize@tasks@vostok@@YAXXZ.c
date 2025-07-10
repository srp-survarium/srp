void __thiscall vostok::tasks::finalize(vostok::tasks::thread_pool *ecx0)
{
  vostok::tasks::thread_pool::~thread_pool(ecx0, (volatile int *)s_thread_pool.m_variable);
  s_thread_pool.m_initialized = 0;
}
