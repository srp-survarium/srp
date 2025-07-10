void __cdecl vostok::vfs::change_subfat_ref_for_node(
        int change,
        vostok::vfs::base_node<1> *node,
        unsigned int *in_out_mount_operation_id)
{
  vostok::vfs::vfs_mount *sub_fat; // [esp+4h] [ebp-124h]
  unsigned int mount_operation_id; // [esp+8h] [ebp-120h]
  vostok::vfs::mount_root_node_base<1> *mount_root; // [esp+Ch] [ebp-11Ch]
  vostok::fs_new::virtual_path_string virtual_path; // [esp+10h] [ebp-118h] BYREF

  sub_fat = vostok::vfs::mount_of_node<1>(node);
  if ( sub_fat )
  {
    mount_root = sub_fat->m_mount_root;
    if ( node == vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_root_node_base,1>(mount_root) )
    {
      vostok::fs_new::path_string_impl::path_string_impl(
        &virtual_path,
        47,
        (const vostok::platform_pointer_selector<char,1>::helper *)&mount_root->virtual_path);
      mount_operation_id = mount_root->mount_operation_id;
      if ( mount_operation_id > *in_out_mount_operation_id )
      {
        if ( change < 0 )
          return;
        *in_out_mount_operation_id = mount_operation_id;
      }
      vostok::vfs::vfs_mount::change_reference_count_change_may_destroy_this(sub_fat, change);
    }
  }
}
