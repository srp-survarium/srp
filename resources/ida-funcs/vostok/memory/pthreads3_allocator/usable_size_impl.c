unsigned int __thiscall vostok::memory::pthreads3_allocator::usable_size_impl(
        vostok::memory::pthreads3_allocator *this,
        void *pointer)
{
  return vostok_mspace_usable_size(pointer);
}
