// attributes: thunk
int *__thiscall vostok::memory::doug_lea_allocator::call_malloc(
        vostok::memory::doug_lea_allocator *this,
        unsigned int size)
{
  return vostok::memory::doug_lea_allocator::malloc_impl(this, size);
}
