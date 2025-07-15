vostok::vfs::base_folder_node<1> *__thiscall vostok::vfs::mounter::find_parent_to_link(
        vostok::vfs::mounter *this,
        vostok::vfs::base_node<1> **in_out_overlapper,
        vostok::vfs::base_node<1> *candidate_for_link,
        vostok::vfs::base_node<1> *parent,
        vostok::vfs::base_folder_node<1> *path,
        char **a6)
{
  vostok::vfs::base_node<1> *v7; // esi
  vostok::vfs::overlapped_node_iterator *v8; // ecx
  unsigned int v9; // edi
  vostok::vfs::overlapped_node_iterator *v10; // ecx
  vostok::vfs::base_node<1> *v11; // edi
  vostok::vfs::base_node<1> *v12; // eax
  vostok::vfs::base_folder_node<1> *v13; // edi
  vostok::vfs::overlapped_node_iterator *v14; // ecx
  char *v15; // [esp-4h] [ebp-170h]
  vostok::vfs::vfs_hashset *v16; // [esp-4h] [ebp-170h]
  vostok::fs_new::virtual_path_string v17; // [esp+10h] [ebp-15Ch] BYREF
  int v18; // [esp+128h] [ebp-44h] BYREF
  vostok::vfs::base_node<1> *v19; // [esp+12Ch] [ebp-40h]
  int v20; // [esp+130h] [ebp-3Ch]
  int v21; // [esp+134h] [ebp-38h]
  int v22; // [esp+138h] [ebp-34h]
  int v23; // [esp+13Ch] [ebp-30h]
  int v24; // [esp+140h] [ebp-2Ch]
  vostok::vfs::overlapped_node_iterator *v25; // [esp+144h] [ebp-28h]
  _DWORD v26[4]; // [esp+148h] [ebp-24h] BYREF
  int v27; // [esp+158h] [ebp-14h] BYREF
  vostok::vfs::base_node<1> *v28; // [esp+15Ch] [ebp-10h]
  int v29; // [esp+160h] [ebp-Ch]
  int v30; // [esp+164h] [ebp-8h]
  char v31; // [esp+177h] [ebp+Bh]
  vostok::vfs::base_node<1> *node; // [esp+17Ch] [ebp+10h]
  bool v33; // [esp+187h] [ebp+1Bh]

  if ( parent && vostok::vfs::cast_folder<1>(parent) == path )
    return path;
  v17.m_string.m_begin = v17.m_string.m_buffer;
  v17.m_string.m_end = v17.m_string.m_buffer;
  v17.m_string.m_max_end = &v17.m_separator;
  v15 = *a6;
  v17.m_string.m_buffer[0] = 0;
  v17.m_separator = 47;
  vostok::fs_new::get_path_without_last_item<vostok::fs_new::virtual_path_string>(&v17, v15);
  vostok::vfs::vfs_hashset::equal_range(
    v16,
    (vostok::vfs::vfs_hashset *)&in_out_overlapper[329]->m_next,
    (char *)&v18,
    v17.m_string.m_begin,
    lock_type_write);
  v7 = v19;
  v27 = v18;
  v29 = v20;
  v30 = v21;
  v26[0] = v22;
  v26[2] = v24;
  v8 = v25;
  v28 = v19;
  v26[1] = v23;
  v26[3] = v25;
  v33 = v23 != 0;
  while ( (v7 != 0) != v33 && parent && v7 != parent )
  {
    vostok::vfs::overlapped_node_iterator::operator++(v8, (int)&v27);
    v7 = v28;
  }
  if ( candidate_for_link->m_mount_root.pointer )
  {
    v9 = vostok::vfs::mount_id_of_node<1>((vostok::vfs::base_node<1> *)candidate_for_link->m_mount_root.pointer);
    while ( (v7 != 0) != v33 )
    {
      if ( vostok::vfs::mount_id_of_node<1>(v7) == v9 )
      {
        vostok::vfs::overlapped_node_iterator::operator++(v10, (int)&v27);
        v7 = v28;
        break;
      }
      vostok::vfs::overlapped_node_iterator::operator++(v10, (int)&v27);
      v7 = v28;
    }
  }
  v31 = 0;
  node = v7;
  v11 = 0;
  while ( (v7 != 0) != v33 )
  {
    if ( v11 && !v11->m_next_overlapped.pointer )
    {
      candidate_for_link->m_mount_root.pointer = 0;
      node = v7;
    }
    if ( v31 )
    {
      node = v7;
      v31 = 0;
    }
    v12 = path ? &path->base : 0;
    if ( v7 == v12 )
      break;
    if ( (v7->m_flags & 1) == 0 )
    {
      v31 = 1;
      candidate_for_link->m_mount_root.pointer = 0;
    }
    v11 = v7;
    vostok::vfs::overlapped_node_iterator::operator++(v8, (int)&v27);
    v7 = v28;
  }
  if ( node )
    v13 = vostok::vfs::cast_folder<1>(node);
  else
    v13 = 0;
  vostok::vfs::overlapped_node_iterator::clear(v8, v26);
  vostok::vfs::overlapped_node_iterator::clear(v14, &v27);
  return v13;
}
