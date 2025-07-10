// attributes: thunk
int *__thiscall vostok::memory::doug_lea_allocator::call_realloc(
        vostok::memory::doug_lea_allocator *this,
        char *pointer,
        unsigned int new_size)
{
  return vostok::memory::doug_lea_allocator::realloc_impl(this, pointer, new_size);
}
