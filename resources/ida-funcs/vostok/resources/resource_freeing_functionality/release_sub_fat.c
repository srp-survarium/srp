void __userpurge vostok::resources::resource_freeing_functionality::release_sub_fat(
        vostok::resources::vfs_sub_fat_resource *sub_fat@<edi>,
        vostok::threading::simple_lock *a2@<ecx>,
        vostok::resources::resource_freeing_functionality *this)
{
  unsigned int v3; // ebx
  vostok::resources::resources_to_free_collection *m_collection; // eax
  const vostok::resources::memory_type *type; // ecx

  v3 = 0;
  do
  {
    vostok::resources::resource_freeing_functionality::release_sub_fat_from_parents(sub_fat, a2, this);
    ++v3;
  }
  while ( v3 < 0xA
       && !vostok::resources::resource_base::try_unregister_from_fat_or_from_name_registry(
             sub_fat,
             (vostok::vfs::vfs_hashset *)(sub_fat->m_parent_resources.m_size + 1)) );
  m_collection = this->m_collection;
  sub_fat->m_next_for_grm_observer_list = 0;
  ++m_collection->resources.m_size;
  if ( m_collection->resources.m_first )
    m_collection->resources.m_last->m_next_for_grm_observer_list = sub_fat;
  else
    m_collection->resources.m_first = sub_fat;
  m_collection->resources.m_last = sub_fat;
  vostok::threading::interlocked_or(
    &sub_fat->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
    0x20u);
  type = this->m_collection->collected_memory.type;
  if ( type == sub_fat->m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type )
    this->m_collection->collected_memory.size += sub_fat->m_memory_usage_self.size;
  vostok::resources::resource_freeing_functionality::free_collected(
    (vostok::resources::resource_freeing_functionality *)type,
    (vostok::resources::releasing_functionality)this);
}
