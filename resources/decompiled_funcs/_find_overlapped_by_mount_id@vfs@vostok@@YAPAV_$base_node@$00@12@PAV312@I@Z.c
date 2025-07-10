vostok::vfs::base_node<1> *__cdecl vostok::vfs::find_overlapped_by_mount_id(
        vostok::vfs::base_node<1> *node,
        unsigned int mount_id)
{
  while ( node )
  {
    if ( vostok::vfs::mount_id_of_node<1>(node) == mount_id )
      return node;
    node = node->m_next_overlapped.pointer;
  }
  return 0;
}
