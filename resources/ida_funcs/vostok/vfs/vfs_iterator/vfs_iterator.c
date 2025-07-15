void __thiscall vostok::vfs::vfs_iterator::vfs_iterator(
        vostok::vfs::vfs_iterator *this,
        const vostok::vfs::vfs_iterator *it)
{
  *this = *it;
}


void __thiscall vostok::vfs::vfs_iterator::vfs_iterator(
        vostok::vfs::vfs_iterator *this,
        vostok::vfs::base_node<1> *node,
        vostok::vfs::base_node<1> *link_target,
        vostok::vfs::vfs_hashset *hashset,
        vostok::vfs::vfs_iterator::type_enum type)
{
  this->m_hashset = hashset;
  this->m_node = node;
  this->m_link_target = link_target;
  this->m_type = type;
  if ( node )
  {
    if ( (node->m_flags & 0x800) == 0x800 )
    {
      this->m_node = 0;
      this->m_link_target = 0;
    }
  }
}


void __thiscall vostok::vfs::vfs_iterator::vfs_iterator(vostok::vfs::vfs_iterator *this)
{
  this->m_hashset = 0;
  this->m_node = 0;
  this->m_link_target = 0;
  this->m_type = type_unset;
}
