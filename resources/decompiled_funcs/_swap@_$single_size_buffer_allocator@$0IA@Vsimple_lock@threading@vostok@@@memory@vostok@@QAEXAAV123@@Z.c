void __thiscall vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::swap(
        vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *this,
        vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *other)
{
  unsigned int counter; // edx
  volatile int m_allocated_count; // [esp+10h] [ebp-Ch]
  vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::node>::free_list_type v4; // [esp+14h] [ebp-8h]

  v4.whole = (volatile __int64)this->m_free_list_head;
  counter = other->m_free_list_head.counter;
  this->m_free_list_head.pointer = other->m_free_list_head.pointer;
  this->m_free_list_head.counter = counter;
  other->m_free_list_head = v4;
  m_allocated_count = this->m_allocated_count;
  this->m_allocated_count = other->m_allocated_count;
  other->m_allocated_count = m_allocated_count;
  stlp_std::swap<unsigned int>(&this->m_max_count, &other->m_max_count);
}
