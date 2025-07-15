vostok::vfs::archive_compressed_file_node<1> *__thiscall vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  unsigned __int16 m_flags; // ax

  if ( node
    && (m_flags = node->m_flags, (m_flags & 1) == 0)
    && (m_flags & 4) != 0
    && (m_flags & 0x10) != 0
    && (m_flags & 0x40) == 0 )
  {
    return (vostok::vfs::archive_compressed_file_node<1> *)((char *)node - 32);
  }
  else
  {
    return 0;
  }
}


vostok::vfs::archive_file_node<1> *__usercall vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>@<eax>(
        vostok::vfs::base_node<1> *node@<eax>)
{
  unsigned __int16 m_flags; // cx

  if ( !node )
    return 0;
  m_flags = node->m_flags;
  if ( (m_flags & 1) != 0 || (m_flags & 4) == 0 || (m_flags & 0x50) != 0 )
    return 0;
  else
    return (vostok::vfs::archive_file_node<1> *)((char *)node - 24);
}


vostok::vfs::base_node<1> *__usercall vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>@<eax>(
        vostok::vfs::base_node<1> *node@<eax>)
{
  unsigned __int16 m_flags; // cx

  if ( node && (m_flags = node->m_flags, (m_flags & 1) != 0) && (m_flags & 8) != 0 && (m_flags & 4) != 0 )
    return node - 17;
  else
    return 0;
}


vostok::vfs::archive_inline_file_node<1> *__thiscall vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  unsigned __int16 m_flags; // ax

  if ( node
    && (m_flags = node->m_flags, (m_flags & 1) == 0)
    && (m_flags & 4) != 0
    && (m_flags & 0x10) == 0
    && (m_flags & 0x40) != 0 )
  {
    return (vostok::vfs::archive_inline_file_node<1> *)((char *)node - 40);
  }
  else
  {
    return 0;
  }
}


vostok::vfs::mount_helper_node<1> *__thiscall vostok::vfs::node_cast<vostok::vfs::mount_helper_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  unsigned __int16 m_flags; // ax

  if ( node && (m_flags = node->m_flags, (m_flags & 1) != 0) && (m_flags & 0x400) == 0x400 )
    return (vostok::vfs::mount_helper_node<1> *)((char *)node - 24);
  else
    return 0;
}


vostok::vfs::physical_folder_mount_root_node<1> *__usercall vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>@<eax>(
        vostok::vfs::base_node<1> *node@<esi>)
{
  vostok::vfs::physical_folder_mount_root_node<1> *result; // eax

  if ( !node )
    return 0;
  result = vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(node);
  if ( !result )
  {
    result = (vostok::vfs::physical_folder_mount_root_node<1> *)vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::base_node,1>(node);
    if ( !result )
      return (vostok::vfs::physical_folder_mount_root_node<1> *)vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(node);
  }
  return result;
}


vostok::vfs::base_node<1> *__usercall vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::base_node,1>@<eax>(
        vostok::vfs::base_node<1> *node@<eax>)
{
  unsigned __int16 m_flags; // cx

  if ( node && (m_flags = node->m_flags, (m_flags & 1) == 0) && (m_flags & 8) != 0 && (m_flags & 2) != 0 )
    return node - 2;
  else
    return 0;
}


vostok::vfs::physical_file_node<1> *__thiscall vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_physical_file<1>(node);
  else
    return 0;
}


vostok::vfs::physical_folder_mount_root_node<1> *__usercall vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>@<eax>(
        vostok::vfs::base_node<1> *node@<eax>)
{
  unsigned __int16 m_flags; // cx

  if ( node && (m_flags = node->m_flags, (m_flags & 1) != 0) && (m_flags & 8) != 0 && (m_flags & 2) != 0 )
    return (vostok::vfs::physical_folder_mount_root_node<1> *)((char *)node - 136);
  else
    return 0;
}


vostok::vfs::physical_folder_node<1> *__usercall vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>@<eax>(
        vostok::vfs::base_node<1> *node@<eax>)
{
  unsigned __int16 m_flags; // cx

  if ( !node )
    return 0;
  m_flags = node->m_flags;
  if ( (m_flags & 1) == 0 || (m_flags & 2) == 0 )
    return 0;
  if ( (m_flags & 8) != 0 )
    return &vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(node)->folder;
  return (vostok::vfs::physical_folder_node<1> *)((char *)node - 32);
}


vostok::vfs::universal_file_node<1> *__usercall vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>@<eax>(
        vostok::vfs::base_node<1> *node@<eax>)
{
  if ( node && (node->m_flags & 0x2000) == 0x2000 )
    return (vostok::vfs::universal_file_node<1> *)((char *)node - 24);
  else
    return 0;
}
