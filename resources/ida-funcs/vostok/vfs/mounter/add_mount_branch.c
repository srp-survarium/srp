void __thiscall vostok::vfs::mounter::add_mount_branch(
        vostok::vfs::mounter *this,
        vostok::vfs::mounter *helper_nodes,
        vostok::vfs::base_node<1> **out_branch,
        vostok::vfs::base_node<1> **in_out_lock,
        vostok::vfs::base_node<1> **out_node_hash,
        unsigned int *a6)
{
  int v7; // eax
  vostok::fs_new::virtual_path_string *v8; // ecx
  vostok::fs_new::path_part_iterator *v9; // [esp-4h] [ebp-280h]
  vostok::fs_new::virtual_path_string v10; // [esp+10h] [ebp-26Ch] BYREF
  vostok::fs_new::virtual_path_string v11; // [esp+128h] [ebp-154h] BYREF
  vostok::fs_new::path_part_iterator v12; // [esp+244h] [ebp-38h] BYREF
  vostok::fs_new::path_part_iterator v13; // [esp+25Ch] [ebp-20h] BYREF
  int v14; // [esp+274h] [ebp-8h]
  unsigned int v15; // [esp+284h] [ebp+8h]

  v10.m_string.m_begin = v10.m_string.m_buffer;
  v10.m_string.m_end = v10.m_string.m_buffer;
  v10.m_string.m_max_end = &v10.m_separator;
  v10.m_string.m_buffer[0] = 0;
  v10.m_separator = 47;
  vostok::fs_new::virtual_path_string::virtual_path_string((vostok::fs_new::virtual_path_string *)this, (int)&v11);
  v15 = vostok::fs_new::path_crc32(*(const char **)v7, *(_DWORD *)(v7 + 4) - *(_DWORD *)v7, 0);
  vostok::fs_new::path_string_impl::begin_part(&helper_nodes->m_args.virtual_path, (int)&v13);
  vostok::fs_new::path_part_iterator::path_part_iterator(&v12, 0, include_empty_string_in_iteration_false, 0);
  if ( vostok::fs_new::path_part_iterator::operator!=(&v13, &v12) )
  {
    v14 = 0;
    do
    {
      v11.m_string.m_begin = v11.m_string.m_buffer;
      v11.m_string.m_end = v11.m_string.m_buffer;
      v11.m_string.m_max_end = &v11.m_separator;
      v11.m_string.m_buffer[0] = 0;
      v11.m_separator = 47;
      vostok::fs_new::path_part_iterator::assign_to_string<vostok::fs_new::virtual_path_string>(&v13, &v11);
      vostok::fs_new::virtual_path_string::append_path(v8, (int)&v10, &v11);
      v15 = vostok::fs_new::path_crc32(v11.m_string.m_begin, v11.m_string.m_end - v11.m_string.m_begin, v15);
      vostok::fs_new::path_part_iterator::operator++(v9, (int)&v13);
      if ( vostok::fs_new::path_part_iterator::operator!=(&v13, &v12) )
        vostok::vfs::mounter::add_mount_helper_node(
          *(vostok::vfs::mount_helper_node<1> **)((char *)&(*out_branch)->m_mount_helper_parent.pointer + v14),
          helper_nodes,
          &v10,
          v15,
          in_out_lock,
          out_node_hash);
      v14 += 4;
    }
    while ( vostok::fs_new::path_part_iterator::operator!=(&v13, &v12) );
  }
  if ( a6 )
    *a6 = v15;
}
