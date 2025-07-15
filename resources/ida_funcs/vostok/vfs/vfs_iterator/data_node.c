vostok::vfs::base_node<1> *__thiscall vostok::vfs::vfs_iterator::data_node(vostok::vfs::vfs_iterator *this)
{
  if ( this->m_link_target )
    return this->m_link_target;
  else
    return this->m_node;
}
