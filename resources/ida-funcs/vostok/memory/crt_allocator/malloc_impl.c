void *__usercall vostok::memory::crt_allocator::malloc_impl@<eax>(
        vostok::memory::crt_allocator *this@<ecx>,
        unsigned int size@<eax>)
{
  return this->m_malloc_ptr(size);
}
