bool __thiscall vostok::vfs::vfs_iterator::is_archive(vostok::vfs::vfs_iterator *this)
{
  vostok::vfs::base_node<1> *m_link_target; // eax

  m_link_target = this->m_link_target;
  if ( !m_link_target )
    m_link_target = this->m_node;
  return (m_link_target->m_flags & 4) == 4;
}
