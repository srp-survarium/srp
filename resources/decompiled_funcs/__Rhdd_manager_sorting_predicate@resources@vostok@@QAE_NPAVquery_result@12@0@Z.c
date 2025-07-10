char __userpurge vostok::resources::hdd_manager_sorting_predicate::operator()@<al>(
        vostok::resources::query_result *r1@<eax>,
        vostok::resources::hdd_manager_sorting_predicate *this,
        vostok::resources::query_result *r2)
{
  vostok::resources::queries_result *m_parent; // ebp
  unsigned int v6; // edi
  unsigned int m_quality_index; // eax
  unsigned int v8; // ecx
  vostok::fs_new::native_path_string *v9; // eax
  unsigned __int64 file_offs; // rdi
  vostok::fs_new::native_path_string *physical_path; // [esp-4h] [ebp-25Ch]
  vostok::vfs::vfs_iterator fat_it2; // [esp+10h] [ebp-248h] BYREF
  vostok::vfs::vfs_iterator fat_it1; // [esp+20h] [ebp-238h] BYREF
  vostok::fs_new::native_path_string result; // [esp+30h] [ebp-228h] BYREF
  vostok::fs_new::native_path_string v15; // [esp+144h] [ebp-114h] BYREF

  vostok::vfs::vfs_iterator::vfs_iterator(&fat_it1, &r1->m_fat_it);
  vostok::vfs::vfs_iterator::vfs_iterator(&fat_it2, (const vostok::vfs::vfs_iterator *)&this[160]);
  if ( !fat_it1.m_node )
  {
    if ( !fat_it2.m_node )
      return r1 < (vostok::resources::query_result *)this;
    return 1;
  }
  if ( !fat_it2.m_node )
    return 0;
  m_parent = r1->m_parent;
  v6 = *(_DWORD *)&this[328];
  if ( m_parent != (vostok::resources::queries_result *)v6 )
    goto LABEL_22;
  m_quality_index = r1->m_quality_index;
  v8 = *(_DWORD *)&this[680];
  if ( m_quality_index > v8 )
    return 1;
  if ( m_quality_index < v8 )
    return 0;
LABEL_22:
  if ( vostok::vfs::vfs_iterator::is_archive(&fat_it1)
    && vostok::vfs::vfs_iterator::is_archive(&fat_it2)
    && (physical_path = vostok::vfs::vfs_iterator::get_physical_path(&fat_it2, &result),
        v9 = vostok::vfs::vfs_iterator::get_physical_path(&fat_it1, &v15),
        vostok::fs_new::path_string_impl::operator==(v9, physical_path)) )
  {
    file_offs = vostok::vfs::vfs_iterator::get_file_offs(&fat_it2);
    return vostok::vfs::vfs_iterator::get_file_offs(&fat_it1) < file_offs;
  }
  else if ( m_parent )
  {
    if ( v6 )
      return (unsigned int)m_parent < v6;
    else
      return m_parent < (vostok::resources::queries_result *)this;
  }
  else
  {
    if ( !v6 )
      return r1 < (vostok::resources::query_result *)this;
    return (unsigned int)r1 < v6;
  }
}
