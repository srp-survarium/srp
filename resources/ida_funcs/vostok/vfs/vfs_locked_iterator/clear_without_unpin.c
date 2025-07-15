void __thiscall vostok::vfs::vfs_locked_iterator::clear_without_unpin(vostok::vfs::vfs_locked_iterator *this)
{
  this->m_node = 0;
  this->m_link_target = 0;
}
