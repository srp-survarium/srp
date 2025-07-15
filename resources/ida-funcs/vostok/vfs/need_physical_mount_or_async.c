bool __usercall vostok::vfs::need_physical_mount_or_async@<al>(
        vostok::vfs::base_node<1> *node@<esi>,
        vostok::vfs::find_enum find_flags,
        vostok::vfs::traverse_enum traverse_type)
{
  vostok::vfs::physical_file_node<1> *v4; // eax

  if ( (node->m_flags & 0x300) != 0 )
    return 0;
  if ( vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(node) )
    return vostok::vfs::need_physical_folder_mount(node, find_flags, traverse_type);
  v4 = vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(node);
  if ( !v4 || traverse_type == traverse_child || traverse_type == traverse_node && (find_flags & 2) != 0 )
    return 0;
  if ( (v4->m_file_flags.m_flags & 1) != 0 )
    return (v4->m_file_flags.m_flags & 2) != 0 && (v4->m_file_flags.m_flags & 4) == 0;
  return 1;
}
