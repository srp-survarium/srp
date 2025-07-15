int *__thiscall vostok::memory::doug_lea_mt_allocator::call_malloc(
        vostok::memory::doug_lea_mt_allocator *this,
        unsigned int size)
{
  return vostok::memory::doug_lea_mt_allocator::malloc_impl(this, (mutex_mt_raii *)this, size);
}
