vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(
        vostok::vfs::base_folder_node<1> *node)
{
  if ( node )
    return &node->base;
  else
    return 0;
}
