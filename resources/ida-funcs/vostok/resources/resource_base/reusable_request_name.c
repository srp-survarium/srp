vostok::fs_new::virtual_path_string *__userpurge vostok::resources::resource_base::reusable_request_name@<eax>(
        vostok::resources::resource_base *this@<ecx>,
        vostok::resources::resource_base *a2@<eax>,
        vostok::fs_new::virtual_path_string *result)
{
  bool is_associated_with; // al
  vostok::resources::unmanaged_resource *v5; // esi
  vostok::resources::name_registry_entry *m_name_registry_entry; // edi
  vostok::vfs::vfs_iterator v8; // [esp+2Ch] [ebp-64h] BYREF
  vostok::resources::resource_base *v9; // [esp+3Ch] [ebp-54h]
  vostok::resources::base_of_intrusive_base *v10; // [esp+40h] [ebp-50h]
  vostok::vfs::vfs_iterator si128; // [esp+50h] [ebp-40h] BYREF
  vostok::vfs::vfs_iterator v12; // [esp+60h] [ebp-30h] BYREF
  vostok::vfs::vfs_iterator v13; // [esp+70h] [ebp-20h] BYREF
  vostok::vfs::vfs_iterator it; // [esp+80h] [ebp-10h] BYREF

  vostok::vfs::vfs_iterator::vfs_iterator(&si128);
  if ( (a2->m_flags.m_flags & 1) != 0 && a2 )
  {
    vostok::vfs::vfs_iterator::vfs_iterator(&v12, &a2->m_fat_it);
    si128 = (vostok::vfs::vfs_iterator)_mm_load_si128((const __m128i *)&v12);
    if ( !v12.m_node )
      goto LABEL_10;
    vostok::vfs::vfs_iterator::vfs_iterator(&it, &a2->m_fat_it);
    v9 = a2;
    vostok::vfs::vfs_iterator::vfs_iterator(&v8, &it);
    is_associated_with = vostok::resources::is_associated_with(v8, v9);
  }
  else
  {
    v5 = (a2->m_flags.m_flags & 4) != 4 ? 0 : (vostok::resources::unmanaged_resource *)a2;
    vostok::vfs::vfs_iterator::vfs_iterator(&v13, &v5->m_fat_it);
    si128 = (vostok::vfs::vfs_iterator)_mm_load_si128((const __m128i *)&v13);
    if ( !v13.m_node )
      goto LABEL_10;
    is_associated_with = vostok::resources::base_of_intrusive_base::is_associated_with_fat(v10, v5);
  }
  if ( si128.m_node )
  {
    if ( is_associated_with )
    {
      vostok::vfs::vfs_iterator::get_virtual_path(&si128, result);
      return result;
    }
    goto LABEL_12;
  }
LABEL_10:
  m_name_registry_entry = a2->m_name_registry_entry;
  if ( m_name_registry_entry )
  {
    vostok::fs_new::virtual_path_string::virtual_path_string(result, &m_name_registry_entry->name);
    return result;
  }
LABEL_12:
  vostok::fs_new::virtual_path_string::virtual_path_string(result, (const char (*)[1])&buf);
  return result;
}
