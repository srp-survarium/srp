vostok::vfs::base_node<1> *__cdecl vostok::vfs::find_referenced_link_node(vostok::vfs::base_node<1> *node)
{
  vostok::vfs::soft_link_node<1> *v2; // eax
  const char *v3; // eax
  survarium::game_camera *v4; // ecx
  vostok::vfs::mount_root_node_base<1> *pointer; // [esp+0h] [ebp-14Ch]
  vostok::fs_new::virtual_path_string full_path; // [esp+24h] [ebp-128h] BYREF
  vostok::vfs::mount_root_node_base<1> *mount_root; // [esp+140h] [ebp-Ch]
  vostok::vfs::vfs_hashset *hashset; // [esp+144h] [ebp-8h]
  vostok::vfs::base_node<1> *out_referenced_node; // [esp+148h] [ebp-4h]

  if ( !node || (node->m_flags & 0x300) == 0 )
    return 0;
  if ( (node->m_flags & 0x200) == 0x200 )
    return vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(node)->referenced.pointer;
  if ( (node->m_flags & 8) == 8 )
    pointer = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(node);
  else
    pointer = node->m_mount_root.pointer;
  mount_root = pointer;
  hashset = &pointer->file_system.pointer->hashset;
  vostok::fs_new::virtual_path_string::virtual_path_string(&full_path);
  v2 = (vostok::vfs::soft_link_node<1> *)vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(node);
  vostok::vfs::soft_link_node<1>::absolute_path_to_referenced(v2, &full_path);
  v3 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&full_path);
  out_referenced_node = vostok::vfs::vfs_hashset::find_no_lock(hashset, v3, check_locks_true);
  survarium::weapon_user_dead_state::finalize(v4);
  return out_referenced_node;
}
