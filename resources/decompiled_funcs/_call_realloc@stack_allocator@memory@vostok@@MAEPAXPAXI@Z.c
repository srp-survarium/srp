unsigned __int8 *__thiscall vostok::memory::stack_allocator::call_realloc(
        vostok::memory::stack_allocator *this,
        unsigned __int8 *pointer,
        unsigned int new_size)
{
  return vostok::memory::stack_allocator::realloc_impl(this, new_size, pointer);
}
