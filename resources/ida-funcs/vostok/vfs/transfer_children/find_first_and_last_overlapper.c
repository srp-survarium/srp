void __userpurge vostok::vfs::transfer_children::find_first_and_last_overlapper(
        vostok::vfs::transfer_children *this@<ecx>,
        const vostok::fs_new::virtual_path_string *path@<eax>,
        vostok::vfs::base_node<1> **out_first_overlapper,
        vostok::vfs::base_node<1> **out_last_overlapper,
        __int16 hash,
        vostok::vfs::base_node<1> *const child)
{
  vostok::vfs::base_node<1> *node; // ebx
  vostok::vfs::base_node<1> *v8; // edi
  vostok::vfs::base_node<1> *m_dest_start; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  vostok::vfs::overlapped_node_iterator *v12; // ecx
  vostok::vfs::overlapped_node_iterator *v13; // ecx
  vostok::vfs::overlapped_node_iterator *v14; // ecx
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> v15; // [esp+Ch] [ebp-4Ch] BYREF
  _DWORD v16[4]; // [esp+2Ch] [ebp-2Ch] BYREF
  const char *v17; // [esp+3Ch] [ebp-1Ch] BYREF
  vostok::vfs::base_node<1> *v18; // [esp+40h] [ebp-18h]
  vostok::vfs::lock_type_enum lock_type; // [esp+44h] [ebp-14h]
  vostok::threading::reader_writer_lock *hashset_lock; // [esp+48h] [ebp-10h]
  unsigned int v21; // [esp+4Ch] [ebp-Ch]
  vostok::vfs::base_node<1> *v22; // [esp+50h] [ebp-8h]
  vostok::vfs::base_node<1> *v23; // [esp+54h] [ebp-4h]

  vostok::vfs::vfs_hashset::equal_range(this->m_hashset, hash, &v15, path->m_string.m_begin, lock_type_read);
  node = v15.first.node;
  v8 = v15.second.node;
  v17 = v15.first.path;
  lock_type = v15.first.lock_type;
  hashset_lock = v15.first.hashset_lock;
  v16[0] = v15.second.path;
  v16[2] = v15.second.lock_type;
  v16[3] = v15.second.hashset_lock;
  m_dest_start = this->m_dest_start;
  v18 = v15.first.node;
  v16[1] = v15.second.node;
  v10 = vostok::vfs::mount_id_of_node<1>(m_dest_start);
  v23 = 0;
  v22 = 0;
  v21 = v10;
  while ( (node != 0) != (v8 != 0) && node != child )
  {
    v11 = vostok::vfs::mount_id_of_node<1>(node);
    if ( v11 <= v21 )
    {
      if ( !v23 )
        v23 = node;
      if ( (node->m_flags & 1) == 0 )
        v23 = 0;
      v22 = node;
    }
    vostok::vfs::overlapped_node_iterator::operator++(v12, (int)&v17);
    node = v18;
  }
  *out_first_overlapper = v23;
  v13 = (vostok::vfs::overlapped_node_iterator *)v22;
  *out_last_overlapper = v22;
  vostok::vfs::overlapped_node_iterator::clear(v13, v16);
  vostok::vfs::overlapped_node_iterator::clear(v14, &v17);
}
