void *__thiscall vostok::memory::base_allocator::malloc_impl(vostok::memory::base_allocator *this, unsigned int size)
{
  return this->call_malloc(this, size);
}
