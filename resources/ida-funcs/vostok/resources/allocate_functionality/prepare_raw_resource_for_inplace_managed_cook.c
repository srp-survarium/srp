void __userpurge vostok::resources::allocate_functionality::prepare_raw_resource_for_inplace_managed_cook(
        vostok::resources::query_result *query@<eax>,
        vostok::resources::allocate_functionality *this,
        vostok::resources::reallocating_bool reallocating)
{
  vostok::vfs::vfs_iterator *p_m_fat_it; // eax
  vostok::vfs::vfs_hashset *m_hashset; // ecx
  vostok::vfs::base_node<1> *m_node; // esi
  vostok::vfs::base_node<1> *m_link_target; // edx
  const char *m_data; // eax
  vostok::resources::query_result *m_size; // ecx
  vostok::resources::query_result *v10; // ecx
  int raw_managed_resource_if_needed; // ebx
  vostok::vfs::base_node<1> *v12; // eax
  vostok::resources::query_result *v13; // ecx
  vostok::resources::query_result *v14; // ecx
  vostok::resources::query_result *v15; // ecx
  int compressed_resource_if_needed; // eax
  vostok::const_buffer v17; // [esp-Ch] [ebp-30h]
  vostok::resources::resources_manager *v18; // [esp+0h] [ebp-24h]
  vostok::vfs::vfs_iterator v19; // [esp+10h] [ebp-14h] BYREF

  p_m_fat_it = &query->m_fat_it;
  m_hashset = p_m_fat_it->m_hashset;
  m_node = p_m_fat_it->m_node;
  m_link_target = p_m_fat_it->m_link_target;
  v19.m_type = p_m_fat_it->m_type;
  m_data = query->m_creation_data_from_user.m_data;
  v19.m_hashset = m_hashset;
  m_size = (vostok::resources::query_result *)query->m_creation_data_from_user.m_size;
  v19.m_node = m_node;
  v19.m_link_target = m_link_target;
  if ( m_data || m_size )
  {
    raw_managed_resource_if_needed = vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
                                       m_size,
                                       (int)query);
    if ( raw_managed_resource_if_needed != 1 )
      goto LABEL_28;
    v17.m_size = (unsigned int)query->m_creation_data_from_user.m_data;
    v17.m_data = (const char *)query;
    vostok::resources::query_result::copy_data_to_resource(v10, v17, query->m_creation_data_from_user.m_size);
LABEL_14:
    vostok::resources::query_result::send_to_create_resource(v10, (int)query, v18);
    goto LABEL_28;
  }
  if ( !m_node )
  {
    raw_managed_resource_if_needed = vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
                                       0,
                                       (int)query);
    if ( raw_managed_resource_if_needed != 1 )
      goto LABEL_28;
    goto LABEL_14;
  }
  v12 = m_link_target;
  if ( !m_link_target )
    v12 = m_node;
  if ( (v12->m_flags & 0x40) != 0 && !vostok::vfs::vfs_iterator::is_compressed(&v19) )
  {
    raw_managed_resource_if_needed = vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
                                       v13,
                                       (int)query);
    if ( raw_managed_resource_if_needed != 1 )
      goto LABEL_28;
    vostok::resources::query_result::copy_inline_data_to_resource_if_needed(v10, (vostok::vfs::vfs_iterator *)query);
    goto LABEL_14;
  }
  if ( !m_link_target )
    m_link_target = m_node;
  if ( (m_link_target->m_flags & 0x40) != 0 && vostok::vfs::vfs_iterator::is_compressed(&v19) )
  {
    raw_managed_resource_if_needed = vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
                                       v14,
                                       (int)query);
    if ( raw_managed_resource_if_needed == 1 )
      vostok::resources::query_result::on_load_operation_end(v10, (int)query);
  }
  else
  {
    if ( vostok::vfs::vfs_iterator::is_compressed(&v19) )
    {
      compressed_resource_if_needed = vostok::resources::query_result::allocate_compressed_resource_if_needed(
                                        v15,
                                        (int)query);
    }
    else
    {
      if ( !this )
      {
        vostok::resources::resources_manager::on_allocated_raw_resource(query, (vostok::threading::mutex *)v15, v18);
        return;
      }
      compressed_resource_if_needed = vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
                                        v15,
                                        (int)query);
    }
    raw_managed_resource_if_needed = compressed_resource_if_needed;
    if ( compressed_resource_if_needed == 1 )
      vostok::resources::resources_manager::on_allocated_raw_resource(query, (vostok::threading::mutex *)v10, v18);
  }
LABEL_28:
  if ( !raw_managed_resource_if_needed )
    vostok::resources::query_result::end_query_might_destroy_this(v10, (int)query);
}
