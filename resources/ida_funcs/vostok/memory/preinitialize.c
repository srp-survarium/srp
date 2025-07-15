void __cdecl vostok::memory::preinitialize()
{
  int v0; // esi
  vostok::command_line::key *v1; // ecx

  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&s_process_heap_walk, 0x2710u);
  _InterlockedExchange(&s_process_heap_walk.m_initialized, 1);
  *(_DWORD *)s_allocators.m_static_memory = &s_allocators.m_static_memory[8];
  *(_DWORD *)&s_allocators.m_static_memory[4] = &s_allocators.m_static_memory[8];
  _InterlockedExchange(&s_allocators.m_initialized, 1);
  vostok::memory::register_allocator(
    (vostok::memory::base_allocator *)vostok::memory::g_crt_allocator.__vftable,
    0,
    "C runtime library");
  vostok::memory::register_allocator(&s_process_allocator, 0, "process heap");
  vostok::memory::register_allocator(&vostok::strings::shared::g_allocator, 0x40000u, "shared strings");
  v0 = 327155712;
  if ( vostok::testing::run_tests_command_line(v1) )
    v0 = 343932928;
  vostok::memory::register_allocator(&vostok::memory::g_mt_allocator, (unsigned int)v0, "global multithreaded");
  if ( vostok::memory::g_use_resources_manager )
  {
    vostok::memory::register_allocator(&vostok::memory::g_cook_allocator, (unsigned int)&loc_120000, "cook allocator");
    vostok::memory::register_allocator(
      &vostok::memory::g_resources_helper_allocator,
      (unsigned int)&unk_800000,
      "resources helper allocator");
    vostok::memory::register_allocator(
      &vostok::memory::g_resources_links_allocator,
      (unsigned int)&loc_3FFFC,
      "resources links allocator");
  }
}
