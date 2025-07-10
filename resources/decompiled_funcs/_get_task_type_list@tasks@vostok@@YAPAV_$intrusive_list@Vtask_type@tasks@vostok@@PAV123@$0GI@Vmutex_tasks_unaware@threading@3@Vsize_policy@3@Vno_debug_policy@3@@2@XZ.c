vostok::intrusive_list<vostok::tasks::task_type,vostok::tasks::task_type *,104,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy> *__cdecl vostok::tasks::get_task_type_list()
{
  return s_task_type_list;
}
