void __cdecl vostok::vfs::unlock_and_decref_branch(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::lock_type_enum unlock_type,
        unsigned int mount_operation_id)
{
  vostok::vfs::base_node<1> *v3; // eax
  vostok::vfs::lock_type_enum v4; // [esp-8h] [ebp-10h]
  unsigned int v5; // [esp-4h] [ebp-Ch]
  vostok::vfs::base_folder_node<1> *parent; // [esp+4h] [ebp-4h]

  if ( node )
  {
    vostok::vfs::change_subfat_ref_for_overlapped(-1, node, &mount_operation_id);
    parent = node->m_parent.pointer;
    vostok::vfs::unlock_node(node, unlock_type);
    if ( parent )
    {
      v5 = mount_operation_id;
      v4 = vostok::vfs::soften_lock(unlock_type);
      v3 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(parent);
      vostok::vfs::unlock_and_decref_branch(v3, v4, v5);
    }
  }
}
