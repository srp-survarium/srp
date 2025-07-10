vostok::vfs::archive_compressed_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_compressed_file<1>(node);
  else
    return 0;
}
