void __cdecl vostok::vfs::separate_folders_by_file_node(
        char *path,
        __int16 hash,
        vostok::vfs::base_node<1> *last_overlapper,
        unsigned int separator_mount_id)
{
  vostok::vfs::vfs_hashset *v4; // ecx
  vostok::vfs::base_node<1> *node; // ecx
  vostok::vfs::base_node<1> *v6; // edi
  bool v7; // bl
  vostok::vfs::overlapped_node_iterator *v8; // ecx
  vostok::vfs::overlapped_node_iterator *v9; // ecx
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> v10; // [esp+10h] [ebp-40h] BYREF
  vostok::vfs::overlapped_node_initializer second; // [esp+30h] [ebp-20h] BYREF
  const char *v12; // [esp+40h] [ebp-10h] BYREF
  vostok::vfs::overlapped_node_iterator *v13; // [esp+44h] [ebp-Ch]
  vostok::vfs::lock_type_enum lock_type; // [esp+48h] [ebp-8h]
  vostok::threading::reader_writer_lock *hashset_lock; // [esp+4Ch] [ebp-4h]

  vostok::vfs::vfs_hashset::equal_range(v4, hash, &v10, path, lock_type_write);
  node = v10.first.node;
  v12 = v10.first.path;
  lock_type = v10.first.lock_type;
  hashset_lock = v10.first.hashset_lock;
  second = v10.second;
  v6 = 0;
  v13 = (vostok::vfs::overlapped_node_iterator *)v10.first.node;
  v7 = v10.second.node != 0;
  while ( (node != 0) != v7 )
  {
    if ( (node->m_flags & 1) != 0 )
    {
      if ( !v6 )
        v6 = node;
    }
    else
    {
      v6 = 0;
    }
    if ( node == last_overlapper )
      break;
    vostok::vfs::overlapped_node_iterator::operator++((vostok::vfs::overlapped_node_iterator *)node, (int)&v12);
    node = (vostok::vfs::base_node<1> *)v13;
  }
  vostok::vfs::relink_children_of_folder_range(v6, last_overlapper, separator_mount_id);
  vostok::vfs::break_separated_links_of_folder_range(v6, last_overlapper, separator_mount_id);
  vostok::vfs::overlapped_node_iterator::clear(v8, &second);
  vostok::vfs::overlapped_node_iterator::clear(v9, &v12);
}
