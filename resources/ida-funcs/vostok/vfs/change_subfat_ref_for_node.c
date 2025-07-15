void __cdecl vostok::vfs::change_subfat_ref_for_node(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> change,
        vostok::vfs::base_node<1> *node,
        unsigned int *in_out_mount_operation_id)
{
  vostok::vfs::vfs_mount *v3; // eax
  vostok::fixed_string<260> *v4; // ecx
  vostok::vfs::vfs_mount *v5; // ebx
  vostok::vfs::mount_root_node_base<1> *m_mount_root; // edi
  vostok::vfs::base_node<1> *v7; // eax
  vostok::vfs::vfs_mount *v8; // ecx
  unsigned int mount_operation_id; // edi
  vostok::buffer_string v10[22]; // [esp+Ch] [ebp-118h] BYREF
  char v11; // [esp+11Ch] [ebp-8h]

  v3 = vostok::vfs::mount_of_node<1>(node);
  v5 = v3;
  if ( v3 )
  {
    m_mount_root = v3->m_mount_root;
    v7 = m_mount_root ? m_mount_root->node.pointer : 0;
    if ( node == v7 )
    {
      vostok::fixed_string<260>::fixed_string<260>(v4, v10, (char *)m_mount_root->virtual_path.pointer);
      v11 = 47;
      mount_operation_id = m_mount_root->mount_operation_id;
      if ( mount_operation_id > *in_out_mount_operation_id )
      {
        if ( (int)change.m_object < 0 )
          return;
        *in_out_mount_operation_id = mount_operation_id;
      }
      vostok::vfs::vfs_mount::change_reference_count_change_may_destroy_this(v8, v5, change);
    }
  }
}
