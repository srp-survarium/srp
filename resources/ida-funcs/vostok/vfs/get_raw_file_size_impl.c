unsigned int __cdecl vostok::vfs::get_raw_file_size_impl<1>(vostok::vfs::base_node<1> *node)
{
  unsigned __int16 m_flags; // ax
  vostok::vfs::base_node<1> *referenced_link_node; // eax
  vostok::vfs::archive_file_node<1> *v4; // eax

  m_flags = node->m_flags;
  if ( (m_flags & 0x300) != 0 )
  {
    referenced_link_node = vostok::vfs::find_referenced_link_node(node);
    if ( (referenced_link_node->m_flags & 0x55) == 4 )
      return *((_DWORD *)referenced_link_node - 6);
    else
      return vostok::vfs::get_raw_file_size_impl<1>(referenced_link_node);
  }
  else if ( (m_flags & 0x2000) == 0x2000 )
  {
    return vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(node)->size;
  }
  else
  {
    if ( (m_flags & 4) != 0 )
    {
      if ( (m_flags & 0x40) != 0 )
      {
        if ( (m_flags & 0x10) != 0 )
          v4 = (vostok::vfs::archive_file_node<1> *)vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>(node);
        else
          v4 = (vostok::vfs::archive_file_node<1> *)vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(node);
      }
      else if ( (m_flags & 0x10) != 0 )
      {
        v4 = (vostok::vfs::archive_file_node<1> *)vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(node);
      }
      else
      {
        v4 = vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>(node);
      }
    }
    else
    {
      v4 = (vostok::vfs::archive_file_node<1> *)vostok::vfs::cast_physical_file<1>(node);
    }
    return v4->size_in_db;
  }
}
