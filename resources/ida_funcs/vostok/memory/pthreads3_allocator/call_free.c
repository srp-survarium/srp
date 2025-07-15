void __thiscall vostok::memory::pthreads3_allocator::call_free(
        vostok::memory::pthreads3_allocator *this,
        char *pointer)
{
  if ( pointer )
    pt3free(pointer);
}
