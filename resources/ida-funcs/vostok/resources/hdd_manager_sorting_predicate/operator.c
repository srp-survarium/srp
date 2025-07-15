bool __usercall vostok::resources::hdd_manager_sorting_predicate::operator()@<al>(
        vostok::resources::query_result *r1@<ecx>,
        vostok::resources::query_result *r2@<eax>)
{
  vostok::vfs::vfs_iterator *p_m_fat_it; // eax
  vostok::vfs::base_node<1> *m_link_target; // edx
  vostok::vfs::base_node<1> *m_node; // ecx
  vostok::vfs::base_node<1> *v7; // ebx
  vostok::vfs::base_node<1> *v8; // edx
  vostok::vfs::vfs_iterator::type_enum m_type; // eax
  vostok::resources::queries_result *m_parent; // ebx
  unsigned int m_quality_index; // eax
  unsigned int v14; // ecx
  unsigned int v15; // edx
  vostok::vfs::vfs_iterator *v16; // ecx
  vostok::vfs::vfs_iterator *v17; // ecx
  vostok::fs_new::native_path_string *v18; // eax
  vostok::vfs::vfs_iterator *v19; // ecx
  unsigned __int64 file_offs; // rdi
  vostok::vfs::vfs_iterator *v21; // ecx
  vostok::fs_new::native_path_string v22; // [esp+10h] [ebp-250h] BYREF
  vostok::fs_new::native_path_string v23; // [esp+124h] [ebp-13Ch] BYREF
  vostok::vfs::vfs_iterator v24; // [esp+238h] [ebp-28h] BYREF
  vostok::vfs::vfs_iterator v25; // [esp+248h] [ebp-18h] BYREF
  vostok::resources::queries_result *v26; // [esp+258h] [ebp-8h]
  vostok::fs_new::native_path_string *physical_path; // [esp+25Ch] [ebp-4h]

  p_m_fat_it = &r1->m_fat_it;
  m_link_target = r1->m_fat_it.m_link_target;
  v24.m_hashset = r1->m_fat_it.m_hashset;
  m_node = r1->m_fat_it.m_node;
  v24.m_type = p_m_fat_it->m_type;
  v7 = r2->m_fat_it.m_link_target;
  v24.m_link_target = m_link_target;
  v25.m_hashset = r2->m_fat_it.m_hashset;
  v8 = r2->m_fat_it.m_node;
  m_type = r2->m_fat_it.m_type;
  v24.m_node = m_node;
  v25.m_node = v8;
  v25.m_link_target = v7;
  v25.m_type = m_type;
  if ( !m_node )
  {
    if ( !v8 )
      return r1 < r2;
    return 1;
  }
  if ( !v8 )
    return 0;
  m_parent = r2->m_parent;
  v26 = r1->m_parent;
  if ( v26 == m_parent )
  {
    m_quality_index = r1->m_quality_index;
    v14 = r2->m_quality_index;
    if ( m_quality_index > v14 )
      return 1;
    if ( m_quality_index < v14 )
      return 0;
  }
  if ( vostok::vfs::vfs_iterator::is_archive(&v24) && vostok::vfs::vfs_iterator::is_archive(&v25) )
  {
    physical_path = vostok::vfs::vfs_iterator::get_physical_path(v16, (int)&v25, &v23);
    v18 = vostok::vfs::vfs_iterator::get_physical_path(v17, (int)&v24, &v22);
    if ( !vostok::detail::strcmp_s(v18->m_string.m_begin, physical_path->m_string.m_begin) )
    {
      file_offs = vostok::vfs::vfs_iterator::get_file_offs(v19, (int)&v25);
      return vostok::vfs::vfs_iterator::get_file_offs(v21, (int)&v24) < file_offs;
    }
    v15 = (unsigned int)v26;
  }
  if ( v15 )
  {
    if ( m_parent )
      return v15 < (unsigned int)m_parent;
    else
      return v15 < (unsigned int)r2;
  }
  if ( m_parent )
    return r1 < (vostok::resources::query_result *)m_parent;
  return r1 < r2;
}
