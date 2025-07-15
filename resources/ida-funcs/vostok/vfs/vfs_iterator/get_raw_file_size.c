int __thiscall vostok::vfs::vfs_iterator::get_raw_file_size(vostok::vfs::vfs_iterator *this)
{
  vostok::vfs::base_node<1> *m_link_target; // eax

  m_link_target = this->m_link_target;
  if ( !m_link_target )
    m_link_target = this->m_node;
  if ( (m_link_target->m_flags & 0x55) == 4 )
    return *((_DWORD *)m_link_target - 6);
  else
    return vostok::vfs::get_raw_file_size_impl<1>(m_link_target);
}
