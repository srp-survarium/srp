char __usercall vostok::vfs::query_notification_operation::try_write_lock@<al>(
        vostok::vfs::query_notification_operation *this@<ecx>,
        int a2@<edi>)
{
  char **v2; // eax
  vostok::vfs::vfs_mount *v3; // ecx
  vostok::vfs::mount_result *v4; // ecx
  vostok::vfs::vfs_mount *v5; // ecx
  const vostok::vfs::mount_result *v6; // eax
  boost::function1<void,vostok::vfs::mount_result> *v7; // ecx
  vostok::vfs::mount_result v9; // [esp-Ch] [ebp-134h] BYREF
  int v10; // [esp-4h] [ebp-12Ch]
  vostok::vfs::lock_operation_enum v11; // [esp+0h] [ebp-128h]
  vostok::fs_new::virtual_path_string in_out_path; // [esp+8h] [ebp-120h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v13; // [esp+120h] [ebp-8h] BYREF

  in_out_path.m_string.m_begin = in_out_path.m_string.m_buffer;
  in_out_path.m_string.m_end = in_out_path.m_string.m_buffer;
  in_out_path.m_string.m_max_end = &in_out_path.m_separator;
  v2 = *(char ***)(a2 + 44);
  in_out_path.m_string.m_buffer[0] = 0;
  in_out_path.m_separator = 47;
  vostok::fs_new::get_path_without_last_item<vostok::fs_new::virtual_path_string>(&in_out_path, *v2);
  *(_DWORD *)(a2 + 40) = 0;
  v3 = (vostok::vfs::vfs_mount *)v10;
  while ( 1 )
  {
    if ( (in_out_path.m_string.m_begin != in_out_path.m_string.m_end
        ? (unsigned int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        : 0) == 0
      || !vostok::vfs::vfs_hashset::find_and_lock_branch(
            in_out_path.m_string.m_begin,
            (vostok::vfs::vfs_hashset *)(*(_DWORD *)a2 + 24),
            (vostok::vfs::base_node<1> **)(a2 + 40),
            *(vostok::vfs::lock_type_enum *)(a2 + 20),
            v11)
      && *(_DWORD *)(a2 + 20) == 1 )
    {
      v10 = 4;
      v9.result = (vostok::vfs::result_enum)v3;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v9.result,
        0);
      vostok::vfs::mount_result::mount_result(
        v4,
        &v13,
        (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)v9.result,
        (vostok::vfs::vfs_mount *)v10);
      v10 = (int)v5;
      v9.result = (vostok::vfs::result_enum)v5;
      vostok::vfs::mount_result::mount_result((vostok::vfs::mount_result *)&v9.result, v6);
      v9.mount.m_object = *(vostok::vfs::vfs_mount **)(a2 + 16);
      boost::function1<void,vostok::vfs::mount_result>::operator()(
        v7,
        v9,
        (boost::function1<void,vostok::vfs::mount_result> *)v10);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v13);
      return 0;
    }
    if ( *(_DWORD *)(a2 + 40) )
      break;
    vostok::fs_new::get_path_without_last_item_inplace<vostok::fs_new::virtual_path_string>(&in_out_path);
  }
  return 1;
}
