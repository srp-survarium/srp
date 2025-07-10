void __thiscall vostok::tasks::task_manager::collect_garbage(vostok::tasks::task_manager *this)
{
  vostok::tasks::task *i; // esi
  vostok::tasks::task_manager::collector collector; // [esp+Ch] [ebp-8h] BYREF
  vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::tasks::task_manager::collector> pred; // [esp+10h] [ebp-4h] BYREF

  EnterCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_mutex_collect_garbage);
  _InterlockedExchange(&s_task_manager.m_collecting_garbage, 1);
  vostok::tasks::thread_pool::wait_while_all_threads_end_grab_next_task(s_thread_pool.m_variable);
  for ( i = vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,12,vostok::threading::mutex>::front();
        i;
        i = vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,12,vostok::threading::mutex>::front() )
  {
    if ( i->m_state == 1 )
      break;
    vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,12,vostok::threading::mutex>::pop_front();
    if ( !_InterlockedDecrement(&i->m_reference_counter) )
      vostok::tasks::task_allocator::deallocate(0, (int)&s_task_manager.m_task_allocator, i);
  }
  collector.m_tasks_freed_count = 0;
  if ( s_task_type_list )
  {
    pred.m_predicate_ref = &collector;
    vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::tasks::task_manager::collector>>(
      s_task_type_list,
      &pred);
  }
  _InterlockedExchange(&s_task_manager.m_collecting_garbage, 0);
  LeaveCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_mutex_collect_garbage);
}
