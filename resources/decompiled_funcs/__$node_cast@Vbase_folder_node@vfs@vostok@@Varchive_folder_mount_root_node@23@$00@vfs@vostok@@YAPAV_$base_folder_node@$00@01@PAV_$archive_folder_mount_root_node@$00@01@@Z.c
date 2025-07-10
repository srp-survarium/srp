vostok::vfs::base_folder_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::archive_folder_mount_root_node,1>(
        vostok::vfs::archive_folder_mount_root_node<1> *node)
{
  if ( node )
    return &node->folder;
  else
    return 0;
}
