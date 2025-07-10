vostok::vfs::archive_folder_mount_root_node<1> *__cdecl vostok::vfs::cast_mount_root_node_base<1>(
        vostok::vfs::base_node<1> *node)
{
  vostok::vfs::archive_folder_mount_root_node<1> *v2; // [esp+0h] [ebp-Ch]
  vostok::vfs::physical_file_mount_root_node<1> *v3; // [esp+4h] [ebp-8h]
  vostok::vfs::physical_folder_mount_root_node<1> *root_node; // [esp+8h] [ebp-4h]

  root_node = vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(node);
  if ( root_node )
    return (vostok::vfs::archive_folder_mount_root_node<1> *)root_node;
  v3 = vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::base_node,1>(node);
  if ( v3 )
    return (vostok::vfs::archive_folder_mount_root_node<1> *)v3;
  v2 = vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(node);
  if ( v2 )
    return v2;
  else
    return 0;
}
