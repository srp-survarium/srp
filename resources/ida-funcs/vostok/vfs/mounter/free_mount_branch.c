void __userpurge vostok::vfs::mounter::free_mount_branch(
        vostok::buffer_vector<vostok::vfs::mount_helper_node<1> *> *helper_nodes@<edi>,
        vostok::vfs::mounter *this)
{
  vostok::vfs::mount_helper_node<1> **m_begin; // eax
  unsigned int i; // ebx
  void **v4; // esi

  m_begin = helper_nodes->m_begin;
  for ( i = 0; i < helper_nodes->m_end - helper_nodes->m_begin; ++i )
  {
    v4 = (void **)&m_begin[i];
    if ( *v4 )
    {
      this->m_args.allocator->call_free(
        this->m_args.allocator,
        *v4,
        "vostok::vfs::mounter::free_mount_branch",
        ".\\mount_helper_branch.cpp",
        545u);
      *v4 = 0;
    }
    m_begin = helper_nodes->m_begin;
  }
}
