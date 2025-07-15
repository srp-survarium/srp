_DWORD *__thiscall vostok::memory::pthreads3_allocator::call_malloc(
        vostok::memory::pthreads3_allocator *this,
        char *size)
{
  return pt3malloc(size);
}
