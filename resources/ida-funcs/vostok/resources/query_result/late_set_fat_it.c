void __thiscall vostok::resources::query_result::late_set_fat_it(
        vostok::resources::query_result *this,
        vostok::vfs::vfs_iterator new_it,
        vostok::resources::managed_resource *a3)
{
  vostok::resources::vfs_sub_fat_resource *node_sub_fat; // eax
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v4; // ecx
  vostok::particle::particle_system_instance_impl *(__thiscall *v5)(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // edx
  unsigned int writer_thread_id; // ebx
  vostok::vfs::vfs_iterator v7; // [esp-10h] [ebp-2Ch]
  vostok::vfs::vfs_iterator v8; // [esp-10h] [ebp-2Ch]

  if ( (vostok::vfs::base_node<1> *)new_it.m_hashset->m_hashlocks[20].m_readers_writers_counter.writer_thread_id != new_it.m_link_target )
  {
    node_sub_fat = vostok::resources::get_node_sub_fat(new_it.m_link_target, (vostok::vfs::base_node<1> *)this);
    vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      v4,
      (int *)&new_it.m_hashset->m_hashset.m_buffer[90],
      node_sub_fat);
    new_it.m_hashset->m_hashlocks[20].m_readers_writers_counter.whole = *(_QWORD *)&new_it.m_node;
    *(_DWORD *)&new_it.m_hashset->m_hashlocks[21].m_readers_writers_counter.readers_count = new_it.m_type;
    new_it.m_hashset->m_hashlocks[21].m_readers_writers_counter.writer_thread_id = (unsigned int)a3;
    _InterlockedOr((volatile signed __int32 *)&new_it.m_hashset->m_hashset.m_buffer[111], 0x10u);
    _InterlockedExchangeAdd(&s_resources_manager_buffer.m_count_of_pending_query_with_fat_it, 1u);
    v5 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    if ( new_it.m_hashset->m_hashset.m_buffer[97]
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      *(_QWORD *)&v7.m_hashset = *(_QWORD *)&new_it.m_node;
      *(_QWORD *)&v7.m_link_target = __PAIR64__((unsigned int)a3, new_it.m_type);
      vostok::resources::managed_resource::late_set_fat_it(
        a3,
        (vostok::vfs::vfs_iterator *)new_it.m_hashset->m_hashset.m_buffer[97],
        v7);
    }
    if ( *(_DWORD *)&new_it.m_hashset->m_hashlocks[27].m_readers_writers_counter.readers_count && v5 )
    {
      *(_QWORD *)&v8.m_hashset = *(_QWORD *)&new_it.m_node;
      *(_QWORD *)&v8.m_link_target = __PAIR64__((unsigned int)a3, new_it.m_type);
      vostok::resources::managed_resource::late_set_fat_it(
        a3,
        *(vostok::vfs::vfs_iterator **)&new_it.m_hashset->m_hashlocks[27].m_readers_writers_counter.readers_count,
        v8);
    }
    writer_thread_id = new_it.m_hashset->m_hashlocks[27].m_readers_writers_counter.writer_thread_id;
    if ( writer_thread_id )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        *(_QWORD *)(writer_thread_id + 160) = *(_QWORD *)&new_it.m_node;
        *(_DWORD *)(writer_thread_id + 168) = new_it.m_type;
        *(_DWORD *)(writer_thread_id + 172) = a3;
      }
    }
  }
}
