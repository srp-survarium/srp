vostok::vfs::base_node<1> *__usercall vostok::vfs::find_referenced_link_node@<eax>(
        const vostok::vfs::base_node<1> *node@<edi>)
{
  vostok::vfs::virtual_file_system *pointer; // esi
  vostok::vfs::vfs_hashset *v3; // ecx
  vostok::fs_new::virtual_path_string out_path; // [esp+4h] [ebp-118h] BYREF

  if ( !node || (node->m_flags & 0x300) == 0 )
    return 0;
  if ( (node->m_flags & 0x200) == 0x200 )
    return (vostok::vfs::base_node<1> *)*((_DWORD *)node - 2);
  pointer = vostok::vfs::base_node<1>::get_mount_root((vostok::vfs::base_node<1> *)0x200, (int)node)->file_system.pointer;
  out_path.m_string.m_begin = out_path.m_string.m_buffer;
  out_path.m_string.m_end = out_path.m_string.m_buffer;
  out_path.m_string.m_max_end = &out_path.m_separator;
  out_path.m_string.m_buffer[0] = 0;
  out_path.m_separator = 47;
  vostok::vfs::soft_link_node<1>::absolute_path_to_referenced(
    (vostok::vfs::soft_link_node<1> *)&out_path,
    (char **)node - 2,
    &out_path);
  return vostok::vfs::vfs_hashset::find_no_lock(v3, &pointer->hashset, out_path.m_string.m_begin, 1);
}
