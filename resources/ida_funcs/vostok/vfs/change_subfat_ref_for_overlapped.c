void __cdecl vostok::vfs::change_subfat_ref_for_overlapped(
        int change,
        vostok::vfs::base_node<1> *topmost_node,
        unsigned int *in_out_mount_operation_id)
{
  while ( topmost_node )
  {
    vostok::vfs::change_subfat_ref_for_node(change, topmost_node, in_out_mount_operation_id);
    topmost_node = topmost_node->m_next_overlapped.pointer;
  }
}
