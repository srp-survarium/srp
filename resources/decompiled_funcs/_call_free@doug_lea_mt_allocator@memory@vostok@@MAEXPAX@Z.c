void __thiscall vostok::memory::doug_lea_mt_allocator::call_free(
        vostok::memory::doug_lea_mt_allocator *this,
        char *pointer)
{
  vostok::memory::doug_lea_mt_allocator::free_impl(this, (int)this, pointer);
}
