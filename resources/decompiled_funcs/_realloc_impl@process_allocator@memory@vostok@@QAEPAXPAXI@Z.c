void *__userpurge vostok::memory::process_allocator::realloc_impl@<eax>(
        vostok::memory::process_allocator *this@<ecx>,
        void *pointer@<eax>,
        unsigned int new_size)
{
  if ( new_size && pointer )
    this->usable_size_impl(this, pointer);
  return 0;
}
