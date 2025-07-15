vostok::vfs::physical_file_node<1> *__thiscall vostok::vfs::cast_physical_file<1>(vostok::vfs::base_node<1> *node)
{
  unsigned __int16 m_flags; // ax

  m_flags = node->m_flags;
  if ( (m_flags & 1) != 0 || (m_flags & 2) == 0 )
    return 0;
  else
    return (vostok::vfs::physical_file_node<1> *)((char *)node - 8);
}
