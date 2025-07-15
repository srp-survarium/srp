void __thiscall vostok::memory::doug_lea_mt_allocator::initialize(
        vostok::memory::doug_lea_mt_allocator *this,
        char *arena,
        unsigned __int64 arena_size,
        const char *arena_id)
{
  vostok::memory::doug_lea_mt_allocator_vtbl *v4; // edi

  if ( arena )
  {
    this->m_arena_id = arena_id;
    this->m_arena_end = &arena[arena_size];
    v4 = this->__vftable;
    this->m_arena_start = arena;
    ((void (__stdcall *)(char *, _DWORD, _DWORD, const char *))v4->initialize_impl)(
      arena,
      arena_size,
      HIDWORD(arena_size),
      arena_id);
  }
}
