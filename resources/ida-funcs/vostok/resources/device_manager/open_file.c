char __userpurge vostok::resources::device_manager::open_file@<al>(
        vostok::resources::device_manager *this@<edi>,
        vostok::fs_new::synchronous_device_interface *device@<eax>,
        void ***out_file,
        vostok::resources::query_result *query)
{
  vostok::vfs::base_node<1> *m_link_target; // edx
  vostok::vfs::vfs_iterator::type_enum m_type; // eax
  vostok::fs_new::file_access::access_enum v9; // ecx
  vostok::fs_new::file_mode::mode_enum v10; // eax
  vostok::fs_new::use_buffering_bool v11; // [esp+0h] [ebp-130h]
  vostok::fs_new::native_path_string v12; // [esp+8h] [ebp-128h] BYREF
  vostok::vfs::vfs_iterator v13; // [esp+120h] [ebp-10h] BYREF
  char v14; // [esp+13Fh] [ebp+Fh]

  if ( (query->m_flags & 8) == 0 )
  {
    m_link_target = query->m_fat_it.m_link_target;
    v13.m_hashset = query->m_fat_it.m_hashset;
    m_type = query->m_fat_it.m_type;
    v13.m_node = query->m_fat_it.m_node;
    v13.m_link_target = m_link_target;
    v13.m_type = m_type;
    if ( !v13.m_node || vostok::vfs::vfs_iterator::is_folder(&v13) )
    {
      query->m_error_type = error_type_file_not_found;
      return 0;
    }
  }
  vostok::resources::query_result::absolute_physical_path(query, (int)&v12);
  if ( (query->m_flags & 2) != 0 )
  {
    v9 = read;
    v10 = open_existing;
  }
  else
  {
    vostok::fs_new::create_folder_r((char *)device, device, &v12, 0);
    v10 = create_always;
    v9 = write;
  }
  v14 = vostok::fs_new::device_file_system_no_watcher_proxy::open(
          &device->m_device,
          v10,
          out_file,
          &v12,
          v9,
          assert_on_fail_false,
          notify_watcher_true,
          v11);
  if ( vostok::detail::strcmp_s(this->m_last_file_name.m_string.m_begin, v12.m_string.m_begin) )
  {
    this->m_sector_data_last_file_pos = -1;
    vostok::fixed_string<260>::operator=(&v12.m_string, &this->m_last_file_name.m_string);
  }
  if ( !v14 )
  {
    query->m_error_type = error_type_cannot_open_file;
    return 0;
  }
  return 1;
}
