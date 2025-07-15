void *__userpurge vostok::memory::base_allocator::on_malloc@<eax>(
        vostok::memory::base_allocator *this@<ecx>,
        int a2@<eax>,
        void *buffer,
        unsigned int buffer_size,
        unsigned int previous_size,
        const char *description)
{
  if ( *(_BYTE *)(a2 + 16) )
    vostok::memory::monitor::on_alloc(&buffer, &buffer_size, description);
  return buffer;
}
