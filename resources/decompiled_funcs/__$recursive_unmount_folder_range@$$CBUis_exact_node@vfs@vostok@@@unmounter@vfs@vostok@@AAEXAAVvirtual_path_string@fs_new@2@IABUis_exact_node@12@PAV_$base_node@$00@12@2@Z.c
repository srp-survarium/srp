void __thiscall vostok::vfs::unmounter::recursive_unmount_folder_range<vostok::vfs::is_exact_node const>(
        vostok::vfs::unmounter *this,
        vostok::fs_new::virtual_path_string *path,
        unsigned int hash,
        vostok::vfs::is_exact_node *predicate,
        vostok::vfs::base_node<1> *first_to_unmount,
        vostok::vfs::base_node<1> *last_to_unmount)
{
  const char *v6; // eax
  BOOL v7; // ecx
  vostok::vfs::base_folder_node<1> *v8; // eax
  survarium::game_camera *v9; // ecx
  vostok::vfs::base_folder_node<1> *v10; // eax
  _BYTE *v11; // eax
  vostok::vfs::base_node<1> *next_node; // [esp+314h] [ebp-48h]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+318h] [ebp-44h] BYREF
  vostok::vfs::base_node<1> *current_to_unmount; // [esp+338h] [ebp-24h]
  vostok::vfs::overlapped_node_iterator it_end; // [esp+33Ch] [ebp-20h] BYREF
  vostok::vfs::overlapped_node_iterator it; // [esp+34Ch] [ebp-10h] BYREF

  v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)path);
  vostok::vfs::vfs_hashset::equal_range(this->m_hashset, &begin_end, v6, hash, lock_type_write);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it_end, &begin_end.second);
  while ( it.node != first_to_unmount )
    vostok::vfs::overlapped_node_iterator::operator++(&it);
  current_to_unmount = first_to_unmount;
  do
  {
    v7 = it_end.node != 0;
    if ( (it.node != 0) != v7 )
      vostok::vfs::overlapped_node_iterator::operator++(&it);
    next_node = it.node;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v7);
    if ( current_to_unmount == last_to_unmount )
    {
      v8 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(current_to_unmount);
      vostok::vfs::unmounter::recursive_unmount_folder<vostok::vfs::is_exact_node>(this, path, hash, predicate, v8);
    }
    else
    {
      v10 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(current_to_unmount);
      vostok::vfs::unmounter::recursive_traverse_folder<vostok::vfs::is_exact_node>(this, path, hash, predicate, v10);
    }
    if ( current_to_unmount == last_to_unmount )
      break;
    current_to_unmount = next_node;
    survarium::weapon_user_dead_state::finalize(v9);
  }
  while ( *v11 );
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
}
