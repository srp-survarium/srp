int __thiscall vostok::vfs::vfs_iterator::get_raw_file_size(vostok::vfs::vfs_iterator *this)
{
  vostok::vfs::base_node<1> *node; // [esp+8h] [ebp-24h]

  if ( this->m_link_target )
    node = this->m_link_target;
  else
    node = this->m_node;
  if ( (node->m_flags & 4 | node->m_flags & 0x51) == 4 )
    return *((_DWORD *)node - 6);
  else
    return vostok::vfs::get_raw_file_size_impl<1>(node);
}
