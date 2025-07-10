vostok::vfs::physical_file_mount_root_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_physical_file_mount_root<1>(node);
  else
    return 0;
}
