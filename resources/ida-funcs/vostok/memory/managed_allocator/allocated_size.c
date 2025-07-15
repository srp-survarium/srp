unsigned int __thiscall vostok::memory::managed_allocator::allocated_size(vostok::memory::managed_allocator *this)
{
  return this->m_arena_size - this->m_free_size;
}
