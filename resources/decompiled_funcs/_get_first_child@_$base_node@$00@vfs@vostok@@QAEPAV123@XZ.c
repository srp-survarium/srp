vostok::vfs::base_node<1> *__thiscall vostok::vfs::base_node<1>::get_first_child(vostok::vfs::base_node<1> *this)
{
  if ( (this->m_flags & 1) == 1 )
    return vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(this)->m_first_child.pointer;
  else
    return 0;
}
