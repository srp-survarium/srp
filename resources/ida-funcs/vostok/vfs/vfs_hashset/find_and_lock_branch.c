char __userpurge vostok::vfs::vfs_hashset::find_and_lock_branch@<al>(
        vostok::vfs::base_node<1> **out_locked_branch@<edi>,
        vostok::vfs::vfs_hashset *this,
        char *path,
        __int16 hash,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum lock_operation)
{
  char v6; // bl
  vostok::vfs::overlapped_node_iterator *v7; // ecx
  vostok::vfs::base_node<1> *node; // esi
  vostok::tasks *v9; // ecx
  vostok::vfs::overlapped_node_iterator *v10; // ecx
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> patha; // [esp+8h] [ebp-30h] BYREF
  _DWORD v13[4]; // [esp+28h] [ebp-10h] BYREF

  v6 = 0;
  while ( 1 )
  {
    vostok::vfs::vfs_hashset::equal_range(this, hash, &patha, path, lock_type_read);
    node = patha.first.node;
    v13[0] = patha.first.path;
    v13[2] = patha.first.lock_type;
    v13[1] = patha.first.node;
    v13[3] = patha.first.hashset_lock;
    if ( !patha.first.node )
    {
      *out_locked_branch = 0;
      vostok::vfs::overlapped_node_iterator::clear(v7, v13);
      return 1;
    }
    if ( vostok::vfs::lock_branch(patha.first.node, lock_type_write, lock_operation_try_lock) )
      break;
    if ( lock_type == lock_type_read )
      goto LABEL_8;
    vostok::threading::yield(0, v9);
    vostok::vfs::overlapped_node_iterator::clear(v10, v13);
  }
  *out_locked_branch = node;
  v6 = 1;
LABEL_8:
  vostok::vfs::overlapped_node_iterator::clear((vostok::vfs::overlapped_node_iterator *)v9, v13);
  return v6;
}


char __userpurge vostok::vfs::vfs_hashset::find_and_lock_branch@<al>(
        char *path@<eax>,
        vostok::vfs::vfs_hashset *this,
        vostok::vfs::base_node<1> **out_locked_branch,
        vostok::vfs::lock_type_enum lock_type,
        vostok::vfs::lock_operation_enum lock_operation)
{
  __int16 v6; // ax
  vostok::vfs::lock_operation_enum v8; // [esp+0h] [ebp-8h]

  v6 = vostok::fs_new::path_crc32(path, strlen(path), 0);
  return vostok::vfs::vfs_hashset::find_and_lock_branch(out_locked_branch, this, path, v6, lock_type, v8);
}
