void vostok::tasks::_dynamic_atexit_destructor_for__s_task_manager__()
{
  DeleteCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_mutex_collect_garbage);
  DeleteCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_pending_tasks.m_threading_policy);
}
