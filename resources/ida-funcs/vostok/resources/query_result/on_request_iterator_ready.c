void __userpurge vostok::resources::query_result::on_request_iterator_ready(
        vostok::vfs::vfs_iterator *it@<eax>,
        vostok::resources::query_result *this,
        bool try_sync_way_only)
{
  volatile int m_flags; // ecx
  vostok::resources::vfs_sub_fat_resource *node_sub_fat; // eax
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v5; // ecx

  m_flags = this->m_flags;
  if ( (m_flags & 0x100) == 0 )
  {
    this->m_fat_it = *it;
    node_sub_fat = vostok::resources::get_node_sub_fat(it->m_node, (vostok::vfs::base_node<1> *)m_flags);
    vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      v5,
      (int *)&this->m_sub_fat,
      node_sub_fat);
    if ( this->m_fat_it.m_node )
    {
      _InterlockedOr(&this->m_flags, 0x10u);
      _InterlockedExchangeAdd(&s_resources_manager_buffer.m_count_of_pending_query_with_fat_it, 1u);
    }
    m_flags = 256;
    _InterlockedOr(&this->m_flags, 0x100u);
  }
  if ( !try_sync_way_only )
    vostok::resources::resources_manager::continue_init_new_query((vostok::resources::resources_manager *)m_flags, this);
}
