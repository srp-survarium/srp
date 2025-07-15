void __thiscall vostok::memory::doug_lea_mt_allocator::initialize(
        vostok::memory::doug_lea_mt_allocator *this,
        char *arena,
        unsigned __int64 arena_size,
        const char *arena_id)
{
  if ( arena )
    vostok::memory::base_allocator::initialize(this, arena, arena_size, arena_id);
}
