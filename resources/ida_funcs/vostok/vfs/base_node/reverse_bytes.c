void __thiscall vostok::vfs::base_node<1>::reverse_bytes(vostok::vfs::base_node<1> *this)
{
  vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>((vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *)this);
  vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>(&this->m_next_overlapped);
  vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>(&this->m_hashset_next);
  vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>(&this->m_next);
  vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>((vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *)&this->m_parent);
  vostok::vfs::reverse_bytes<vostok::platform_pointer_selector<char,1>::helper>((vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *)&this->m_association);
  vostok::vfs::reverse_bytes<unsigned short>(&this->m_flags);
}
