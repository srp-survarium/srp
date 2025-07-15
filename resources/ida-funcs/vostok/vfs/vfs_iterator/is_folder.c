BOOL __thiscall vostok::vfs::vfs_iterator::is_folder(vostok::vfs::vfs_iterator *this)
{
  vostok::vfs::base_node<1> *m_link_target; // [esp+4h] [ebp-4h]

  if ( this->m_link_target )
    m_link_target = this->m_link_target;
  else
    m_link_target = this->m_node;
  return (m_link_target->m_flags & 1) == 1;
}
