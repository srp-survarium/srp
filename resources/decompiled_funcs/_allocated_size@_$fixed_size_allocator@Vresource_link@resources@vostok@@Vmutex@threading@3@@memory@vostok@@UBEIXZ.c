int __thiscall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::allocated_size(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this)
{
  return 12 * this->m_allocator.m_variable->m_allocated_count;
}
