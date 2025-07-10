vostok::vfs::physical_file_mount_root_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::mount_root_node_base,1>(
        vostok::vfs::mount_root_node_base<1> *node)
{
  if ( node )
    return vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::base_node,1>(node->node.pointer);
  else
    return 0;
}
