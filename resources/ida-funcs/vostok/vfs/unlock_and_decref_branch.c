void __usercall vostok::vfs::unlock_and_decref_branch(
        vostok::vfs::base_node<1> *node@<eax>,
        vostok::vfs::lock_type_enum unlock_type,
        unsigned int mount_operation_id)
{
  vostok::vfs::base_folder_node<1> *pointer; // esi

  while ( node )
  {
    vostok::vfs::change_subfat_ref_for_overlapped(
      node,
      (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)-1,
      &mount_operation_id);
    pointer = node->m_parent.pointer;
    vostok::vfs::unlock_node(node, unlock_type);
    if ( !pointer )
      break;
    node = &pointer->base;
    unlock_type = vostok::vfs::soften_lock(unlock_type);
  }
}
