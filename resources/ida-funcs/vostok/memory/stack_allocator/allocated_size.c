int __thiscall vostok::memory::stack_allocator::allocated_size(vostok::memory::stack_allocator *this)
{
  return (char *)this->m_arena_current_position - (char *)this->m_arena_start;
}
