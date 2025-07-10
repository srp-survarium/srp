void __thiscall vostok::vfs::unmounter::unmount_helper_branch(
        vostok::vfs::unmounter *this,
        vostok::vfs::mount_helper_node<1> *parent_to_unmount_helper,
        vostok::vfs::base_node<1> *child_to_unmount,
        vostok::vfs::base_node<1> *overlap_of_unmount,
        unsigned int child_to_unmount_hash)
{
  char *v5; // eax
  survarium::game_camera *v6; // ecx
  const char *v7; // eax
  signed int v8; // [esp-8h] [ebp-150h]
  vostok::vfs::mount_helper_node<1> *next_parent; // [esp+20h] [ebp-128h]
  vostok::vfs::base_node<1> *parent_to_unmount; // [esp+24h] [ebp-124h]
  unsigned int hash; // [esp+28h] [ebp-120h]
  bool root_visited; // [esp+2Fh] [ebp-119h]
  vostok::fs_new::virtual_path_string branch_path; // [esp+30h] [ebp-118h] BYREF

  vostok::fs_new::virtual_path_string::virtual_path_string(&branch_path);
  v5 = (char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_args);
  vostok::fs_new::get_path_without_last_item<vostok::fs_new::virtual_path_string>(&branch_path, v5);
  hash = child_to_unmount_hash;
  root_visited = 0;
  while ( (vostok::fs_new::path_string_impl::length(&branch_path) || !root_visited) && parent_to_unmount_helper )
  {
    survarium::weapon_user_dead_state::finalize(v6);
    parent_to_unmount = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_helper_node,1>(parent_to_unmount_helper);
    next_parent = (vostok::vfs::mount_helper_node<1> *)parent_to_unmount->m_mount_root.pointer;
    v8 = vostok::fs_new::path_string_impl::length(&branch_path);
    v7 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&branch_path);
    hash = vostok::fs_new::path_crc32(v7, v8, 0);
    if ( child_to_unmount )
      vostok::vfs::unmounter::unmount_helper(
        this,
        &branch_path,
        hash,
        parent_to_unmount,
        child_to_unmount,
        &overlap_of_unmount);
    child_to_unmount = parent_to_unmount;
    if ( !vostok::fs_new::path_string_impl::length(&branch_path) && !root_visited )
      root_visited = 1;
    parent_to_unmount_helper = next_parent;
    vostok::fs_new::cut_last_item_from_path<vostok::fs_new::virtual_path_string>(&branch_path);
  }
  if ( child_to_unmount )
  {
    if ( overlap_of_unmount )
      overlap_of_unmount->m_next_overlapped.pointer = child_to_unmount->m_next_overlapped.pointer;
    vostok::vfs::free_node(
      this->m_file_system,
      child_to_unmount,
      &this->m_args->root_write_lock,
      hash,
      this->m_args->allocator);
  }
  else
  {
    survarium::weapon_user_dead_state::finalize(v6);
  }
}
