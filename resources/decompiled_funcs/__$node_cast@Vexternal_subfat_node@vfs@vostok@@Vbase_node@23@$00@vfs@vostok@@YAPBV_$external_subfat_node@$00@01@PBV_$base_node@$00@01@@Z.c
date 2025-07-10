const vostok::vfs::external_subfat_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::external_subfat_node,vostok::vfs::base_node,1>(
        const vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_external_node<1>(node);
  else
    return 0;
}
