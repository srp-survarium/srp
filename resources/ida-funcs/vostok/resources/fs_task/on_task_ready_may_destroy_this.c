void __usercall vostok::resources::fs_task::on_task_ready_may_destroy_this(
        vostok::resources::fs_task *this@<ecx>,
        survarium::player_params_modifier *a2@<eax>)
{
  survarium::player_params_modifier *next; // ebx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::threading::mutex *v5; // ecx
  vostok::resources::resources_manager *v6; // ecx

  next = a2[2].next;
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        (vostok::resources::resources_manager *)this,
                        (unsigned int)&s_resources_manager_buffer,
                        (unsigned int)next,
                        1);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&thread_local_data->ready_fs_tasks,
    a2,
    v5);
  vostok::resources::resources_manager::wakeup_thread_by_id_if_needed(
    v6,
    (int)&s_resources_manager_buffer,
    (vostok::resources::resources_manager *)next);
}
