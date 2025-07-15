void __thiscall vostok::memory::doug_lea_mt_allocator::initialize_impl(
        vostok::memory::doug_lea_mt_allocator *this,
        char *arena,
        unsigned __int64 arena_size,
        const char *arena_id)
{
  char (__stdcall *v5)(void *, const void *, int); // eax
  malloc_state *vostok_mspace_with_base; // eax
  bool v7; // zf
  mutex_mt_raii guard; // [esp+10h] [ebp-8h] BYREF

  if ( arena )
  {
    mutex_mt_raii::mutex_mt_raii((mutex_mt_raii *)this, &guard);
    v5 = (char (__stdcall *)(void *, const void *, int))out_of_memory_with_crash;
    if ( !this->m_crash_after_out_of_memory )
      v5 = (char (__stdcall *)(void *, const void *, int))out_of_memory_silent;
    vostok_mspace_with_base = create_vostok_mspace_with_base(
                                arena,
                                arena_size,
                                v5,
                                (char (__stdcall *)(void *, const void *, int))this);
    v7 = !guard.m_is_tasks_aware;
    this->m_arena = vostok_mspace_with_base;
    if ( v7 )
      LeaveCriticalSection((LPCRITICAL_SECTION)&guard.m_instance->m_mutex_tasks_unaware);
    else
      LeaveCriticalSection((LPCRITICAL_SECTION)&guard.m_instance->m_mutex);
  }
}
