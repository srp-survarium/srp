void __userpurge vostok::vfs::mounter::add_mount_helper_node(
        vostok::vfs::mount_helper_node<1> *in_out_helper_node@<edi>,
        vostok::vfs::mounter *this,
        vostok::fs_new::virtual_path_string *path,
        unsigned int path_hash,
        vostok::vfs::base_node<1> **in_out_current_helper,
        vostok::vfs::base_node<1> **in_out_branch_lock)
{
  unsigned int m_mount_id; // eax
  vostok::memory::base_allocator *allocator; // ecx
  vostok::vfs::base_node<1> *p_base; // eax
  vostok::vfs::base_node<1> *v10; // eax
  unsigned int v11; // [esp+8h] [ebp-4h]
  char *v12; // [esp+14h] [ebp+8h]

  v12 = vostok::fs_new::file_name_from_path<vostok::fs_new::virtual_path_string>(path);
  v11 = strlen(v12);
  m_mount_id = this->m_mount_id;
  if ( in_out_helper_node )
  {
    allocator = this->m_args.allocator;
    in_out_helper_node->m_allocator = allocator;
    in_out_helper_node->mount_id = m_mount_id;
    vostok::vfs::base_folder_node<1>::base_folder_node<1>(
      (vostok::vfs::base_folder_node<1> *)allocator,
      (int)&in_out_helper_node->folder);
    p_base = &in_out_helper_node->folder.base;
  }
  else
  {
    p_base = 0;
  }
  p_base->m_flags = 1025;
  vostok::strings::copy(p_base->m_name, v11 + 1, v12);
  if ( in_out_helper_node )
    v10 = &in_out_helper_node->folder.base;
  else
    v10 = 0;
  vostok::vfs::mounter::add_mount_helper_node_impl(
    v10,
    this,
    path,
    path_hash,
    in_out_current_helper,
    in_out_branch_lock);
}
