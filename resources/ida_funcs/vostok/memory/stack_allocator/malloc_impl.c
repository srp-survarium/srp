char *__fastcall vostok::memory::stack_allocator::malloc_impl(vostok::memory::stack_allocator *this, unsigned int size)
{
  char *result; // eax

  result = (char *)this->m_arena_current_position;
  this->m_arena_current_position = &result[size];
  return result;
}
