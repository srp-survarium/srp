void __thiscall vostok::memory::pthreads3_allocator::free_impl(
        vostok::memory::pthreads3_allocator *this,
        char *pointer)
{
  if ( pointer )
    pt3free(pointer);
}
