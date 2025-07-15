void __thiscall vostok::vfs::archive_mounter::recursive_merge(
        vostok::vfs::archive_mounter *this,
        vostok::fs_new::virtual_path_string *path,
        vostok::vfs::base_node<1> *hash,
        vostok::vfs::base_folder_node<1> *node,
        vostok::vfs::base_node<1> *parent)
{
  vostok::vfs::base_folder_node<1> *v5; // edi
  vostok::vfs::mounter *v6; // ecx
  vostok::vfs::base_folder_node<1> *v7; // eax
  vostok::fs_new::virtual_path_string *v8; // ebx
  vostok::fs_new::path_string_impl *v9; // ecx
  vostok::vfs::base_node<1> *v10; // eax
  char *v11; // eax
  vostok::vfs::base_node<1> *v12; // edi
  int v13; // [esp+14h] [ebp-Ch]
  vostok::vfs::base_node<1> *first_child; // [esp+18h] [ebp-8h]

  v5 = node;
  first_child = vostok::vfs::base_node<1>::get_first_child((vostok::vfs::base_node<1> *)this, (int)node);
  if ( ((int)v5->base.m_parent.pointer & 1) != 0 )
  {
    v7 = vostok::vfs::cast_folder<1>((vostok::vfs::base_node<1> *)v5);
    v7->m_first_child.pointer = 0;
    HIDWORD(v7->m_first_child.max_storage) = 0;
  }
  v8 = path;
  if ( parent )
    vostok::vfs::mounter::merge_node_with_tree(v6, this, path, __PAIR64__((unsigned int)v5, (unsigned int)hash), parent);
  else
    vostok::vfs::mounter::merge_root_node(
      (vostok::vfs::base_node<1> *)v5,
      &this->m_args.root_write_lock,
      this,
      (unsigned int)hash);
  v13 = v8->m_string.m_end - v8->m_string.m_begin;
  if ( ((int)v5->base.m_parent.pointer & 0x300) != 0 )
    node = 0;
  else
    node = vostok::vfs::cast_folder<1>((vostok::vfs::base_node<1> *)v5);
  while ( 1 )
  {
    v12 = first_child;
    if ( !first_child )
      break;
    first_child = first_child->m_next.pointer;
    path = (vostok::fs_new::virtual_path_string *)v12->m_name;
    vostok::fs_new::path_string_impl::append_path<char const *>(v9, (int)v8, (char **)&path);
    v10 = (vostok::vfs::base_node<1> *)vostok::fs_new::crc32(v12->m_name, strlen(v12->m_name), (unsigned int)hash);
    vostok::vfs::archive_mounter::recursive_merge(this, v8, v10, (vostok::vfs::base_folder_node<1> *)v12, node);
    v9 = (vostok::fs_new::path_string_impl *)v13;
    v11 = &v8->m_string.m_begin[v13];
    v8->m_string.m_end = v11;
    *v11 = 0;
  }
  if ( parent )
    vostok::vfs::mounter::remove_marked_to_unlink_from_parent((vostok::vfs::base_folder_node<1> *)parent);
}
