void __usercall vostok::vfs::change_subfat_ref_for_overlapped(
        vostok::vfs::base_node<1> *topmost_node@<eax>,
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> change,
        unsigned int *in_out_mount_operation_id)
{
  while ( topmost_node )
  {
    vostok::vfs::change_subfat_ref_for_node(change, topmost_node, in_out_mount_operation_id);
    topmost_node = topmost_node->m_next_overlapped.pointer;
  }
}
