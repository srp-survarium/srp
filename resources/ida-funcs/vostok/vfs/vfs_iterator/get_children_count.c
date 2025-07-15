int __thiscall vostok::vfs::vfs_iterator::get_children_count(vostok::vfs::vfs_iterator *this)
{
  vostok::vfs::base_node<1> *m_link_target; // eax
  vostok::vfs::base_node<1> *pointer; // eax
  int i; // ecx

  m_link_target = this->m_link_target;
  if ( !m_link_target )
  {
    m_link_target = this->m_node;
    if ( !m_link_target )
      return 0;
  }
  if ( (m_link_target->m_flags & 1) == 0 )
    return 0;
  pointer = vostok::vfs::cast_folder<1>(m_link_target)->m_first_child.pointer;
  for ( i = 0; pointer; pointer = pointer->m_next.pointer )
  {
    if ( (pointer->m_flags & 0x800) != 0x800 )
      ++i;
  }
  return i;
}
