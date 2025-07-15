void __thiscall vostok::memory::doug_lea_allocator::initialize_impl(
        vostok::memory::doug_lea_allocator *this,
        char *arena,
        unsigned __int64 arena_size,
        const char *arena_id)
{
  char (__stdcall *v4)(void *, const void *, int); // eax

  v4 = (char (__stdcall *)(void *, const void *, int))out_of_memory_with_crash;
  if ( !this->m_crash_after_out_of_memory )
    v4 = (char (__stdcall *)(void *, const void *, int))out_of_memory_silent;
  this->m_arena = create_vostok_mspace_with_base(
                    arena,
                    arena_size,
                    v4,
                    (char (__stdcall *)(void *, const void *, int))this);
}
