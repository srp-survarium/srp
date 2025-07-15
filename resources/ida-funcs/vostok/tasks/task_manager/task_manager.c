void __thiscall vostok::tasks::task_manager::task_manager(vostok::tasks::task_manager *this)
{
  vostok::threading::mutex_tasks_unaware *v1; // ecx
  int v2; // ecx
  unsigned __int8 *v3; // eax
  int v4; // edx

  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    (vostok::threading::mutex_tasks_unaware *)this,
    (_RTL_CRITICAL_SECTION *)&s_task_manager.m_pending_tasks.m_threading_policy);
  s_task_manager.m_pending_tasks.m_pop_list = 0;
  s_task_manager.m_pending_tasks.m_push_list = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    v1,
    (_RTL_CRITICAL_SECTION *)&s_task_manager.m_mutex_collect_garbage);
  s_task_manager.m_task_allocator.m_free_list.whole = 0;
  v2 = 0;
  v3 = &s_task_manager.m_task_allocator.m_task_buffer[88];
  v4 = 4096;
  do
  {
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 - 21) = v2++ != 4095 ? v3 + 8 : 0;
    v3 += 96;
    --v4;
  }
  while ( v4 );
  s_task_manager.m_task_allocator.m_free_list.m_pointer = (vostok::tasks::task *)&s_task_manager.m_task_allocator;
  s_task_manager.m_task_ordinal = 0;
  s_task_manager.m_oldest_task_ordinal = 0;
  s_task_manager.m_collecting_garbage = 0;
  s_task_manager.m_current_thread_task_tls_key = TlsAlloc();
}
