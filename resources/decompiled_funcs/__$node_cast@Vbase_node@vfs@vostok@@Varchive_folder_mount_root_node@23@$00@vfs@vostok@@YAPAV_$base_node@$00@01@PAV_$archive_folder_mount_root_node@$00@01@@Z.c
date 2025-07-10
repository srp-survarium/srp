vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::archive_folder_mount_root_node,1>(
        vostok::vfs::archive_folder_mount_root_node<1> *node)
{
  if ( node )
    return &node->folder.base;
  else
    return 0;
}
