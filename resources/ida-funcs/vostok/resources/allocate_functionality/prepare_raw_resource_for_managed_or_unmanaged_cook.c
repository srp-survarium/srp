void __userpurge vostok::resources::allocate_functionality::prepare_raw_resource_for_managed_or_unmanaged_cook(
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
  vostok::vfs::base_node<1> *v10; // eax
  vostok::resources::query_result *v11; // ecx
  vostok::resources::query_result *v12; // ecx
  vostok::resources::query_result *v13; // ecx
  int raw_managed_resource_if_needed; // esi
  vostok::resources::query_result *v15; // ecx
  int compressed_resource_if_needed; // eax
  vostok::resources::resources_manager *v17; // [esp+0h] [ebp-1Ch]
  vostok::vfs::vfs_iterator v18; // [esp+8h] [ebp-14h] BYREF

  p_m_fat_it = &query->m_fat_it;
  m_hashset = p_m_fat_it->m_hashset;
  m_node = p_m_fat_it->m_node;
  m_link_target = p_m_fat_it->m_link_target;
  v18.m_type = p_m_fat_it->m_type;
  m_data = query->m_creation_data_from_user.m_data;
  v18.m_hashset = m_hashset;
  m_size = (vostok::resources::query_result *)query->m_creation_data_from_user.m_size;
  v18.m_node = m_node;
  v18.m_link_target = m_link_target;
  if ( m_data || m_size || !m_node )
  {
    vostok::resources::query_result::prepare_final_resource(m_size, query);
    return;
  }
  v10 = m_link_target;
  if ( !m_link_target )
    v10 = m_node;
  if ( (v10->m_flags & 0x40) != 0 && !vostok::vfs::vfs_iterator::is_compressed(&v18) )
  {
    vostok::resources::query_result::on_load_operation_end(v11, (int)query);
    return;
  }
  if ( !m_link_target )
    m_link_target = m_node;
  if ( (m_link_target->m_flags & 0x40) != 0 && vostok::vfs::vfs_iterator::is_compressed(&v18) )
  {
    raw_managed_resource_if_needed = vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
                                       v12,
                                       (int)query);
    if ( raw_managed_resource_if_needed == 1 )
      vostok::resources::query_result::on_load_operation_end(v13, (int)query);
  }
  else
  {
    if ( vostok::vfs::vfs_iterator::is_compressed(&v18) )
    {
      compressed_resource_if_needed = vostok::resources::query_result::allocate_compressed_resource_if_needed(
                                        v15,
                                        (int)query);
    }
    else
    {
      if ( !this )
      {
        vostok::resources::resources_manager::on_allocated_raw_resource(query, (vostok::threading::mutex *)v15, v17);
        return;
      }
      compressed_resource_if_needed = vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
                                        v15,
                                        (int)query);
    }
    raw_managed_resource_if_needed = compressed_resource_if_needed;
    if ( compressed_resource_if_needed == 1 )
      vostok::resources::resources_manager::on_allocated_raw_resource(query, (vostok::threading::mutex *)v13, v17);
  }
  if ( !raw_managed_resource_if_needed )
    vostok::resources::query_result::end_query_might_destroy_this(v13, (int)query);
}
