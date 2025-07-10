const vostok::vfs::universal_file_node<1> *__cdecl vostok::vfs::cast_universal_file_node<1>(
        vostok::vfs::base_node<1> *node)
{
  return vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(node);
}
