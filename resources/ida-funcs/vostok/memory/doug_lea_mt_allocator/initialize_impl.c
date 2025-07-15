void __thiscall vostok::memory::doug_lea_mt_allocator::initialize_impl(
        vostok::memory::doug_lea_mt_allocator *this,
        char *arena,
        unsigned __int64 arena_size,
        char *arena_id)
{
  mutex_mt_raii *v5; // ecx
  mutex_mt_raii v6; // [esp+8h] [ebp-8h] BYREF

  if ( arena )
  {
    mutex_mt_raii::mutex_mt_raii(&v6, this, (vostok::threading::mutex *)this);
    vostok::memory::doug_lea_allocator::initialize_impl(this, arena, arena_size, arena_id);
    mutex_mt_raii::~mutex_mt_raii(v5, (int *)&v6);
  }
}
