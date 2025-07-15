void __usercall vostok::vfs::mount_root_node_base<1>::prepend_erased_node(
        vostok::vfs::mount_root_node_base<1> *this@<ecx>,
        vostok::vfs::base_node<1> *node@<eax>)
{
  int max_storage_high; // esi

  if ( this->first_erased.pointer )
  {
    max_storage_high = HIDWORD(this->first_erased.max_storage);
    node->m_next.pointer = this->first_erased.pointer;
    HIDWORD(node->m_next.max_storage) = max_storage_high;
  }
  else
  {
    node->m_next.max_storage = 0;
  }
  this->first_erased.pointer = node;
}
