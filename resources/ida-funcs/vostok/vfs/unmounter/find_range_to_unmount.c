void __userpurge vostok::vfs::unmounter::find_range_to_unmount<vostok::vfs::is_exact_node>(
        vostok::vfs::unmounter *this@<ecx>,
        vostok::fs_new::virtual_path_string *path@<eax>,
        vostok::vfs::base_node<1> **first_to_unmount@<edi>,
        __int16 hash,
        const vostok::vfs::is_exact_node *predicate,
        vostok::vfs::base_node<1> **last_to_unmount,
        vostok::vfs::base_node<1> **next_to_last)
{
  vostok::vfs::lock_type_enum lock_type; // ecx
  vostok::vfs::lock_type_enum v9; // edx
  const char *v10; // eax
  const char *v11; // ecx
  vostok::vfs::base_node<1> *node; // ecx
  vostok::vfs::base_node<1> *v13; // eax
  vostok::vfs::overlapped_node_iterator *v14; // ecx
  vostok::vfs::overlapped_node_iterator *v15; // ecx
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> v16; // [esp+8h] [ebp-40h] BYREF
  _DWORD v17[4]; // [esp+28h] [ebp-20h] BYREF
  const char *v18; // [esp+38h] [ebp-10h] BYREF
  vostok::vfs::base_node<1> *v19; // [esp+3Ch] [ebp-Ch]
  vostok::vfs::lock_type_enum v20; // [esp+40h] [ebp-8h]
  vostok::threading::reader_writer_lock *hashset_lock; // [esp+44h] [ebp-4h]
  bool v22; // [esp+5Fh] [ebp+17h]

  vostok::vfs::vfs_hashset::equal_range(this->m_hashset, hash, &v16, path->m_string.m_begin, lock_type_write);
  lock_type = v16.first.lock_type;
  v9 = v16.second.lock_type;
  v10 = v16.first.path;
  *first_to_unmount = 0;
  *next_to_last = 0;
  v20 = lock_type;
  v17[2] = v9;
  hashset_lock = v16.first.hashset_lock;
  v11 = v16.second.path;
  v17[3] = v16.second.hashset_lock;
  *last_to_unmount = 0;
  v17[0] = v11;
  node = v16.second.node;
  v18 = v10;
  v13 = v16.first.node;
  v19 = v16.first.node;
  v17[1] = v16.second.node;
  v22 = v16.second.node != 0;
  while ( 1 )
  {
    LOBYTE(node) = v13 != 0;
    if ( (v13 != 0) == v22 )
      break;
    HIWORD(v14) = HIWORD(predicate);
    if ( v13 == predicate->helper_node )
    {
      if ( !*first_to_unmount )
        *first_to_unmount = v13;
      node = (vostok::vfs::base_node<1> *)last_to_unmount;
      *last_to_unmount = v13;
      break;
    }
    LOWORD(v14) = v13->m_flags & 1;
    *next_to_last = v13;
    if ( !(_WORD)v14 || *first_to_unmount )
    {
      if ( (_WORD)v14 != 1 )
        *first_to_unmount = 0;
    }
    else
    {
      *first_to_unmount = v13;
    }
    vostok::vfs::overlapped_node_iterator::operator++(v14, (int)&v18);
    v13 = v19;
  }
  vostok::vfs::overlapped_node_iterator::clear((vostok::vfs::overlapped_node_iterator *)node, v17);
  vostok::vfs::overlapped_node_iterator::clear(v15, &v18);
}
