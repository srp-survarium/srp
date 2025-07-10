vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::node *__thiscall vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::allocate(
        vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy> *this)
{
  vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::node *result; // eax

  result = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::node>::allocate(&this->m_free_list_head);
  _InterlockedExchangeAdd(&this->m_allocated_count, 1u);
  return result;
}
