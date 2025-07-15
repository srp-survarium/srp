void __usercall vostok::resources::resources_manager::add_resource_to_create(
        vostok::resources::query_result *query@<eax>)
{
  vostok::resources::cook_base *cook; // eax
  unsigned int v3; // eax
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::threading::mutex *v5; // ecx
  vostok::resources::cook_base *v6; // [esp-4h] [ebp-10h]

  cook = vostok::resources::resources_manager::find_cook(query->m_class_id);
  v3 = vostok::resources::cook_base::creation_thread_id(v6, (int)cook);
  if ( v3 == s_resources_manager_buffer.m_cooker_thread_id )
  {
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &s_resources_manager_buffer.m_resources_to_create,
      query,
      (vostok::threading::mutex *)s_resources_manager_buffer.m_cooker_thread_id);
    SetEvent(*(HANDLE *)s_resources_manager_buffer.m_cooker_wakeup_event.m_event.m_event);
  }
  else
  {
    thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                          (vostok::resources::resources_manager *)s_resources_manager_buffer.m_cooker_thread_id,
                          (unsigned int)&s_resources_manager_buffer,
                          v3,
                          1);
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &thread_local_data->to_create_resource,
      query,
      v5);
  }
}
