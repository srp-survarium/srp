unsigned int __thiscall vostok::vfs::vfs_iterator::get_compressed_file_size(vostok::vfs::vfs_iterator *this)
{
  if ( this->m_link_target )
    return vostok::vfs::get_compressed_file_size<1>(this->m_link_target);
  else
    return vostok::vfs::get_compressed_file_size<1>(this->m_node);
}
