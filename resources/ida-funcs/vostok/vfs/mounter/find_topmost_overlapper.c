vostok::vfs::base_node<1> *__userpurge vostok::vfs::mounter::find_topmost_overlapper@<eax>(
        const vostok::fs_new::virtual_path_string *path@<eax>,
        vostok::vfs::mounter *this,
        __int16 hash,
        vostok::vfs::base_node<1> *node)
{
  vostok::vfs::base_node<1> *v4; // ecx
  vostok::vfs::base_node<1> *v5; // edi
  bool v6; // bl
  vostok::vfs::overlapped_node_iterator *v7; // ecx
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> v9; // [esp+10h] [ebp-44h] BYREF
  vostok::vfs::overlapped_node_initializer second; // [esp+30h] [ebp-24h] BYREF
  const char *v11; // [esp+40h] [ebp-14h] BYREF
  vostok::vfs::base_node<1> *v12; // [esp+44h] [ebp-10h]
  vostok::vfs::lock_type_enum lock_type; // [esp+48h] [ebp-Ch]
  vostok::threading::reader_writer_lock *hashset_lock; // [esp+4Ch] [ebp-8h]

  vostok::vfs::vfs_hashset::equal_range(
    &this->m_file_system->hashset,
    hash,
    &v9,
    path->m_string.m_begin,
    lock_type_write);
  v4 = v9.first.node;
  v11 = v9.first.path;
  lock_type = v9.first.lock_type;
  hashset_lock = v9.first.hashset_lock;
  second = v9.second;
  v5 = 0;
  v12 = v9.first.node;
  v6 = v9.second.node != 0;
  while ( (v4 != 0) != v6 )
  {
    if ( (v4->m_flags & 1) != 0 )
    {
      if ( !v5 )
        v5 = v4;
    }
    else
    {
      v5 = 0;
    }
    if ( v4 == node )
      break;
    vostok::vfs::overlapped_node_iterator::operator++((vostok::vfs::overlapped_node_iterator *)v4, (int)&v11);
    v4 = v12;
  }
  vostok::vfs::overlapped_node_iterator::clear((vostok::vfs::overlapped_node_iterator *)v4, &second);
  vostok::vfs::overlapped_node_iterator::clear(v7, &v11);
  return v5;
}
