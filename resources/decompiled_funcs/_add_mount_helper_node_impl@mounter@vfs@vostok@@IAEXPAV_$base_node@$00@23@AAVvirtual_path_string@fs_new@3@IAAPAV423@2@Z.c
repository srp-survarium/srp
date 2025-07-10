void __thiscall vostok::vfs::mounter::add_mount_helper_node_impl(
        vostok::vfs::mounter *this,
        vostok::vfs::base_node<1> *node_to_add,
        vostok::fs_new::virtual_path_string *path,
        unsigned int path_hash,
        vostok::vfs::base_node<1> **in_out_current_helper,
        vostok::vfs::base_node<1> **in_out_branch_lock)
{
  survarium::game_camera *v6; // ecx
  vostok::vfs::mount_root_node_base<1> *v7; // eax
  int v8; // eax
  BOOL v9; // ecx
  vostok::vfs::base_folder_node<1> *v10; // eax
  vostok::vfs::base_folder_node<1> *v11; // eax
  const char *v12; // eax
  vostok::vfs::base_node<1> *new_branch_lock; // [esp+Ch] [ebp-8h] BYREF
  bool adding_at_root; // [esp+13h] [ebp-1h]

  if ( *in_out_current_helper && vostok::fs_new::path_string_impl::length(path) )
  {
    survarium::weapon_user_dead_state::finalize(v6);
    v7 = (vostok::vfs::mount_root_node_base<1> *)vostok::vfs::node_cast<vostok::vfs::mount_helper_node,vostok::vfs::base_node,1>(*in_out_current_helper);
    node_to_add->m_mount_root.max_storage = 0;
    node_to_add->m_mount_root.pointer = v7;
  }
  v8 = vostok::fs_new::path_string_impl::length(path);
  adding_at_root = v8 == 0;
  v9 = v8 == 0;
  if ( v8 )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v9);
    v10 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(*in_out_current_helper);
    vostok::vfs::mounter::merge_node_with_tree(
      this,
      (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)path,
      path_hash,
      node_to_add,
      v10);
    v11 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(*in_out_current_helper);
    vostok::vfs::mounter::remove_marked_to_unlink_from_parent(v11);
    new_branch_lock = 0;
    v12 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)path);
    vostok::vfs::vfs_hashset::find_no_branch_lock(
      &this->m_file_system->hashset,
      &new_branch_lock,
      v12,
      path_hash,
      lock_type_write,
      lock_operation_lock);
    vostok::vfs::upgrade_node(*in_out_branch_lock, lock_type_write, (vostok::vfs::lock_type_enum)4);
    *in_out_branch_lock = new_branch_lock;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v9);
    vostok::vfs::mounter::merge_root_node(this, path_hash, node_to_add, in_out_branch_lock);
  }
  *in_out_current_helper = node_to_add;
}
