void __usercall vostok::resources::allocate_functionality::continue_prepare_raw_resource_for_inplace_unmanaged_cook(
        vostok::vfs::vfs_iterator *query@<eax>)
{
  vostok::vfs::vfs_iterator *v2; // eax
  vostok::vfs::vfs_hashset *m_hashset; // ecx
  vostok::vfs::base_node<1> *m_link_target; // edx
  vostok::vfs::base_node<1> *m_node; // edi
  const char *v6; // eax
  vostok::resources::query_result *v7; // ecx
  vostok::vfs::base_node<1> *v8; // eax
  vostok::resources::query_result *v9; // ecx
  vostok::resources::query_result *v10; // ecx
  vostok::threading::mutex *v11; // ecx
  vostok::resources::resources_manager *v12; // [esp+0h] [ebp-18h]
  vostok::vfs::vfs_iterator v13; // [esp+8h] [ebp-10h] BYREF

  v2 = query + 10;
  m_hashset = v2->m_hashset;
  m_link_target = v2->m_link_target;
  m_node = v2->m_node;
  v13.m_type = v2->m_type;
  v6 = (const char *)query[13].m_hashset;
  v13.m_hashset = m_hashset;
  v7 = (vostok::resources::query_result *)query[13].m_node;
  v13.m_node = m_node;
  v13.m_link_target = m_link_target;
  if ( v6 || v7 )
  {
    vostok::resources::query_result::copy_data_to_resource(
      v7,
      (vostok::const_buffer)__PAIR64__((unsigned int)v6, (unsigned int)query),
      (unsigned int)v7);
LABEL_10:
    vostok::resources::query_result::send_to_create_resource(v7, (int)query, v12);
    return;
  }
  if ( !m_node )
    goto LABEL_10;
  v8 = m_link_target;
  if ( !m_link_target )
    v8 = m_node;
  if ( (v8->m_flags & 0x40) != 0 && !vostok::vfs::vfs_iterator::is_compressed(&v13) )
  {
    vostok::resources::query_result::copy_inline_data_to_resource_if_needed(v9, query);
    goto LABEL_10;
  }
  if ( !m_link_target )
    m_link_target = m_node;
  if ( (m_link_target->m_flags & 0x40) != 0 && vostok::vfs::vfs_iterator::is_compressed(&v13) )
  {
    vostok::resources::query_result::on_load_operation_end(v10, (int)query);
  }
  else
  {
    vostok::vfs::vfs_iterator::is_compressed(&v13);
    vostok::resources::resources_manager::on_allocated_raw_resource((vostok::resources::query_result *)query, v11, v12);
  }
}
