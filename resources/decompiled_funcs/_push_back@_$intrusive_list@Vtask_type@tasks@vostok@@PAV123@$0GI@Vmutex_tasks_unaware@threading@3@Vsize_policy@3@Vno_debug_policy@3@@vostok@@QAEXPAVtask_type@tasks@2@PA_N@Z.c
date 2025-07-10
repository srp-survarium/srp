void __thiscall vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::tasks::task_type *object,
        vostok::tasks::task_type *out_pushed_first)
{
  vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy> *v2; // esi
  _RTL_CRITICAL_SECTION *v3; // edi

  v2 = s_task_type_list;
  out_pushed_first->m_next_task_type = 0;
  if ( v2 )
    v3 = (_RTL_CRITICAL_SECTION *)&v2->vostok::threading::mutex_tasks_unaware;
  else
    v3 = 0;
  EnterCriticalSection(v3);
  ++v2->m_size;
  if ( v2->m_first )
    v2->m_last->m_next_task_type = out_pushed_first;
  else
    v2->m_first = out_pushed_first;
  v2->m_last = out_pushed_first;
  LeaveCriticalSection(v3);
}
