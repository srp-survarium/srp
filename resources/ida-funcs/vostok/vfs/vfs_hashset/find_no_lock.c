vostok::vfs::base_node<1> *__thiscall vostok::vfs::vfs_hashset::find_no_lock(
        vostok::vfs::vfs_hashset *this,
        vostok::vfs::vfs_hashset *path,
        char *check_locks,
        int a4)
{
  __int16 v4; // ax
  vostok::vfs::overlapped_node_iterator *whole; // ecx
  vostok::vfs::base_node<1> *node; // esi
  vostok::vfs::base_node<1> *v7; // edi
  vostok::vfs::base_folder_node<1> *pointer; // eax
  char v10; // dl
  _DWORD v11[4]; // [esp+Ch] [ebp-144h] BYREF
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> patha; // [esp+1Ch] [ebp-134h] BYREF
  vostok::buffer_string v13; // [esp+3Ch] [ebp-114h] BYREF
  char v14; // [esp+14Ch] [ebp-4h]

  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)this, &v13, check_locks);
  v14 = 47;
  v4 = vostok::fs_new::path_crc32(v13.m_begin, v13.m_end - v13.m_begin, 0);
  vostok::vfs::vfs_hashset::equal_range(path, v4, &patha, check_locks, lock_type_read);
  node = patha.first.node;
  v11[0] = patha.first.path;
  v11[2] = patha.first.lock_type;
  v11[1] = patha.first.node;
  v11[3] = patha.first.hashset_lock;
  if ( patha.first.node )
  {
    if ( a4 == 1 )
    {
      pointer = (patha.first.node->m_flags & 1) != 0
              ? vostok::vfs::cast_folder<1>(patha.first.node)
              : patha.first.node->m_parent.pointer;
      v10 = 0;
      if ( pointer )
      {
        do
        {
          whole = (vostok::vfs::overlapped_node_iterator *)pointer->m_readers_writers_counters.m_counters.whole;
          LOBYTE(whole) = whole != 0;
          if ( v10 && !(_BYTE)whole )
            break;
          v10 = (char)whole;
          pointer = pointer->base.m_parent.pointer;
        }
        while ( pointer );
        node = patha.first.node;
      }
    }
    v7 = node;
  }
  else
  {
    v7 = 0;
  }
  vostok::vfs::overlapped_node_iterator::clear(whole, v11);
  return v7;
}
