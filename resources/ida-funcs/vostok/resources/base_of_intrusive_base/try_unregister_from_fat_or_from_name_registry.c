bool __userpurge vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>@<al>(
        vostok::resources::managed_resource *const object@<eax>,
        vostok::resources::base_of_intrusive_base *this,
        volatile int count_that_allows_unregister)
{
  vostok::vfs::vfs_iterator *p_m_fat_it; // eax
  vostok::vfs::vfs_hashset *m_hashset; // ebx
  vostok::vfs::base_node<1> *m_node; // edi
  vostok::resources::resource_flags *v7; // ecx
  bool result; // al
  vostok::resources::name_registry_entry *m_name_registry_entry; // edi
  vostok::threading::mutex *v10; // ecx
  vostok::vfs::vfs_iterator v11; // [esp-14h] [ebp-34h]
  vostok::resources::resources_manager *v12; // [esp+0h] [ebp-20h]
  vostok::vfs::base_node<1> *m_link_target; // [esp+18h] [ebp-8h]

  p_m_fat_it = &object->m_fat_it;
  m_hashset = p_m_fat_it->m_hashset;
  m_node = p_m_fat_it->m_node;
  m_link_target = p_m_fat_it->m_link_target;
  if ( vostok::resources::resource_flags::cast_base_of_intrusive_base(object)->m_reference_count
    && vostok::resources::resource_flags::cast_base_of_intrusive_base(v7)->m_reference_count > (unsigned int)count_that_allows_unregister )
  {
    return 0;
  }
  if ( m_node
    && vostok::resources::base_of_intrusive_base::is_associated_with_fat(
         (vostok::resources::base_of_intrusive_base *)v7,
         (vostok::vfs::vfs_hashset *)object) )
  {
    *(_QWORD *)&v11.m_hashset = __PAIR64__((unsigned int)m_hashset, count_that_allows_unregister);
    *(_QWORD *)&v11.m_link_target = __PAIR64__((unsigned int)m_link_target, (unsigned int)m_node);
    if ( !vostok::resources::try_clean_associated(v11) )
      return 0;
    vostok::resources::resource_base::on_deassociated_from_fat(object);
  }
  m_name_registry_entry = object->m_name_registry_entry;
  if ( m_name_registry_entry )
  {
    vostok::threading::mutex::lock(
      (vostok::threading::mutex *)v7,
      (_RTL_CRITICAL_SECTION *)&s_resources_manager_buffer.m_name_registry_mutex);
    if ( this->m_reference_count > count_that_allows_unregister )
    {
      LeaveCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_name_registry_mutex);
      return 0;
    }
    vostok::resources::resources_manager::push_name_registry_to_delete(m_name_registry_entry, v10, v12);
    object->m_name_registry_entry = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_name_registry_mutex);
  }
  vostok::resources::resource_base::clean_sub_fat_and_fat_it(object);
  result = 1;
  _InterlockedOr(
    &object->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
    0x800u);
  return result;
}
