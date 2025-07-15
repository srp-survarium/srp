vostok::memory::single_size_buffer_allocator<512,vostok::threading::multi_threading_policy>::node *__thiscall vostok::network_core::handler_allocator<32,512,1>::allocate(
        vostok::network_core::handler_allocator<32,512,1> *this)
{
  vostok::memory::single_size_fixed_allocator<512,32,vostok::threading::multi_threading_policy> *p_m_allocator; // esi
  volatile int *p_m_allocated_count; // edi
  vostok::memory::single_size_buffer_allocator<512,vostok::threading::multi_threading_policy>::node *result; // eax

  p_m_allocator = &this->m_allocator;
  this->m_max_count -= this->m_max_count < this->m_allocator.m_allocated_count + 1
                     ? this->m_max_count - (this->m_allocator.m_allocated_count + 1)
                     : 0;
  p_m_allocated_count = &this->m_allocator.m_allocated_count;
  if ( this->m_allocator.m_allocated_count >= this->m_allocator.m_max_count
    && (p_m_allocator->m_on_out_of_memory.vtable != 0
      ? (unsigned int)vostok::memory::process_allocator::finalize_impl
      : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this,
      &this->m_allocator.m_on_out_of_memory.vtable,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)&this->m_allocator);
  }
  result = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<512,vostok::threading::multi_threading_policy>::node>::allocate(&p_m_allocator->m_free_list_head);
  _InterlockedExchangeAdd(p_m_allocated_count, 1u);
  return result;
}


vostok::memory::single_size_buffer_allocator<96,vostok::threading::multi_threading_policy>::node *__thiscall vostok::network_core::handler_allocator<1024,96,1>::allocate(
        vostok::network_core::handler_allocator<1024,96,1> *this)
{
  vostok::memory::single_size_fixed_allocator<96,1024,vostok::threading::multi_threading_policy> *p_m_allocator; // esi
  volatile int *p_m_allocated_count; // edi
  vostok::memory::single_size_buffer_allocator<96,vostok::threading::multi_threading_policy>::node *result; // eax

  p_m_allocator = &this->m_allocator;
  this->m_max_count -= this->m_max_count < this->m_allocator.m_allocated_count + 1
                     ? this->m_max_count - (this->m_allocator.m_allocated_count + 1)
                     : 0;
  p_m_allocated_count = &this->m_allocator.m_allocated_count;
  if ( this->m_allocator.m_allocated_count >= this->m_allocator.m_max_count
    && (p_m_allocator->m_on_out_of_memory.vtable != 0
      ? (unsigned int)vostok::memory::process_allocator::finalize_impl
      : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this,
      &this->m_allocator.m_on_out_of_memory.vtable,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)&this->m_allocator);
  }
  result = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<96,vostok::threading::multi_threading_policy>::node>::allocate(&p_m_allocator->m_free_list_head);
  _InterlockedExchangeAdd(p_m_allocated_count, 1u);
  return result;
}
