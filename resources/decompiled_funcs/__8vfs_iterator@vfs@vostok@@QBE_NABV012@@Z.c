BOOL __thiscall vostok::vfs::vfs_iterator::operator==(
        vostok::vfs::vfs_iterator *this,
        const vostok::vfs::vfs_iterator *it)
{
  return this->m_node == it->m_node;
}
