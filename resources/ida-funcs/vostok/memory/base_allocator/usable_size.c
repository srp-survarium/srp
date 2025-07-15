unsigned int __fastcall vostok::memory::base_allocator::usable_size(
        vostok::memory::base_allocator *this,
        void *pointer)
{
  return this->usable_size_impl(this, pointer);
}
