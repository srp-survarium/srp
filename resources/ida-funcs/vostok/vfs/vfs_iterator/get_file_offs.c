int __thiscall vostok::vfs::vfs_iterator::get_file_offs(vostok::vfs::vfs_iterator *this)
{
  if ( this->m_link_target )
    return vostok::vfs::get_file_offs<1>(this->m_link_target);
  else
    return vostok::vfs::get_file_offs<1>(this->m_node);
}
