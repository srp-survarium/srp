void __thiscall vostok::vfs::unmounter::unmount(
        vostok::vfs::unmounter *this,
        vostok::fs_new::virtual_path_string *path)
{
  int v3; // edi
  unsigned int v4; // eax
  vostok::vfs::mount_root_node_base<1> *v5; // esi
  vostok::vfs::base_node<1> *v6; // eax
  vostok::vfs::unmounter *v7; // ecx
  vostok::vfs::base_node<1> *node_to_unmount; // [esp+10h] [ebp-Ch] BYREF
  vostok::vfs::base_node<1> *overlap_of_node_to_unmount; // [esp+14h] [ebp-8h] BYREF
  vostok::vfs::base_node<1> *what_node; // [esp+18h] [ebp-4h] BYREF
  vostok::fs_new::virtual_path_string *patha; // [esp+24h] [ebp+8h]

  v3 = 0;
  v4 = vostok::fs_new::path_crc32(
         *(const char **)path->m_string.m_begin,
         *((_DWORD *)path->m_string.m_begin + 1) - *(_DWORD *)path->m_string.m_begin,
         0);
  v5 = *(vostok::vfs::mount_root_node_base<1> **)path->m_string.m_buffer;
  patha = (vostok::fs_new::virtual_path_string *)v4;
  v6 = vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::mount_root_node_base,1>(v5);
  if ( v6 )
    v3 = *(_DWORD *)&v6->m_name[877];
  overlap_of_node_to_unmount = 0;
  what_node = 0;
  node_to_unmount = (vostok::vfs::base_node<1> *)v5;
  vostok::vfs::unmounter::recursive_unmount_node<vostok::vfs::is_part_of_mount>(
    v7,
    (vostok::vfs::unmounter *)path,
    (vostok::fs_new::virtual_path_string *)path->m_string.m_begin,
    (vostok::vfs::is_part_of_mount *)patha,
    &node_to_unmount,
    &overlap_of_node_to_unmount,
    &what_node);
  if ( v3 )
  {
    vostok::vfs::exchange_nodes_impl(
      (vostok::vfs::base_node<1> *)v3,
      (vostok::vfs::base_folder_node<1> *)overlap_of_node_to_unmount,
      (const vostok::fs_new::virtual_path_string *)path->m_string.m_begin,
      (unsigned int)patha,
      (vostok::vfs::virtual_file_system *)path->m_string.m_max_end,
      overlap_of_node_to_unmount,
      what_node,
      *((vostok::vfs::base_node<1> **)path->m_string.m_begin + 303),
      *((vostok::memory::base_allocator **)path->m_string.m_begin + 286));
    if ( (*(_BYTE *)(v3 + 48) & 2) != 0 )
      _InterlockedAnd(
        &vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>((vostok::vfs::base_node<1> *)v3)->m_file_flags.m_flags,
        0xFFFFFFFB);
  }
  else
  {
    vostok::vfs::unmounter::unmount_helper_branch(
      (vostok::vfs::unmounter *)overlap_of_node_to_unmount,
      path,
      (vostok::vfs::base_node<1> *)overlap_of_node_to_unmount->m_mount_root.pointer,
      overlap_of_node_to_unmount,
      what_node,
      (vostok::vfs::is_exact_node *)patha);
  }
  _InterlockedExchangeAdd(&vostok::vfs::s_global_unmounts_counter, 1u);
}
