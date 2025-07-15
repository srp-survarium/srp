void __usercall vostok::resources::allocate_functionality::prepare_raw_resource_for_inplace_unmanaged_cook(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::allocate_functionality *this)
{
  vostok::vfs::vfs_iterator *p_m_fat_it; // ebx
  vostok::resources::query_result *v4; // ecx
  vostok::resources::query_result *v5; // ecx
  vostok::resources::query_result *v6; // ecx
  vostok::vfs::base_node<1> *v7; // eax
  vostok::resources::query_result *v8; // ecx
  int compressed_resource_if_needed; // eax
  unsigned int m_size; // eax
  vostok::resources::query_result *v11; // ecx
  vostok::resources::resources_manager *thread_id; // edi
  vostok::resources::query_result *v13; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v15; // ecx
  int raw_unmanaged_resource_if_needed; // eax
  vostok::resources::query_result *v17; // ecx
  bool *v18; // [esp+0h] [ebp-2Ch]
  vostok::mutable_buffer v19; // [esp+10h] [ebp-1Ch] BYREF
  vostok::vfs::vfs_iterator fat_it; // [esp+18h] [ebp-14h] BYREF

  p_m_fat_it = &query->m_fat_it;
  vostok::vfs::vfs_iterator::vfs_iterator(&fat_it, &query->m_fat_it);
  if ( vostok::resources::query_result::need_create_resource_inplace_in_creation_or_inline_data(v4, (int)query) )
  {
    vostok::resources::query_result::bind_unmanaged_resource_buffer_to_creation_or_inline_data(v5, (int)query);
    vostok::resources::query_result::send_to_create_resource(v6, (int)query);
    return;
  }
  if ( fat_it.m_node )
  {
    if ( vostok::vfs::vfs_iterator::is_compressed(p_m_fat_it) )
    {
      v7 = vostok::vfs::vfs_iterator::data_node(&fat_it);
      if ( !vostok::vfs::base_node<1>::is_inlined(v7) )
      {
        compressed_resource_if_needed = vostok::resources::query_result::allocate_compressed_resource_if_needed(
                                          v8,
                                          (int)query);
        if ( !compressed_resource_if_needed )
        {
          if ( !_InterlockedExchangeAdd(&query->m_query_end_guard, 0xFFFFFFFF) )
            vostok::resources::query_result::end_query_might_destroy_this_impl(0, query);
          return;
        }
        if ( compressed_resource_if_needed == 2 )
          return;
      }
    }
  }
  m_size = query->m_raw_unmanaged_buffer.m_size;
  v19.m_data = query->m_raw_unmanaged_buffer.m_data;
  v19.m_size = m_size;
  if ( vostok::mutable_buffer::operator bool(&v19) )
    goto LABEL_14;
  thread_id = (vostok::resources::resources_manager *)vostok::resources::query_result::allocate_thread_id(
                                                        v11,
                                                        (int)query);
  if ( thread_id != (vostok::resources::resources_manager *)GetCurrentThreadId() )
  {
    thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                          vostok::resources::g_resources_manager.m_variable,
                          vostok::resources::g_resources_manager.m_variable,
                          (unsigned int)thread_id,
                          1);
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v15,
      &thread_local_data->to_allocate_raw_resource.m_size,
      query,
      v18);
    vostok::resources::resources_manager::wakeup_thread_by_id_if_needed(
      thread_id,
      (int)vostok::resources::g_resources_manager.m_variable);
    return;
  }
  raw_unmanaged_resource_if_needed = vostok::resources::query_result::allocate_raw_unmanaged_resource_if_needed(
                                       v13,
                                       (int)query);
  if ( raw_unmanaged_resource_if_needed == 1 )
  {
LABEL_14:
    vostok::resources::allocate_functionality::continue_prepare_raw_resource_for_inplace_unmanaged_cook(
      (vostok::vfs::vfs_iterator *)query,
      (vostok::resources::allocate_functionality *)v18);
  }
  else if ( !raw_unmanaged_resource_if_needed )
  {
    vostok::resources::query_result::end_query_might_destroy_this(v17, (int)query);
  }
}
