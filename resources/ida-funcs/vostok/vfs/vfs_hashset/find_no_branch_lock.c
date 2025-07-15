char __thiscall vostok::vfs::vfs_hashset::find_no_branch_lock(
        vostok::vfs::vfs_hashset *this,
        vostok::vfs::base_node<1> **out_locked_node,
        char *path,
        char *hash,
        __int16 lock_type,
        vostok::vfs::lock_type_enum lock_operation,
        int a7)
{
  char v7; // bl
  vostok::vfs::overlapped_node_iterator *v8; // ecx
  vostok::vfs::base_node<1> *node; // edi
  bool v10; // al
  vostok::vfs::overlapped_node_iterator *v11; // ecx
  vostok::vfs::base_folder_node<1> *i; // eax
  vostok::tasks *v14; // [esp-4h] [ebp-44h]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> patha; // [esp+10h] [ebp-30h] BYREF
  _DWORD v16[4]; // [esp+30h] [ebp-10h] BYREF

  v7 = 1;
  while ( 1 )
  {
    vostok::vfs::vfs_hashset::equal_range(
      (vostok::vfs::vfs_hashset *)out_locked_node,
      lock_type,
      &patha,
      hash,
      lock_type_read);
    node = patha.first.node;
    v16[0] = patha.first.path;
    v16[2] = patha.first.lock_type;
    v16[1] = patha.first.node;
    v16[3] = patha.first.hashset_lock;
    if ( !patha.first.node )
    {
      *(_DWORD *)path = 0;
LABEL_7:
      vostok::vfs::overlapped_node_iterator::clear(v8, v16);
      return v7;
    }
    v10 = vostok::vfs::lock_node(patha.first.node, lock_operation, lock_operation_try_lock);
    v8 = (vostok::vfs::overlapped_node_iterator *)v14;
    if ( v10 )
      break;
    if ( a7 == 1 )
    {
      v7 = 0;
      goto LABEL_7;
    }
    vostok::threading::yield(0, v14);
    vostok::vfs::overlapped_node_iterator::clear(v11, v16);
  }
  vostok::vfs::overlapped_node_iterator::clear((vostok::vfs::overlapped_node_iterator *)v14, v16);
  for ( i = node->m_parent.pointer; i; i = i->base.m_parent.pointer )
    ;
  *(_DWORD *)path = node;
  return v7;
}


char __userpurge vostok::vfs::vfs_hashset::find_no_branch_lock@<al>(
        vostok::vfs::vfs_hashset *this@<ecx>,
        vostok::vfs::base_node<1> **out_locked_node,
        char *path,
        char *lock_type,
        vostok::vfs::lock_operation_enum lock_operation)
{
  __int16 v5; // ax
  vostok::vfs::vfs_hashset *v7; // [esp-4h] [ebp-120h]
  vostok::buffer_string v8; // [esp+8h] [ebp-114h] BYREF
  char v9; // [esp+118h] [ebp-4h]

  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)this, &v8, lock_type);
  v9 = 47;
  v5 = vostok::fs_new::path_crc32(v8.m_begin, v8.m_end - v8.m_begin, 0);
  return vostok::vfs::vfs_hashset::find_no_branch_lock(v7, out_locked_node, path, lock_type, v5, lock_type_read, 1);
}
