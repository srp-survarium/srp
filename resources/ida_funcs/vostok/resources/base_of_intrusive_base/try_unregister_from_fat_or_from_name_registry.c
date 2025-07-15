char __userpurge vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>@<al>(
        vostok::resources::unmanaged_resource *const object@<eax>,
        vostok::resources::base_of_intrusive_base *this,
        vostok::vfs::vfs_hashset *count_that_allows_unregister)
{
  vostok::vfs::vfs_iterator *p_m_fat_it; // edi
  vostok::resources::resource_base *m_flags; // ecx
  vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *p_m_flags; // ebp
  _DWORD *p_m_parent; // eax
  _DWORD *p_m_reference_count; // eax
  vostok::resources::resource_base *v9; // ecx
  vostok::resources::name_registry_entry *m_name_registry_entry; // edi
  _RTL_CRITICAL_SECTION *v11; // ebx
  vostok::vfs::vfs_iterator v13; // [esp-14h] [ebp-48h] BYREF
  vostok::resources::resource_base *v14; // [esp-4h] [ebp-38h]
  vostok::vfs::vfs_iterator fat_it; // [esp+10h] [ebp-24h] BYREF
  vostok::vfs::vfs_iterator it; // [esp+20h] [ebp-14h] BYREF

  p_m_fat_it = &object->m_fat_it;
  vostok::vfs::vfs_iterator::vfs_iterator(&fat_it, &object->m_fat_it);
  p_m_flags = &object->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  if ( (object->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
      & 1) != 0
    && object )
  {
    p_m_parent = &object->m_sub_fat.m_parent;
  }
  else
  {
    m_flags = (vostok::resources::resource_base *)p_m_flags->m_flags;
    if ( (p_m_flags->m_flags & 4) != 0 && object )
      p_m_parent = &object->m_reference_count;
    else
      p_m_parent = 0;
  }
  if ( *p_m_parent )
  {
    if ( (p_m_flags->m_flags & 1) != 0 && object )
    {
      p_m_reference_count = &object->m_sub_fat.m_parent;
    }
    else
    {
      m_flags = (vostok::resources::resource_base *)p_m_flags->m_flags;
      if ( (p_m_flags->m_flags & 4) != 0 && object )
        p_m_reference_count = &object->m_reference_count;
      else
        p_m_reference_count = 0;
    }
    if ( *p_m_reference_count > (unsigned int)count_that_allows_unregister )
      return 0;
  }
  if ( fat_it.m_node )
  {
    vostok::vfs::vfs_iterator::vfs_iterator(&it, p_m_fat_it);
    v14 = object;
    vostok::vfs::vfs_iterator::vfs_iterator(&v13, &it);
    if ( vostok::resources::is_associated_with(v13, v14) )
    {
      vostok::vfs::vfs_iterator::vfs_iterator((vostok::vfs::vfs_iterator *)&v13.m_node, &fat_it);
      v13.m_hashset = count_that_allows_unregister;
      if ( !vostok::resources::try_clean_associated(v13, (unsigned int)v14) )
        return 0;
      vostok::resources::resource_base::on_deassociated_from_fat(v9);
    }
  }
  m_name_registry_entry = object->m_name_registry_entry;
  if ( m_name_registry_entry )
  {
    v11 = (_RTL_CRITICAL_SECTION *)&byte_20168[(unsigned int)vostok::resources::g_resources_manager.m_variable];
    vostok::threading::mutex::lock((vostok::threading::mutex *)&byte_20168[(unsigned int)vostok::resources::g_resources_manager.m_variable]);
    if ( this->m_reference_count > (int)count_that_allows_unregister )
    {
      LeaveCriticalSection(v11);
      return 0;
    }
    vostok::resources::resources_manager::push_name_registry_to_delete(
      (vostok::resources::resources_manager *)this,
      m_name_registry_entry);
    v14 = (vostok::resources::resource_base *)v11;
    object->m_name_registry_entry = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)v14);
  }
  vostok::resources::resource_base::clean_sub_fat_and_fat_it(m_flags);
  vostok::threading::interlocked_or(
    &object->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
    0x800u);
  return 1;
}
