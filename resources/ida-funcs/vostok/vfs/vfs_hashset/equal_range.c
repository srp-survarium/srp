stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> *__userpurge vostok::vfs::vfs_hashset::equal_range@<eax>(
        vostok::vfs::vfs_hashset *this@<ecx>,
        __int16 hash@<ax>,
        stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> *path,
        char *lock_type,
        vostok::vfs::lock_type_enum a5)
{
  unsigned int *p_readers_count; // ebx
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> *result; // eax
  vostok::threading::reader_writer_lock *v9; // [esp-4h] [ebp-40h]
  vostok::vfs::base_node<1> *v10; // [esp+10h] [ebp-2Ch]
  vostok::threading::reader_writer_lock *v11; // [esp+18h] [ebp-24h]
  vostok::vfs::base_node<1> *node; // [esp+24h] [ebp-18h]

  p_readers_count = (unsigned int *)&this->m_hashlocks[hash & 0x1F].m_readers_writers_counter.readers_count;
  vostok::threading::reader_writer_lock::lock(
    this->m_hashlocks,
    p_readers_count,
    (vostok::threading::lock_type_enum)((a5 != lock_type_read) + 1));
  v11 = 0;
  if ( this->m_hashset.m_buffer[hash & 0x7FFF] )
    node = this->m_hashset.m_buffer[hash & 0x7FFF];
  else
    node = 0;
  v10 = vostok::vfs::vfs_hashset::skip_nodes_with_wrong_path(node, lock_type);
  if ( v10 )
    v11 = (vostok::threading::reader_writer_lock *)p_readers_count;
  else
    vostok::threading::reader_writer_lock::unlock(
      v9,
      (volatile signed __int64 *)p_readers_count,
      (vostok::threading::lock_type_enum)((a5 != lock_type_read) + 1));
  result = path;
  path->first.path = lock_type;
  path->first.node = v10;
  path->first.lock_type = a5;
  path->first.hashset_lock = v11;
  path->second.path = 0;
  path->second.node = 0;
  path->second.lock_type = lock_type_uninitialized;
  path->second.hashset_lock = 0;
  return result;
}


stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> *__thiscall vostok::vfs::vfs_hashset::equal_range(
        vostok::vfs::vfs_hashset *this,
        vostok::vfs::vfs_hashset *result,
        char *path,
        char *lock_type,
        vostok::vfs::lock_type_enum a5)
{
  __int16 v5; // ax
  vostok::buffer_string v7; // [esp+4h] [ebp-114h] BYREF
  char v8; // [esp+114h] [ebp-4h]

  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)this, &v7, lock_type);
  v8 = 47;
  v5 = vostok::fs_new::path_crc32(v7.m_begin, v7.m_end - v7.m_begin, 0);
  vostok::vfs::vfs_hashset::equal_range(
    result,
    v5,
    (stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> *)path,
    lock_type,
    a5);
  return (stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> *)path;
}
