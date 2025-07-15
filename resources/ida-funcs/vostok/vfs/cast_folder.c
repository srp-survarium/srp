vostok::vfs::base_folder_node<1> *__usercall vostok::vfs::cast_folder<1>@<eax>(vostok::vfs::base_node<1> *node@<eax>)
{
  unsigned __int16 m_flags; // cx
  vostok::vfs::mount_helper_node<1> *v3; // eax
  vostok::vfs::base_node<1> *v4; // eax
  vostok::vfs::physical_folder_mount_root_node<1> *v5; // eax
  vostok::vfs::physical_folder_node<1> *v6; // eax

  m_flags = node->m_flags;
  if ( (m_flags & 1) == 0 )
    return 0;
  if ( (m_flags & 0x400) == 0x400 )
  {
    v3 = vostok::vfs::node_cast<vostok::vfs::mount_helper_node,vostok::vfs::base_node,1>(node);
    if ( v3 )
      return &v3->folder;
    return 0;
  }
  if ( (m_flags & 8) != 0 )
  {
    if ( (m_flags & 4) != 0 )
    {
      v4 = vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(node);
      if ( !v4 )
        return 0;
      return (vostok::vfs::base_folder_node<1> *)&v4->m_name[885];
    }
    else
    {
      v5 = vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(node);
      if ( !v5 )
        return 0;
      return &v5->folder.folder;
    }
  }
  else if ( (m_flags & 2) != 0 )
  {
    v6 = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(node);
    if ( !v6 )
      return 0;
    return &v6->folder;
  }
  else
  {
    return (vostok::vfs::base_folder_node<1> *)((char *)node - 16);
  }
}
