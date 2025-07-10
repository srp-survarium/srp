vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::hard_link_node,1>(
        vostok::vfs::hard_link_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_node<1>(node);
  else
    return 0;
}
