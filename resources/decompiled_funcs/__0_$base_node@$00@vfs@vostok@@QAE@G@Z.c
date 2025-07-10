void __thiscall vostok::vfs::base_node<1>::base_node<1>(vostok::vfs::base_node<1> *this, unsigned __int16 flags)
{
  this->m_next_overlapped.max_storage = 0;
  this->m_next_overlapped.pointer = 0;
  this->m_hashset_next.max_storage = 0;
  this->m_hashset_next.pointer = 0;
  this->m_next.max_storage = 0;
  this->m_next.pointer = 0;
  this->m_parent.max_storage = 0;
  this->m_parent.pointer = 0;
  this->m_association.max_storage = 0;
  this->m_association.pointer = 0;
  this->m_flags = flags;
  this->m_association_lock = 0;
  this->m_mount_root.max_storage = 0;
  this->m_mount_root.pointer = 0;
}
