void __thiscall vostok::memory::base_allocator::free_impl(vostok::memory::base_allocator *this, void *pointer)
{
  this->call_free(this, pointer);
}
