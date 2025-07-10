_DWORD *__thiscall vostok::memory::pthreads3_allocator::malloc_impl(
        vostok::memory::pthreads3_allocator *this,
        char *size)
{
  return pt3malloc(size);
}
