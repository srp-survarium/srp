vostok::vfs::physical_folder_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::physical_folder_mount_root_node,1>(
        vostok::vfs::physical_folder_mount_root_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_physical_folder<1>(node);
  else
    return 0;
}
