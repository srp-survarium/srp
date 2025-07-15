vostok::vfs::base_node<1> *__thiscall vostok::vfs::vfs_hashset::find_no_lock(
        vostok::vfs::vfs_hashset *this,
        const char *path,
        vostok::vfs::vfs_hashset::check_locks_bool check_locks)
{
  const char *v3; // eax
  vostok::vfs::base_folder_node<1> *v5; // ecx
  unsigned int v6; // [esp-8h] [ebp-180h]
  vostok::vfs::base_folder_node<1> *pointer; // [esp+0h] [ebp-178h]
  vostok::vfs::base_node<1> *v9; // [esp+14h] [ebp-164h]
  vostok::fs_new::path_string_impl v10; // [esp+20h] [ebp-158h] BYREF
  bool has_locks; // [esp+137h] [ebp-41h]
  vostok::vfs::base_folder_node<1> *it_check_node; // [esp+138h] [ebp-40h]
  bool branch_locked; // [esp+13Fh] [ebp-39h]
  vostok::vfs::base_node<1> *node; // [esp+140h] [ebp-38h]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+144h] [ebp-34h] BYREF
  unsigned int hash; // [esp+164h] [ebp-14h]
  vostok::vfs::overlapped_node_iterator it; // [esp+168h] [ebp-10h] BYREF

  vostok::fs_new::path_string_impl::path_string_impl(&v10, 47, &path);
  v6 = vostok::fs_new::path_string_impl::length(&v10);
  v3 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10);
  hash = vostok::fs_new::path_crc32(v3, v6, 0);
  vostok::vfs::vfs_hashset::equal_range(this, &begin_end, path, hash, lock_type_read);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
  node = it.node;
  if ( it.node )
  {
    if ( check_locks == check_locks_true )
    {
      if ( (node->m_flags & 1) == 1 )
        pointer = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
      else
        pointer = node->m_parent.pointer;
      v5 = pointer;
      it_check_node = pointer;
      branch_locked = 0;
      while ( it_check_node )
      {
        has_locks = vostok::vfs::base_folder_node<1>::has_some_lock(it_check_node);
        if ( branch_locked )
        {
          v5 = (vostok::vfs::base_folder_node<1> *)has_locks;
          if ( !has_locks )
          {
            branch_locked = 0;
            break;
          }
        }
        branch_locked = has_locks;
        v5 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(it_check_node)->m_parent.pointer;
        it_check_node = v5;
      }
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
    }
    v9 = node;
    vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
    return v9;
  }
  else
  {
    vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
    return 0;
  }
}
