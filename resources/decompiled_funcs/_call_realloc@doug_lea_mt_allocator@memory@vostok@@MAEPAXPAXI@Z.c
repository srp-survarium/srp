int *__thiscall vostok::memory::doug_lea_mt_allocator::call_realloc(
        vostok::memory::doug_lea_mt_allocator *this,
        char *pointer,
        unsigned int new_size)
{
  return vostok::memory::doug_lea_mt_allocator::realloc_impl(this, (mutex_mt_raii *)this, pointer, new_size);
}
