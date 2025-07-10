void __usercall vostok::tasks::thread_tls::thread_proc_impl(
        vostok::tasks::thread_tls *this@<ecx>,
        vostok::tasks::thread_tls *a2@<eax>)
{
  vostok::tasks::thread_pool *pool; // edi
  char v4; // bl
  vostok::tasks::task_manager *m_paused; // ecx
  vostok::tasks::thread_pool *v6; // edi
  vostok::tasks::thread_pool *v7; // eax
  vostok::tasks::task *v8; // ecx
  vostok::tasks::thread_pool *v9; // edi
  __int64 elapsed_ticks; // rax

  pool = a2->pool;
  v4 = 1;
  TlsSetValue(pool->m_thread_tls_key, a2);
  if ( _InterlockedIncrement(&pool->m_num_task_threads_started) == pool->m_task_thread_tls.m_end
                                                                 - pool->m_task_thread_tls.m_begin )
    SetEvent(*(HANDLE *)pool->m_all_task_threads_started.m_event);
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v4 )
      {
        WaitForSingleObject(*(HANDLE *)a2->event_should_work.m_event, 0xFFFFFFFF);
        vostok::threading::set_current_thread_affinity(a2->hardware_thread);
        v4 = 0;
      }
      m_paused = (vostok::tasks::task_manager *)a2->pool->m_paused;
      if ( m_paused )
      {
        v6 = a2->pool;
        if ( _InterlockedIncrement(&v6->m_num_paused_threads) == v6->m_task_thread_tls.m_end
                                                               - v6->m_task_thread_tls.m_begin )
          SetEvent(*(HANDLE *)v6->m_all_task_threads_paused.m_event);
        WaitForSingleObject(*(HANDLE *)a2->event_pause_ended.m_event, 0xFFFFFFFF);
        v7 = a2->pool;
        m_paused = (vostok::tasks::task_manager *)&v7->m_num_paused_threads;
        if ( !_InterlockedExchangeAdd(&v7->m_num_paused_threads, 0xFFFFFFFF) )
          SetEvent(*(HANDLE *)v7->m_all_task_threads_resumed.m_event);
      }
      if ( !vostok::tasks::task_manager::grab_next_task(m_paused) )
        break;
LABEL_14:
      vostok::tasks::task::execute(v8);
      elapsed_ticks = vostok::timing::timer::get_elapsed_ticks(&a2->pool->m_timer);
      vostok::threading::interlocked_exchange(&a2->last_task_end_tick, elapsed_ticks);
      _InterlockedExchangeAdd(&a2->executed_tasks_count, 1u);
      if ( !a2->pool->m_destroying )
        v4 = vostok::tasks::thread_pool::deactivate_if_oversubscribed(a2->pool, a2);
    }
    if ( a2->pool->m_destroying )
      break;
    v9 = a2->pool;
    v4 = 1;
    vostok::tasks::thread_pool::log(
      v9,
      a2,
      "%d>deactivated(%d)",
      a2->hardware_thread,
      v9->m_core_thread_count.m_begin[a2->hardware_thread]);
    _InterlockedExchange(&a2->state, 1);
    _InterlockedExchangeAdd(&v9->m_core_thread_count.m_begin[a2->hardware_thread], 0xFFFFFFFF);
    if ( vostok::tasks::task_manager::grab_next_task((vostok::tasks::task_manager *)_InterlockedExchangeAdd(
                                                                                      &v9->m_active_task_thread_count,
                                                                                      0xFFFFFFFF)) )
    {
      v4 = 0;
      vostok::tasks::thread_pool::try_activate_task_thread(a2->pool, a2, a2->hardware_thread);
      WaitForSingleObject(*(HANDLE *)a2->event_should_work.m_event, 0xFFFFFFFF);
      vostok::threading::set_current_thread_affinity(a2->hardware_thread);
      goto LABEL_14;
    }
  }
  vostok::tasks::thread_pool::deactivate_task_thread(a2->pool, a2);
}
