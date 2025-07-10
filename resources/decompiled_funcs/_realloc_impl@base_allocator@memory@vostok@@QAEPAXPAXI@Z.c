void *__thiscall vostok::memory::base_allocator::realloc_impl(
        vostok::memory::base_allocator *this,
        void *pointer,
        unsigned int new_size)
{
  return this->call_realloc(this, pointer, new_size);
}
