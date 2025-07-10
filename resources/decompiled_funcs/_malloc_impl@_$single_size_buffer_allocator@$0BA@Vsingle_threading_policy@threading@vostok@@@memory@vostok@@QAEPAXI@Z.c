vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *__thiscall vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::malloc_impl(
        vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *this,
        unsigned int size)
{
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *result; // eax

  result = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node>::allocate(&this->m_free_list_head);
  ++this->m_allocated_count;
  return result;
}
