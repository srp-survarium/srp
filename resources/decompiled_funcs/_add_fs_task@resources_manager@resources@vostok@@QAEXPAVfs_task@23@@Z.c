void __usercall vostok::resources::resources_manager::add_fs_task(
        vostok::resources::resources_manager *this@<edi>,
        vostok::resources::fs_task *task@<eax>)
{
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v3; // ecx
  bool *v4; // [esp+0h] [ebp-8h]

  if ( task->is_helper_query_for_mount(task) || task->m_parent_query )
    vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v3,
      (volatile int *)((char *)&this->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20546 + 2),
      task,
      v4);
  else
    vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v3,
      (volatile int *)((char *)&this->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20517 + 1),
      task,
      v4);
  SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)this));
}
