void __usercall vostok::memory::managed_node_owner::resize_down(
        vostok::memory::managed_node_owner *this@<esi>,
        unsigned int new_size@<eax>)
{
  this->on_managed_node_resized(this, new_size);
  vostok::memory::managed_allocator_base::resize_down(
    this->m_node,
    new_size + 52,
    &this->m_allocator->vostok::memory::managed_allocator_base);
}
