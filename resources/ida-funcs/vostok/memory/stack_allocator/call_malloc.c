char *__thiscall vostok::memory::stack_allocator::call_malloc(
        vostok::memory::stack_allocator *this,
        unsigned int size,
        const char *const description,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  char *result; // eax

  result = (char *)this->m_arena_current_position;
  this->m_arena_current_position = &result[size];
  return result;
}
