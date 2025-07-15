BOOL __cdecl vostok::tasks::zero_tasks()
{
  return !s_task_manager.m_pending_tasks.m_pop_list && !s_task_manager.m_pending_tasks.m_push_list;
}
