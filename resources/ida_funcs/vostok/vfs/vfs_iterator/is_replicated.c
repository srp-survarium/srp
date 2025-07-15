BOOL __thiscall vostok::vfs::vfs_iterator::is_replicated(vostok::vfs::vfs_iterator *this)
{
  return (this->m_node->m_flags & 0x20) == 32;
}
