void __usercall vostok::resources::intrusive_fs_task_unmount_base::destroy(
        vostok::resources::fs_task_unmount *object@<eax>,
        vostok::resources::intrusive_fs_task_unmount_base *this)
{
  vostok::resources::resources_manager *m_variable; // edi
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v4; // ecx
  bool *v5; // [esp+0h] [ebp-8h]

  _InterlockedExchangeAdd(
    (volatile signed __int32 *)((char *)&loc_201B0 + (unsigned int)vostok::resources::g_resources_manager.m_variable),
    1u);
  m_variable = vostok::resources::g_resources_manager.m_variable;
  if ( object->is_helper_query_for_mount(object) || object->m_parent_query )
    vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v4,
      (volatile int *)((char *)&m_variable->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20546 + 2),
      object,
      v5);
  else
    vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v4,
      &m_variable->m_fs_tasks.m_size,
      object,
      v5);
  SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)m_variable));
}
