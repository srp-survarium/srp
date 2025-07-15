void __userpurge vostok::vfs::unmounter::hot_unmount_node(
        vostok::vfs::unmounter *this@<edi>,
        vostok::vfs::base_node<1> *node@<eax>,
        vostok::vfs::vfs_hashset *a3@<ecx>,
        __int16 hash)
{
  vostok::vfs::physical_folder_mount_root_node<1> *m_root_node_to_unmount; // ebx
  vostok::vfs::physical_folder_node<1> *v6; // eax
  bool v7; // zf

  vostok::vfs::vfs_hashset::erase(a3, (int)this->m_hashset, hash, node);
  m_root_node_to_unmount = (vostok::vfs::physical_folder_mount_root_node<1> *)this->m_root_node_to_unmount;
  if ( vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(node) == m_root_node_to_unmount )
  {
    m_root_node_to_unmount->erased = 1;
  }
  else
  {
    v6 = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(node);
    if ( v6 )
      v7 = (v6->m_folder_flags.m_flags & 4) == 0;
    else
      v7 = (vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(node)->m_file_flags.m_flags
          & 8) == 0;
    if ( v7 )
      vostok::vfs::mount_root_node_base<1>::prepend_erased_node(this->m_root_node_to_unmount, node);
  }
}
