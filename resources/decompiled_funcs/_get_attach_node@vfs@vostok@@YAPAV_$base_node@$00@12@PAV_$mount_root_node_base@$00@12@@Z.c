vostok::vfs::base_node<1> *__cdecl vostok::vfs::get_attach_node(vostok::vfs::mount_root_node_base<1> *node)
{
  const vostok::vfs::archive_folder_mount_root_node<1> *archive_mount; // [esp+4h] [ebp-4h]

  archive_mount = vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::mount_root_node_base,1>(node);
  if ( archive_mount )
    return archive_mount->attach_node.pointer;
  else
    return 0;
}
