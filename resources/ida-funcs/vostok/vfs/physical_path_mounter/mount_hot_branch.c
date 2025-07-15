void __usercall vostok::vfs::physical_path_mounter::mount_hot_branch(
        vostok::vfs::physical_path_mounter *this@<ecx>,
        int a2@<edi>)
{
  vostok::vfs::base_node<1> *v2; // ecx
  vostok::vfs::base_node<1> *v3; // ebx
  int v4; // eax
  vostok::fixed_string<260> *v5; // ecx
  vostok::fs_new::virtual_path_string *v6; // ecx
  char *m_end; // eax
  vostok::fs_new::device_file_system_proxy_base *v8; // ecx
  vostok::vfs::base_node<1> *node_of_mount; // esi
  unsigned __int16 m_flags; // ax
  vostok::vfs::physical_folder_node<1> *v11; // eax
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v12; // ecx
  vostok::fs_new::native_path_string v13; // [esp+8h] [ebp-5B0h] BYREF
  vostok::fs_new::virtual_path_string v14; // [esp+120h] [ebp-498h] BYREF
  vostok::fs_new::virtual_path_string out_relative_path; // [esp+238h] [ebp-380h] BYREF
  vostok::fs_new::virtual_path_string root_to_relate; // [esp+350h] [ebp-268h] BYREF
  vostok::fs_new::virtual_path_string out_string; // [esp+468h] [ebp-150h] BYREF
  vostok::fs_new::path_part_iterator v18; // [esp+584h] [ebp-34h] BYREF
  vostok::fs_new::path_part_iterator v19; // [esp+59Ch] [ebp-1Ch] BYREF
  vostok::vfs::base_node<1> *v20; // [esp+5B4h] [ebp-4h]

  v2 = *(vostok::vfs::base_node<1> **)(a2 + 1288);
  root_to_relate.m_string.m_begin = root_to_relate.m_string.m_buffer;
  root_to_relate.m_string.m_end = root_to_relate.m_string.m_buffer;
  root_to_relate.m_string.m_max_end = &root_to_relate.m_separator;
  root_to_relate.m_string.m_buffer[0] = 0;
  root_to_relate.m_separator = 47;
  vostok::vfs::base_node<1>::get_full_path(v2, &root_to_relate);
  out_relative_path.m_string.m_begin = out_relative_path.m_string.m_buffer;
  out_relative_path.m_string.m_end = out_relative_path.m_string.m_buffer;
  out_relative_path.m_string.m_max_end = &out_relative_path.m_separator;
  out_relative_path.m_string.m_buffer[0] = 0;
  out_relative_path.m_separator = 47;
  vostok::fs_new::convert_to_relative_path<vostok::fs_new::virtual_path_string,vostok::fs_new::virtual_path_string>(
    &root_to_relate,
    &out_relative_path,
    (const vostok::fs_new::virtual_path_string *)(a2 + 72));
  v3 = (vostok::vfs::base_node<1> *)vostok::fs_new::path_crc32(
                                      root_to_relate.m_string.m_begin,
                                      root_to_relate.m_string.m_end - root_to_relate.m_string.m_begin,
                                      0);
  vostok::fixed_string<260>::fixed_string<260>(&v14.m_string, &root_to_relate.m_string);
  v4 = *(_DWORD *)(a2 + 1312);
  v14.m_separator = 47;
  vostok::fixed_string<260>::fixed_string<260>(v5, &v13.m_string, *(char **)(v4 + 40));
  v20 = 0;
  v13.m_separator = 92;
  vostok::fs_new::path_string_impl::begin_part(&out_relative_path, (int)&v19);
  vostok::fs_new::path_part_iterator::path_part_iterator(&v18, 0, include_empty_string_in_iteration_false, 0);
  while ( vostok::fs_new::path_part_iterator::operator!=(&v19, &v18) )
  {
    out_string.m_string.m_begin = out_string.m_string.m_buffer;
    out_string.m_string.m_end = out_string.m_string.m_buffer;
    out_string.m_string.m_max_end = &out_string.m_separator;
    out_string.m_string.m_buffer[0] = 0;
    out_string.m_separator = 47;
    vostok::fs_new::path_part_iterator::assign_to_string<vostok::fs_new::virtual_path_string>(&v19, &out_string);
    vostok::fs_new::virtual_path_string::append_path(v6, (int)&v14, &out_string);
    m_end = out_string.m_string.m_end;
    if ( out_string.m_string.m_end != out_string.m_string.m_begin )
    {
      vostok::buffer_string::appendf(
        &v13,
        (vostok::buffer_string *)(out_string.m_string.m_end - out_string.m_string.m_begin),
        (vostok::buffer_string *)&stru_7FCCD0,
        (const char *)0x5C,
        out_string.m_string.m_begin);
      m_end = out_string.m_string.m_end;
    }
    v3 = (vostok::vfs::base_node<1> *)vostok::fs_new::path_crc32(
                                        out_string.m_string.m_begin,
                                        m_end - out_string.m_string.m_begin,
                                        (unsigned int)v3);
    node_of_mount = vostok::vfs::find_node_of_mount(
                      (vostok::vfs::vfs_hashset *)(*(_DWORD *)(a2 + 1316) + 24),
                      &v14,
                      (__int16)v3,
                      *(_DWORD *)(a2 + 1320));
    if ( !node_of_mount )
      node_of_mount = vostok::vfs::physical_path_mounter::add_physical_node(
                        (vostok::vfs::physical_path_mounter *)a2,
                        &out_string,
                        v8,
                        &v14,
                        v3,
                        &v13,
                        v20);
    if ( *(_DWORD *)(a2 + 68) == 3 || !node_of_mount )
      return;
    m_flags = node_of_mount->m_flags;
    if ( (m_flags & 2) != 0 && (m_flags & 1) != 0 )
    {
      v11 = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(node_of_mount);
      v8 = (vostok::fs_new::device_file_system_proxy_base *)v11->m_folder_flags.m_flags;
      if ( ((unsigned __int8)v8 & 1) == 0 )
        vostok::vfs::physical_path_mounter::mount_physical_folder(
          (vostok::vfs::physical_path_mounter *)a2,
          &v14,
          v11,
          &v13,
          (unsigned int)v3);
      if ( *(_DWORD *)(a2 + 68) == 3 )
        return;
    }
    v20 = node_of_mount;
    vostok::fs_new::path_part_iterator::operator++((vostok::fs_new::path_part_iterator *)v8, (int)&v19);
  }
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
    v12,
    (int *)(a2 + 64),
    *(vostok::vfs::vfs_mount **)(*(_DWORD *)(a2 + 1312) + 56));
}
