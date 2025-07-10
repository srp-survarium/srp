void *__thiscall vostok::memory::process_allocator::call_realloc(
        vostok::memory::process_allocator *this,
        void *pointer,
        unsigned int new_size)
{
  if ( new_size && pointer )
    this->usable_size_impl(this, pointer);
  return 0;
}
