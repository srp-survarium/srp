void __stdcall vostok::memory::base_allocator::do_register(
        vostok::memory::base_allocator *this,
        unsigned __int64 arena_size)
{
  const char *v3; // [esp+0h] [ebp-4h]

  vostok::memory::register_allocator(this, arena_size, v3);
}
