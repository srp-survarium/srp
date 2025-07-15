_DWORD *__usercall vostok::memory::pthreads3_allocator::realloc_impl@<eax>(
        vostok::memory::pthreads3_allocator *this@<ecx>,
        void *pointer@<eax>,
        char *new_size@<esi>)
{
  if ( new_size )
  {
    if ( pointer )
      this->usable_size_impl(this, pointer);
    return pt3realloc((char *)pointer, new_size);
  }
  else
  {
    if ( pointer )
      pt3free((char *)pointer);
    return 0;
  }
}
