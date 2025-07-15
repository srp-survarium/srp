unsigned int __thiscall vostok::vfs::get_file_size<1>(vostok::vfs::base_node<1> *node)
{
  unsigned __int16 m_flags; // ax
  vostok::vfs::archive_file_node<1> *v3; // eax

  m_flags = node->m_flags;
  if ( (m_flags & 0x2000) == 0x2000 )
    return vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(node)->uncompressed_size;
  if ( (m_flags & 4) != 0 )
  {
    if ( (m_flags & 0x1000) == 0x1000 )
      return *((_DWORD *)node - 2);
    if ( (m_flags & 0x40) != 0 )
    {
      if ( (m_flags & 0x10) != 0 )
        return vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>(node)->uncompressed_size;
      v3 = (vostok::vfs::archive_file_node<1> *)vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(node);
    }
    else
    {
      if ( (m_flags & 0x10) != 0 )
        return vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(node)->uncompressed_size;
      v3 = vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>(node);
    }
  }
  else
  {
    v3 = (vostok::vfs::archive_file_node<1> *)vostok::vfs::cast_physical_file<1>(node);
  }
  return v3->size_in_db;
}
