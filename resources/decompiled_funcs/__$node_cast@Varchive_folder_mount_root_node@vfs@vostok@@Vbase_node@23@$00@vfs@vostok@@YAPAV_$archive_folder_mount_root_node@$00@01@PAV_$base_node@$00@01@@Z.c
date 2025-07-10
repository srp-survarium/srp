vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_folder_mount_root<1>(node);
  else
    return 0;
}
