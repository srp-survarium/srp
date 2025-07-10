int __thiscall vostok::memory::stack_allocator::total_size(vostok::memory::stack_allocator *this)
{
  return (char *)this->m_arena_end - (char *)this->m_arena_start;
}
