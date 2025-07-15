void __usercall vostok::resources::allocate_functionality::prepare_raw_resource_for_inplace_unmanaged_cook(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::query_result *a2@<ecx>)
{
  vostok::vfs::vfs_iterator *p_m_fat_it; // ebx
  vostok::resources::query_result *v5; // ecx
  vostok::resources::query_result *v6; // ecx
  vostok::resources::query_result *v7; // ecx
  vostok::vfs::base_node<1> *v8; // eax
  int compressed_resource_if_needed; // eax
  vostok::resources::query_result *v10; // ecx
  vostok::resources::resources_manager *v11; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::threading::mutex *v13; // ecx
  vostok::resources::resources_manager *v14; // ecx
  int raw_unmanaged_resource_if_needed; // eax
  vostok::resources::resources_manager *v16; // [esp+0h] [ebp-20h]
  vostok::vfs::base_node<1> *m_node; // [esp+14h] [ebp-Ch]
  vostok::vfs::base_node<1> *m_link_target; // [esp+18h] [ebp-8h]
  vostok::resources::resources_manager *thread_id; // [esp+1Ch] [ebp-4h]

  p_m_fat_it = &query->m_fat_it;
  m_node = query->m_fat_it.m_node;
  m_link_target = query->m_fat_it.m_link_target;
  if ( vostok::resources::query_result::need_create_resource_inplace_in_creation_or_inline_data(a2, (int)query) )
  {
    vostok::resources::query_result::bind_unmanaged_resource_buffer_to_creation_or_inline_data(v5, (int)query);
    vostok::resources::query_result::send_to_create_resource(v6, (int)query, v16);
    return;
  }
  if ( m_node && vostok::vfs::vfs_iterator::is_compressed(p_m_fat_it) )
  {
    v8 = m_link_target;
    if ( !m_link_target )
      v8 = m_node;
    if ( (v8->m_flags & 0x40) == 0 )
    {
      compressed_resource_if_needed = vostok::resources::query_result::allocate_compressed_resource_if_needed(
                                        v7,
                                        (int)query);
      if ( !compressed_resource_if_needed )
      {
LABEL_16:
        vostok::resources::query_result::end_query_might_destroy_this(v10, (int)query);
        return;
      }
      if ( compressed_resource_if_needed == 2 )
        return;
    }
  }
  if ( query->m_raw_unmanaged_buffer.m_data )
    goto LABEL_14;
  thread_id = (vostok::resources::resources_manager *)vostok::resources::query_result::allocate_thread_id(
                                                        (vostok::resources::query_result *)query->m_raw_unmanaged_buffer.m_size,
                                                        (int)query);
  if ( thread_id != (vostok::resources::resources_manager *)GetCurrentThreadId() )
  {
    thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                          v11,
                          (unsigned int)&s_resources_manager_buffer,
                          (unsigned int)thread_id,
                          1);
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &thread_local_data->to_allocate_raw_resource,
      query,
      v13);
    vostok::resources::resources_manager::wakeup_thread_by_id_if_needed(
      v14,
      (int)&s_resources_manager_buffer,
      thread_id);
    return;
  }
  raw_unmanaged_resource_if_needed = vostok::resources::query_result::allocate_raw_unmanaged_resource_if_needed(
                                       (vostok::resources::query_result *)v11,
                                       (int)query);
  if ( raw_unmanaged_resource_if_needed == 1 )
  {
LABEL_14:
    vostok::resources::allocate_functionality::continue_prepare_raw_resource_for_inplace_unmanaged_cook(
      query,
      (vostok::resources::allocate_functionality *)v16);
    return;
  }
  if ( !raw_unmanaged_resource_if_needed )
    goto LABEL_16;
}
