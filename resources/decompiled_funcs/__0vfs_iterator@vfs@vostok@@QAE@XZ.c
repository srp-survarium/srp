void __thiscall vostok::vfs::vfs_iterator::vfs_iterator(vostok::vfs::vfs_iterator *this)
{
  this->m_hashset = 0;
  this->m_node = 0;
  this->m_link_target = 0;
  this->m_type = type_unset;
}
