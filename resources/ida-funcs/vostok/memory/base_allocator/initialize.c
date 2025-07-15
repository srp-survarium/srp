void __thiscall vostok::memory::base_allocator::initialize(
        vostok::memory::base_allocator *this,
        char *arena,
        unsigned __int64 size,
        const char *arena_id)
{
  vostok::memory::base_allocator_vtbl *v4; // edi

  this->m_arena_end = &arena[size];
  v4 = this->__vftable;
  this->m_arena_id = arena_id;
  this->m_arena_start = arena;
  ((void (__stdcall *)(char *, _DWORD, _DWORD, const char *))v4->initialize_impl)(arena, size, HIDWORD(size), arena_id);
}
