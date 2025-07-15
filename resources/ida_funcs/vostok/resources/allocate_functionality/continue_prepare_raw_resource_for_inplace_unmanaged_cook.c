void __usercall vostok::resources::allocate_functionality::continue_prepare_raw_resource_for_inplace_unmanaged_cook(
        vostok::vfs::vfs_iterator *query@<eax>,
        vostok::resources::allocate_functionality *this)
{
  vostok::resources::query_result *m_node; // ecx
  vostok::resources::query_result *v4; // ecx
  vostok::vfs::base_node<1> *v5; // eax
  vostok::resources::query_result *v6; // ecx
  vostok::vfs::base_node<1> *v7; // eax
  vostok::resources::query_result *v8; // ecx
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v9; // ecx
  vostok::vfs::vfs_iterator fat_it; // [esp+8h] [ebp-14h] BYREF

  vostok::vfs::vfs_iterator::vfs_iterator(&fat_it, query + 10);
  m_node = (vostok::resources::query_result *)query[13].m_node;
  if ( query[13].m_hashset || m_node )
  {
    vostok::resources::query_result::copy_data_to_resource(
      m_node,
      (int)query,
      *(vostok::const_buffer *)&query[13].m_hashset);
    vostok::resources::query_result::send_to_create_resource(v4, (int)query);
    return;
  }
  if ( !fat_it.m_node )
    goto LABEL_8;
  v5 = vostok::vfs::vfs_iterator::data_node(&fat_it);
  if ( vostok::vfs::base_node<1>::is_inlined(v5) && !vostok::vfs::vfs_iterator::is_compressed(&fat_it) )
  {
    vostok::resources::query_result::copy_inline_data_to_resource_if_needed(v6, query);
LABEL_8:
    vostok::resources::query_result::send_to_create_resource(m_node, (int)query);
    return;
  }
  v7 = vostok::vfs::vfs_iterator::data_node(&fat_it);
  if ( vostok::vfs::base_node<1>::is_inlined(v7) && vostok::vfs::vfs_iterator::is_compressed(&fat_it) )
  {
    vostok::resources::query_result::on_load_operation_end(v8, (int)query);
  }
  else
  {
    vostok::vfs::vfs_iterator::is_compressed(&fat_it);
    vostok::resources::resources_manager::on_allocated_raw_resource(
      vostok::resources::g_resources_manager.m_variable,
      (vostok::resources::query_result *)query,
      v9);
  }
}
