void __userpurge vostok::resources::allocate_functionality::prepare_final_resource(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::allocate_functionality *this)
{
  vostok::resources::class_id_enum m_class_id; // esi
  vostok::resources::query_result *v4; // ecx
  __int32 final_managed_resource_if_needed; // ebx
  vostok::resources::query_result *v6; // esi
  vostok::resources::unmanaged_cook *unmanaged_cook; // eax
  vostok::resources::resources_manager *v8; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::threading::mutex *v10; // ecx
  vostok::resources::resources_manager *v11; // ecx
  vostok::resources::query_result *v12; // [esp-4h] [ebp-14h]
  vostok::resources::resources_manager *v13; // [esp+0h] [ebp-10h]
  vostok::resources::resources_manager *thread_id; // [esp+Ch] [ebp-4h]

  m_class_id = query->m_class_id;
  if ( vostok::resources::cook_base::find_managed_cook(m_class_id) )
  {
    if ( GetCurrentThreadId() != s_resources_manager_buffer.m_resources_thread_id )
    {
      vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        &this->m_queries_to_allocate_managed_resource,
        query,
        (vostok::threading::mutex *)s_resources_manager_buffer.m_resources_thread_id);
      SetEvent(*(HANDLE *)s_resources_manager_buffer.m_resources_wakeup_event.m_event.m_event);
      return;
    }
    final_managed_resource_if_needed = vostok::resources::query_result::allocate_final_managed_resource_if_needed(
                                         (vostok::resources::query_result *)s_resources_manager_buffer.m_resources_thread_id,
                                         (int)query);
    if ( final_managed_resource_if_needed != 1 )
      goto LABEL_12;
    v6 = query;
    goto LABEL_11;
  }
  unmanaged_cook = vostok::resources::cook_base::find_unmanaged_cook(m_class_id);
  v6 = query;
  if ( (unmanaged_cook->m_flags.m_flags & 2) != 0 )
  {
    vostok::resources::query_result::send_to_create_resource(v12, (int)query, v13);
    return;
  }
  thread_id = (vostok::resources::resources_manager *)vostok::resources::query_result::allocate_thread_id(
                                                        v12,
                                                        (int)query);
  if ( thread_id != (vostok::resources::resources_manager *)GetCurrentThreadId() )
  {
    thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                          v8,
                          (unsigned int)&s_resources_manager_buffer,
                          (unsigned int)thread_id,
                          1);
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &thread_local_data->to_allocate_resource,
      query,
      v10);
    vostok::resources::resources_manager::wakeup_thread_by_id_if_needed(
      v11,
      (int)&s_resources_manager_buffer,
      thread_id);
    return;
  }
  final_managed_resource_if_needed = vostok::resources::query_result::allocate_final_unmanaged_resource_if_needed(
                                       (vostok::resources::query_result *)v8,
                                       (int)query);
  if ( final_managed_resource_if_needed == 1 )
LABEL_11:
    vostok::resources::query_result::send_to_create_resource(v4, (int)v6, v13);
LABEL_12:
  if ( !final_managed_resource_if_needed )
    vostok::resources::query_result::end_query_might_destroy_this(v4, (int)query);
}
