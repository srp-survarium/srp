vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node *__thiscall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::call_malloc(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this,
        unsigned int size)
{
  vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex> *m_variable; // esi
  vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node *result; // eax

  m_variable = this->m_allocator.m_variable;
  result = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node>::allocate(&m_variable->m_free_list_head);
  _InterlockedExchangeAdd(&m_variable->m_allocated_count, 1u);
  return result;
}
