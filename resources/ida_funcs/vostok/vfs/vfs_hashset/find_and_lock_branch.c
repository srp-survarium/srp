char __thiscall vostok::vfs::vfs_hashset::find_and_lock_branch(
        vostok::vfs::vfs_hashset *this,
        vostok::vfs::base_node<1> **out_locked_branch,
        const char *path,
        unsigned int hash,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum lock_operation)
{
  survarium::game_camera *v6; // ecx
  _BYTE *v7; // eax
  vostok::vfs::base_node<1> *node; // [esp+Ch] [ebp-34h]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+10h] [ebp-30h] BYREF
  vostok::vfs::overlapped_node_iterator it; // [esp+30h] [ebp-10h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  while ( 1 )
  {
    survarium::weapon_user_dead_state::finalize(v6);
    if ( !*v7 )
      break;
    vostok::vfs::vfs_hashset::equal_range(this, &begin_end, path, hash, lock_type_read);
    vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
    node = it.node;
    if ( !it.node )
    {
      *out_locked_branch = 0;
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      return 1;
    }
    if ( vostok::vfs::lock_branch(it.node, lock_type, lock_operation_try_lock) )
    {
      *out_locked_branch = node;
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      return 1;
    }
    if ( lock_operation == lock_operation_try_lock )
    {
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      return 0;
    }
    vostok::threading::yield(0);
    vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
  }
  return 0;
}


char __thiscall vostok::vfs::vfs_hashset::find_and_lock_branch(
        vostok::vfs::vfs_hashset *this,
        vostok::vfs::base_node<1> **out_locked_branch,
        const char *path,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum lock_operation)
{
  unsigned int hash; // [esp+8h] [ebp-8h]
  unsigned int path_length; // [esp+Ch] [ebp-4h]

  path_length = vostok::strings::length(path);
  hash = vostok::fs_new::path_crc32(path, path_length, 0);
  return vostok::vfs::vfs_hashset::find_and_lock_branch(this, out_locked_branch, path, hash, lock_type, lock_operation);
}
