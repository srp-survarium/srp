vostok::vfs::vfs_mount *__cdecl vostok::vfs::mount_of_node<1>(vostok::vfs::base_node<1> *node)
{
  vostok::vfs::mount_root_node_base<1> *pointer; // [esp+0h] [ebp-Ch]

  if ( (node->m_flags & 0x400) == 0x400 )
    return 0;
  if ( (node->m_flags & 8) == 8 )
    pointer = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(node);
  else
    pointer = node->m_mount_root.pointer;
  return pointer->mount.pointer;
}
