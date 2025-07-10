void *__thiscall vostok::memory::crt_allocator::call_realloc(
        vostok::memory::crt_allocator *this,
        void *pointer,
        unsigned int new_size)
{
  if ( new_size )
    return this->m_realloc_ptr(pointer, new_size);
  if ( pointer )
    this->m_free_ptr(pointer);
  return 0;
}
