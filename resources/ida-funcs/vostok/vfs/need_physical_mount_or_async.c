bool __cdecl vostok::vfs::need_physical_mount_or_async(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::find_enum find_flags,
        vostok::vfs::traverse_enum traverse_type)
{
  _DWORD v5[4]; // [esp+3Ch] [ebp-14h] BYREF
  vostok::vfs::physical_file_node<1> *file_node; // [esp+4Ch] [ebp-4h]

  if ( (node->m_flags & 0x300) != 0 )
    return 0;
  if ( vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(node) )
    return vostok::vfs::need_physical_folder_mount(node, find_flags, traverse_type);
  file_node = vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(node);
  if ( !file_node || traverse_type == traverse_child )
    return 0;
  if ( traverse_type == traverse_node && (find_flags & 2) != 0 )
    return 0;
  v5[2] = v5;
  v5[0] = 1;
  v5[1] = 1;
  if ( (file_node->m_file_flags.m_flags & 1) != 1 )
    return 1;
  return vostok::vfs::physical_file_node<1>::is_archive_file(file_node)
      && !vostok::vfs::physical_file_node<1>::is_mounted_archive(file_node);
}
