void __thiscall vostok::memory::crt_allocator::call_free(vostok::memory::crt_allocator *this, void *pointer)
{
  if ( pointer )
    this->m_free_ptr(pointer);
}
