void __thiscall vostok::tasks::task_manager::task_manager(vostok::tasks::task_manager *this)
{
  vostok::tasks::task_allocator *v1; // ecx

  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&s_task_manager.m_pending_tasks.m_threading_policy, 0x2710u);
  s_task_manager.m_pending_tasks.m_pop_list = 0;
  s_task_manager.m_pending_tasks.m_push_list = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&s_task_manager.m_mutex_collect_garbage, 0x2710u);
  vostok::tasks::task_allocator::task_allocator(v1, (int)&s_task_manager.m_task_allocator);
  s_task_manager.m_task_ordinal = 0;
  s_task_manager.m_oldest_task_ordinal = 0;
  s_task_manager.m_collecting_garbage = 0;
  s_task_manager.m_current_thread_task_tls_key = TlsAlloc();
}
