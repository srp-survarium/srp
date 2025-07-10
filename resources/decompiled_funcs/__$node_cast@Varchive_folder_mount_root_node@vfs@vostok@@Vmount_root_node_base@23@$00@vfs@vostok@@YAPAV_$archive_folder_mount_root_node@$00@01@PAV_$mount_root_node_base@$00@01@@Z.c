vostok::vfs::archive_folder_mount_root_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::mount_root_node_base,1>(
        vostok::vfs::mount_root_node_base<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_folder_mount_root<1>(node->node.pointer);
  else
    return 0;
}
