void *__userpurge vostok::memory::crt_allocator::realloc_impl@<eax>(
        void *pointer@<ecx>,
        unsigned int new_size@<eax>,
        vostok::memory::crt_allocator *this)
{
  if ( new_size )
    return this->m_realloc_ptr(pointer, new_size);
  if ( pointer )
    this->m_free_ptr(pointer);
  return 0;
}
