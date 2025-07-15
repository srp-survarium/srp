void __thiscall vostok::memory::preinitialize(vostok::threading::mutex_tasks_unaware *ecx0)
{
  vostok::memory::base_allocator *v1; // ecx
  vostok::memory::base_allocator *v2; // ecx
  vostok::command_line::key *v3; // ecx
  vostok::command_line::key *v4; // ecx
  vostok::memory::base_allocator *v5; // ecx
  vostok::memory::base_allocator *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::memory::base_allocator *v8; // ecx
  unsigned __int64 v9; // rax
  vostok::memory::base_allocator *v10; // ecx
  unsigned int out_value; // [esp+Ch] [ebp-4h] BYREF

  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(ecx0, (_RTL_CRITICAL_SECTION *)&s_process_heap_walk);
  _InterlockedExchange(&s_process_heap_walk.m_initialized, 1);
  *(_DWORD *)s_allocators.m_static_memory = &s_allocators.m_static_memory[12];
  *(_DWORD *)&s_allocators.m_static_memory[4] = &s_allocators.m_static_memory[12];
  *(_DWORD *)&s_allocators.m_static_memory[8] = &s_allocators.m_variable;
  _InterlockedExchange(&s_allocators.m_initialized, 1);
  vostok::memory::base_allocator::do_register(
    (vostok::memory::base_allocator *)&s_allocators.m_initialized,
    (int)vostok::memory::g_crt_allocator,
    0,
    "C runtime library");
  vostok::memory::base_allocator::do_register(v1, (int)&s_process_allocator, 0, "process heap");
  vostok::memory::base_allocator::do_register(
    v2,
    (int)&vostok::strings::shared::g_allocator,
    (unsigned int)&loc_100000,
    "shared strings");
  out_value = 0x1000000;
  if ( vostok::command_line::key::is_set_as_number<unsigned int>(v3, (int)&s_mt_allocator_memory, &out_value) )
    out_value <<= 20;
  else
    out_value += 260046848;
  if ( vostok::testing::run_tests_command_line(v4) )
    out_value += 0x1000000;
  vostok::memory::base_allocator::do_register(
    v5,
    (int)&vostok::memory::g_mt_allocator,
    out_value,
    "global multithreaded");
  if ( vostok::memory::g_use_resources_manager )
  {
    vostok::memory::base_allocator::do_register(
      v6,
      (int)&vostok::memory::g_cook_allocator,
      (unsigned int)&loc_11FFFF + 1,
      "cook allocator");
    out_value = (unsigned int)&loc_400000;
    if ( vostok::command_line::key::is_set_as_number<unsigned int>(v7, (int)&s_rh_allocator_memory, &out_value) )
      out_value <<= 20;
    vostok::memory::base_allocator::do_register(
      v8,
      (int)&vostok::memory::g_resources_helper_allocator,
      out_value,
      "resources helper allocator");
    v9 = vostok::math::align_down<unsigned __int64>(0x80000u, 0xCu);
    vostok::memory::base_allocator::do_register(
      v10,
      (int)&vostok::memory::g_resources_links_allocator,
      v9,
      "resources links allocator");
  }
}
