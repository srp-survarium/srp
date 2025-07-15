void *__thiscall vostok::memory::crt_allocator::call_malloc(vostok::memory::crt_allocator *this, unsigned int size)
{
  return this->m_malloc_ptr(size);
}
