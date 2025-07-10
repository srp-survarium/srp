BOOL __thiscall vostok::tasks::task_manager::zero_tasks(vostok::tasks::task_manager *this)
{
  return !s_task_manager.m_pending_tasks.m_pop_list && !s_task_manager.m_pending_tasks.m_push_list;
}
