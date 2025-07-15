void __userpurge vostok::vfs::mounter::add_mount_helper_node_impl(
        vostok::vfs::base_node<1> *node_to_add@<eax>,
        vostok::vfs::mounter *this,
        vostok::fs_new::virtual_path_string *path,
        unsigned int path_hash,
        vostok::vfs::base_node<1> **in_out_current_helper,
        vostok::vfs::base_node<1> **in_out_branch_lock)
{
  vostok::fs_new::virtual_path_string *v6; // ecx
  vostok::vfs::base_node<1> **v7; // ebx
  vostok::vfs::base_node<1> *v8; // esi
  vostok::vfs::mount_root_node_base<1> *v10; // eax
  vostok::vfs::base_node<1> *v11; // eax
  vostok::vfs::mounter *v12; // esi
  vostok::vfs::base_node<1> *v13; // eax
  vostok::vfs::base_node<1> **v14; // esi
  vostok::vfs::vfs_hashset *v15; // [esp-4h] [ebp-10h]

  v6 = path;
  v7 = in_out_current_helper;
  v8 = *in_out_current_helper;
  if ( *in_out_current_helper && path->m_string.m_end != path->m_string.m_begin )
  {
    v10 = (vostok::vfs::mount_root_node_base<1> *)vostok::vfs::node_cast<vostok::vfs::mount_helper_node,vostok::vfs::base_node,1>(*in_out_current_helper);
    node_to_add->m_mount_root.pointer = 0;
    HIDWORD(node_to_add->m_mount_helper_parent.max_storage) = 0;
    v6 = path;
    node_to_add->m_mount_root.pointer = v10;
  }
  if ( v6->m_string.m_end == v6->m_string.m_begin )
  {
    vostok::vfs::mounter::merge_root_node(node_to_add, in_out_branch_lock, this, path_hash);
  }
  else
  {
    if ( v8 )
    {
      v11 = (vostok::vfs::base_node<1> *)vostok::vfs::cast_folder<1>(v8);
      v6 = path;
    }
    else
    {
      v11 = 0;
    }
    v12 = this;
    vostok::vfs::mounter::merge_node_with_tree(
      (vostok::vfs::mounter *)v6,
      (vostok::vfs::base_node<1> **)this,
      v6,
      __PAIR64__((unsigned int)node_to_add, path_hash),
      v11);
    v13 = *v7;
    if ( *v7 )
      v13 = (vostok::vfs::base_node<1> *)vostok::vfs::cast_folder<1>(v13);
    vostok::vfs::mounter::remove_marked_to_unlink_from_parent((vostok::vfs::base_folder_node<1> *)v13);
    this = 0;
    vostok::vfs::vfs_hashset::find_no_branch_lock(
      v15,
      (vostok::vfs::base_node<1> **)&v12->m_file_system->hashset,
      (char *)&this,
      path->m_string.m_begin,
      path_hash,
      lock_type_write,
      0);
    v14 = in_out_branch_lock;
    vostok::vfs::upgrade_node(*in_out_branch_lock, lock_type_write, (vostok::vfs::lock_operation_enum)4);
    *v14 = (vostok::vfs::base_node<1> *)this;
  }
  *v7 = node_to_add;
}
