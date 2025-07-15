void __thiscall vostok::vfs::vfs_locked_iterator::clear(vostok::vfs::vfs_locked_iterator *this)
{
  vostok::vfs::vfs_locked_iterator::unlock_and_decref_if_needed(this);
  this->m_node = 0;
  this->m_link_target = 0;
}
