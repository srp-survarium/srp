void __thiscall vostok::tasks::thread_tls::thread_proc(vostok::tasks::thread_tls *this)
{
  vostok::tasks::thread_tls *v2; // ecx
  vostok::tasks::thread_pool *pool; // esi

  WaitForSingleObject(*(HANDLE *)this->event_start_thread_work.m_event, 0xFFFFFFFF);
  vostok::tasks::thread_tls::thread_proc_impl(v2, (int)this);
  pool = this->pool;
  EnterCriticalSection((LPCRITICAL_SECTION)&pool->m_thread_exiting_mutex);
  if ( _InterlockedIncrement(&pool->m_num_task_threads_exited) == pool->m_task_thread_tls.m_end
                                                                - pool->m_task_thread_tls.m_begin )
    SetEvent(*(HANDLE *)pool->m_all_task_threads_destroyed.m_event.m_event);
  LeaveCriticalSection((LPCRITICAL_SECTION)&pool->m_thread_exiting_mutex);
}
