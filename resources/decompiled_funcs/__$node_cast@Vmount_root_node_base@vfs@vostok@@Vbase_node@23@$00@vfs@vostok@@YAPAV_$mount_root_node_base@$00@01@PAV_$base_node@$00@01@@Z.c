vostok::vfs::mount_root_node_base<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_mount_root_node_base<1>(node);
  else
    return 0;
}
