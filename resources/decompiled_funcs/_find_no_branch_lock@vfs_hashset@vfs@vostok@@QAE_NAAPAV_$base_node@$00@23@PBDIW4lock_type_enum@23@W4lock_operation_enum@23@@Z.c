char __thiscall vostok::vfs::vfs_hashset::find_no_branch_lock(
        vostok::vfs::vfs_hashset *this,
        vostok::vfs::base_node<1> **out_locked_node,
        const char *path,
        unsigned int hash,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum lock_operation)
{
  _BYTE *v6; // eax
  survarium::game_camera *pointer; // ecx
  vostok::vfs::base_folder_node<1> *ancestor; // [esp+14h] [ebp-38h]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+18h] [ebp-34h] BYREF
  vostok::vfs::overlapped_node_iterator it; // [esp+38h] [ebp-14h] BYREF
  vostok::vfs::base_node<1> *node; // [esp+48h] [ebp-4h]

  node = 0;
  while ( 1 )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    if ( !*v6 )
      break;
    vostok::vfs::vfs_hashset::equal_range(this, &begin_end, path, hash, lock_type_read);
    vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
    node = it.node;
    if ( !it.node )
    {
      *out_locked_node = 0;
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      return 1;
    }
    if ( vostok::vfs::lock_node(node, lock_type, lock_operation_try_lock) )
    {
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      break;
    }
    if ( lock_operation == lock_operation_try_lock )
    {
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      return 0;
    }
    vostok::threading::yield(0);
    vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
  }
  pointer = (survarium::game_camera *)node;
  for ( ancestor = node->m_parent.pointer; ancestor; ancestor = (vostok::vfs::base_folder_node<1> *)pointer )
  {
    survarium::weapon_user_dead_state::finalize(pointer);
    pointer = (survarium::game_camera *)vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(ancestor)->m_parent.pointer;
  }
  *out_locked_node = node;
  return 1;
}
