const vostok::vfs::hard_link_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(
        const vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_hard_link<1>(node);
  else
    return 0;
}
