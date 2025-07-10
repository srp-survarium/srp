void __userpurge vostok::resources::allocate_functionality::prepare_raw_resource_for_inplace_managed_cook(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::allocate_functionality *this,
        vostok::resources::reallocating_bool reallocating)
{
  vostok::resources::query_result *m_size; // ecx
  int raw_managed_resource_if_needed; // ebx
  vostok::resources::query_result *v6; // ecx
  vostok::resources::query_result *v7; // ecx
  vostok::vfs::base_node<1> *v8; // eax
  vostok::resources::query_result *v9; // ecx
  vostok::resources::query_result *v10; // ecx
  vostok::resources::query_result *v11; // ecx
  vostok::vfs::base_node<1> *v12; // eax
  vostok::resources::query_result *v13; // ecx
  vostok::resources::query_result *v14; // ecx
  vostok::resources::query_result *v15; // ecx
  int compressed_resource_if_needed; // eax
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v17; // ecx
  vostok::vfs::vfs_iterator fat_it; // [esp+10h] [ebp-10h] BYREF

  vostok::vfs::vfs_iterator::vfs_iterator(&fat_it, &query->m_fat_it);
  m_size = (vostok::resources::query_result *)query->m_creation_data_from_user.m_size;
  if ( query->m_creation_data_from_user.m_data || m_size )
  {
    raw_managed_resource_if_needed = vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
                                       m_size,
                                       (int)query);
    if ( raw_managed_resource_if_needed == 1 )
    {
      vostok::resources::query_result::copy_data_to_resource(
        (vostok::resources::query_result *)query->m_creation_data_from_user.m_size,
        (int)query,
        query->m_creation_data_from_user);
      vostok::resources::query_result::send_to_create_resource(v6, (int)query);
    }
  }
  else if ( fat_it.m_node )
  {
    v8 = vostok::vfs::vfs_iterator::data_node(&fat_it);
    if ( !vostok::vfs::base_node<1>::is_inlined(v8) || vostok::vfs::vfs_iterator::is_compressed(&fat_it) )
    {
      v12 = vostok::vfs::vfs_iterator::data_node(&fat_it);
      if ( vostok::vfs::base_node<1>::is_inlined(v12) && vostok::vfs::vfs_iterator::is_compressed(&fat_it) )
      {
        raw_managed_resource_if_needed = vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
                                           v13,
                                           (int)query);
        if ( raw_managed_resource_if_needed == 1 )
          vostok::resources::query_result::on_load_operation_end(v14, (int)query);
      }
      else
      {
        if ( vostok::vfs::vfs_iterator::is_compressed(&fat_it) )
        {
          compressed_resource_if_needed = vostok::resources::query_result::allocate_compressed_resource_if_needed(
                                            v15,
                                            (int)query);
        }
        else
        {
          if ( !this )
          {
            vostok::resources::resources_manager::on_allocated_raw_resource(
              vostok::resources::g_resources_manager.m_variable,
              query,
              (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v15);
            return;
          }
          compressed_resource_if_needed = vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
                                            v15,
                                            (int)query);
        }
        raw_managed_resource_if_needed = compressed_resource_if_needed;
        if ( compressed_resource_if_needed == 1 )
          vostok::resources::resources_manager::on_allocated_raw_resource(
            vostok::resources::g_resources_manager.m_variable,
            query,
            v17);
      }
    }
    else
    {
      raw_managed_resource_if_needed = vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
                                         v9,
                                         (int)query);
      if ( raw_managed_resource_if_needed == 1 )
      {
        vostok::resources::query_result::copy_inline_data_to_resource_if_needed(v10, (vostok::vfs::vfs_iterator *)query);
        vostok::resources::query_result::send_to_create_resource(v11, (int)query);
      }
    }
  }
  else
  {
    raw_managed_resource_if_needed = vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
                                       0,
                                       (int)query);
    if ( raw_managed_resource_if_needed == 1 )
      vostok::resources::query_result::send_to_create_resource(v7, (int)query);
  }
  if ( !raw_managed_resource_if_needed && !_InterlockedExchangeAdd(&query->m_query_end_guard, 0xFFFFFFFF) )
    vostok::resources::query_result::end_query_might_destroy_this_impl(0, query);
}
