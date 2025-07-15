int __thiscall vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<10340,128,vostok::threading::multi_threading_policy>>::allocated_size(
        vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<10340,128,vostok::threading::multi_threading_policy> > *this)
{
  return 10340 * this->m_allocator->m_allocated_count;
}


int __thiscall vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<1024,2048,vostok::threading::multi_threading_policy>>::allocated_size(
        vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<1024,2048,vostok::threading::multi_threading_policy> > *this)
{
  return this->m_allocator->m_allocated_count << 10;
}


int __thiscall vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<57460,1024,vostok::threading::multi_threading_policy>>::allocated_size(
        vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<57460,1024,vostok::threading::multi_threading_policy> > *this)
{
  return 57460 * this->m_allocator->m_allocated_count;
}
