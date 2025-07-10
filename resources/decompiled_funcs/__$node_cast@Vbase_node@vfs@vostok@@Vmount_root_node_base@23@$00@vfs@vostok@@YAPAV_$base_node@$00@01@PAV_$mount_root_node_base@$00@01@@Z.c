vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_root_node_base,1>(
        vostok::vfs::mount_root_node_base<1> *node)
{
  if ( node )
    return node->node.pointer;
  else
    return 0;
}
