char __cdecl vostok::vfs::need_physical_mount(
        bool *is_out_of_memory,
        vostok::vfs::base_node<1> *node,
        vostok::vfs::find_enum find_flags,
        vostok::vfs::traverse_enum traverse_type,
        vostok::memory::base_allocator *allocator)
{
  *is_out_of_memory = 0;
  if ( (node->m_flags & 0x300) != 0 )
    return 0;
  if ( vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(node) )
    return vostok::vfs::need_physical_folder_mount(node, find_flags, traverse_type);
  if ( !vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(node)
    || traverse_type == traverse_child )
  {
    return 0;
  }
  if ( traverse_type == traverse_node && (find_flags & 2) != 0 )
    return 0;
  return vostok::vfs::need_automatic_archive_mount(is_out_of_memory, node, allocator);
}
