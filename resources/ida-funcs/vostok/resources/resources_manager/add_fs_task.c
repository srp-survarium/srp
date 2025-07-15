void __usercall vostok::resources::resources_manager::add_fs_task(vostok::resources::fs_task *task@<eax>)
{
  vostok::threading::mutex *v2; // ecx
  vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_m_fs_sub_tasks; // esi
  vostok::resources::resources_manager *v4; // ecx

  if ( task->is_helper_query_for_mount(task)
    || (p_m_fs_sub_tasks = (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&s_resources_manager_buffer.m_fs_tasks,
        task->m_parent_query) )
  {
    p_m_fs_sub_tasks = (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&s_resources_manager_buffer.m_fs_sub_tasks;
  }
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    p_m_fs_sub_tasks,
    (survarium::player_params_modifier *)task,
    v2);
  vostok::resources::resources_manager::wakeup_resources_thread(v4, (int)&s_resources_manager_buffer);
}
