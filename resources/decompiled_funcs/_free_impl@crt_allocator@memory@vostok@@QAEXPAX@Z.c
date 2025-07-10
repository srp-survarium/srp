void __userpurge vostok::memory::crt_allocator::free_impl(void *pointer@<eax>, vostok::memory::crt_allocator *this)
{
  if ( pointer )
    this->m_free_ptr(pointer);
}
