vostok::vfs::base_node<1> *__usercall vostok::vfs::find_node_of_mount@<eax>(
        vostok::vfs::vfs_hashset *hashset@<ecx>,
        const vostok::fs_new::virtual_path_string *virtual_path@<eax>,
        __int16 virtual_path_hash,
        const unsigned int mount_id)
{
  vostok::vfs::base_node<1> *node; // edi
  vostok::threading::reader_writer_lock *v5; // ecx
  bool v6; // bl
  vostok::vfs::overlapped_node_iterator *v7; // ecx
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> v9; // [esp+10h] [ebp-40h] BYREF
  vostok::vfs::overlapped_node_initializer second; // [esp+30h] [ebp-20h] BYREF
  const char *path; // [esp+40h] [ebp-10h] BYREF
  vostok::vfs::base_node<1> *v12; // [esp+44h] [ebp-Ch]
  vostok::vfs::lock_type_enum lock_type; // [esp+48h] [ebp-8h]
  vostok::threading::reader_writer_lock *hashset_lock; // [esp+4Ch] [ebp-4h]

  vostok::vfs::vfs_hashset::equal_range(hashset, virtual_path_hash, &v9, virtual_path->m_string.m_begin, lock_type_read);
  node = v9.first.node;
  path = v9.first.path;
  lock_type = v9.first.lock_type;
  hashset_lock = v9.first.hashset_lock;
  second = v9.second;
  v5 = v9.second.hashset_lock;
  v12 = v9.first.node;
  v6 = v9.second.node != 0;
  while ( (node != 0) != v6 )
  {
    if ( vostok::vfs::mount_id_of_node<1>(node) == mount_id )
      goto LABEL_6;
    vostok::vfs::overlapped_node_iterator::operator++((vostok::vfs::overlapped_node_iterator *)v5, (int)&path);
    node = v12;
  }
  node = 0;
LABEL_6:
  vostok::vfs::overlapped_node_iterator::clear((vostok::vfs::overlapped_node_iterator *)v5, &second);
  vostok::vfs::overlapped_node_iterator::clear(v7, &path);
  return node;
}
