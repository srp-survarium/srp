void __cdecl survarium::game_module::register_memory_allocators()
{
  *(_DWORD *)&s_input_allocator.m_static_memory[4] = 0;
  *(_DWORD *)&s_input_allocator.m_static_memory[8] = 0;
  *(_DWORD *)&s_input_allocator.m_static_memory[12] = 0;
  *(_DWORD *)s_input_allocator.m_static_memory = &vostok::memory::doug_lea_allocator::`vftable';
  *(_DWORD *)&s_input_allocator.m_static_memory[20] = 0;
  *(_DWORD *)&s_input_allocator.m_static_memory[24] = "invalid thread id";
  *(_DWORD *)&s_input_allocator.m_static_memory[28] = 1;
  s_input_allocator.m_static_memory[32] = 0;
  *(_DWORD *)&s_input_allocator.m_static_memory[36] = GetCurrentThreadId();
  s_input_allocator.m_static_memory[40] = 1;
  s_input_allocator.m_static_memory[41] = 0;
  s_input_allocator.m_static_memory[42] = 0;
  s_input_allocator.m_static_memory[43] = 1;
  _InterlockedExchange(&s_input_allocator.m_initialized, 1);
  vostok::memory::register_allocator(s_input_allocator.m_variable, (unsigned int)&_sbh_sizeHeaderList, "input");
  *(_DWORD *)&s_ui_allocator.m_static_memory[4] = 0;
  *(_DWORD *)&s_ui_allocator.m_static_memory[8] = 0;
  *(_DWORD *)&s_ui_allocator.m_static_memory[12] = 0;
  *(_DWORD *)s_ui_allocator.m_static_memory = &vostok::memory::doug_lea_allocator::`vftable';
  *(_DWORD *)&s_ui_allocator.m_static_memory[20] = 0;
  *(_DWORD *)&s_ui_allocator.m_static_memory[24] = "invalid thread id";
  *(_DWORD *)&s_ui_allocator.m_static_memory[28] = 1;
  s_ui_allocator.m_static_memory[32] = 0;
  *(_DWORD *)&s_ui_allocator.m_static_memory[36] = GetCurrentThreadId();
  s_ui_allocator.m_static_memory[40] = 1;
  s_ui_allocator.m_static_memory[41] = 0;
  s_ui_allocator.m_static_memory[42] = 0;
  s_ui_allocator.m_static_memory[43] = 1;
  _InterlockedExchange(&s_ui_allocator.m_initialized, 1);
  vostok::memory::register_allocator(
    s_ui_allocator.m_variable,
    (unsigned int)&_sbh_sizeHeaderList,
    (const char *)&stru_961088);
  *(_DWORD *)&s_ai_navigation_allocator.m_static_memory[4] = 0;
  *(_DWORD *)&s_ai_navigation_allocator.m_static_memory[8] = 0;
  *(_DWORD *)&s_ai_navigation_allocator.m_static_memory[12] = 0;
  *(_DWORD *)s_ai_navigation_allocator.m_static_memory = &vostok::memory::doug_lea_allocator::`vftable';
  *(_DWORD *)&s_ai_navigation_allocator.m_static_memory[20] = 0;
  *(_DWORD *)&s_ai_navigation_allocator.m_static_memory[24] = "invalid thread id";
  *(_DWORD *)&s_ai_navigation_allocator.m_static_memory[28] = 1;
  s_ai_navigation_allocator.m_static_memory[32] = 0;
  *(_DWORD *)&s_ai_navigation_allocator.m_static_memory[36] = GetCurrentThreadId();
  s_ai_navigation_allocator.m_static_memory[40] = 1;
  s_ai_navigation_allocator.m_static_memory[41] = 0;
  s_ai_navigation_allocator.m_static_memory[42] = 0;
  s_ai_navigation_allocator.m_static_memory[43] = 1;
  _InterlockedExchange(&s_ai_navigation_allocator.m_initialized, 1);
  vostok::memory::register_allocator(
    s_ai_navigation_allocator.m_variable,
    (unsigned int)&_sbh_sizeHeaderList,
    "ai navigation");
  *(_DWORD *)&s_ai_allocator.m_static_memory[4] = 0;
  *(_DWORD *)&s_ai_allocator.m_static_memory[8] = 0;
  *(_DWORD *)&s_ai_allocator.m_static_memory[12] = 0;
  *(_DWORD *)s_ai_allocator.m_static_memory = &vostok::memory::doug_lea_allocator::`vftable';
  *(_DWORD *)&s_ai_allocator.m_static_memory[20] = 0;
  *(_DWORD *)&s_ai_allocator.m_static_memory[24] = "invalid thread id";
  *(_DWORD *)&s_ai_allocator.m_static_memory[28] = 1;
  s_ai_allocator.m_static_memory[32] = 0;
  *(_DWORD *)&s_ai_allocator.m_static_memory[36] = GetCurrentThreadId();
  s_ai_allocator.m_static_memory[40] = 1;
  s_ai_allocator.m_static_memory[41] = 0;
  s_ai_allocator.m_static_memory[42] = 0;
  s_ai_allocator.m_static_memory[43] = 1;
  _InterlockedExchange(&s_ai_allocator.m_initialized, 1);
  vostok::memory::register_allocator(s_ai_allocator.m_variable, (unsigned int)&unk_800000, "ai");
  *(_DWORD *)&s_game_allocator.m_static_memory[4] = 0;
  *(_DWORD *)&s_game_allocator.m_static_memory[8] = 0;
  *(_DWORD *)&s_game_allocator.m_static_memory[12] = 0;
  *(_DWORD *)s_game_allocator.m_static_memory = &vostok::memory::doug_lea_allocator::`vftable';
  *(_DWORD *)&s_game_allocator.m_static_memory[20] = 0;
  *(_DWORD *)&s_game_allocator.m_static_memory[24] = "invalid thread id";
  *(_DWORD *)&s_game_allocator.m_static_memory[28] = 1;
  s_game_allocator.m_static_memory[32] = 0;
  *(_DWORD *)&s_game_allocator.m_static_memory[36] = GetCurrentThreadId();
  s_game_allocator.m_static_memory[40] = 1;
  s_game_allocator.m_static_memory[41] = 0;
  s_game_allocator.m_static_memory[42] = 0;
  s_game_allocator.m_static_memory[43] = 1;
  _InterlockedExchange(&s_game_allocator.m_initialized, 1);
  vostok::memory::register_allocator(
    s_game_allocator.m_variable,
    (unsigned int)&vostok::memory::s_CRT_arena[55905848],
    "survarium");
  LODWORD(survarium::g_allocator.f_.f_) = s_game_allocator.m_variable;
}
