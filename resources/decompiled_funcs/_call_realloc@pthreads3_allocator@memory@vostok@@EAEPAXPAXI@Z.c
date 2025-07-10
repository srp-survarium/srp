_DWORD *__thiscall vostok::memory::pthreads3_allocator::call_realloc(
        vostok::memory::pthreads3_allocator *this,
        void *pointer,
        char *new_size)
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
