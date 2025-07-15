BOOL __thiscall vostok::vfs::vfs_iterator::operator==(
        vostok::vfs::vfs_iterator *this,
        const vostok::vfs::vfs_iterator *it)
{
  return this->m_node == it->m_node;
}


BOOL __thiscall vostok::vfs::vfs_iterator::operator!=(
        vostok::vfs::vfs_iterator *this,
        const vostok::vfs::vfs_iterator *it)
{
  return !vostok::vfs::vfs_iterator::operator==(this, it);
}


bool __thiscall vostok::vfs::vfs_iterator::operator bool(vostok::vfs::vfs_iterator *this)
{
  return this->m_node != 0;
}


vostok::vfs::vfs_iterator *__thiscall vostok::vfs::vfs_iterator::operator++(
        vostok::vfs::vfs_iterator *this,
        vostok::vfs::vfs_iterator *result)
{
  while ( this->m_node && (this->m_node->m_flags & 0x800) == 0x800 )
    this->m_node = this->m_node->m_next.pointer;
  this->m_node = this->m_node->m_next.pointer;
  if ( this->m_node )
    this->m_link_target = vostok::vfs::find_referenced_link_node(this->m_node);
  else
    this->m_link_target = 0;
  vostok::vfs::vfs_iterator::vfs_iterator(result, this);
  return result;
}
