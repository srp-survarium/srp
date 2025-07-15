unsigned int __thiscall vostok::vfs::vfs_iterator::get_children_count(vostok::vfs::vfs_iterator *this)
{
  vostok::vfs::base_node<1> *m_link_target; // [esp+0h] [ebp-Ch]

  if ( this->m_link_target )
    m_link_target = this->m_link_target;
  else
    m_link_target = this->m_node;
  if ( m_link_target )
    return vostok::vfs::calculate_count_of_children<1>(m_link_target, 0);
  else
    return 0;
}
