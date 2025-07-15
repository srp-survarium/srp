vostok::memory::doug_lea_allocator *__thiscall survarium::game_module::register_memory_allocators(
        vostok::command_line::key *ecx0)
{
  vostok::memory::base_allocator *v1; // ecx
  vostok::memory::doug_lea_allocator *result; // eax
  char Filename[264]; // [esp+10h] [ebp-108h] BYREF

  if ( !vostok::command_line::key::is_set(ecx0, (int)&s_skip_firewall_check) )
  {
    GetModuleFileNameA(0, Filename, 0x104u);
    if ( !CanLaunchMultiplayerGameA(Filename) )
      vostok::debug::terminate("Survarium tries to run multiplayer game, but is blocked by Windows Firewall");
  }
  vostok::memory::doug_lea_allocator::doug_lea_allocator(
    (vostok::memory::doug_lea_allocator *)&s_input_allocator,
    thread_id_const_true,
    1,
    0,
    1);
  _InterlockedExchange(&s_input_allocator.m_initialized, 1);
  vostok::memory::base_allocator::do_register(
    (vostok::memory::base_allocator *)&s_input_allocator.m_initialized,
    (int)s_input_allocator.m_variable,
    (unsigned int)&_sbh_sizeHeaderList,
    "input");
  vostok::memory::doug_lea_allocator::doug_lea_allocator(
    (vostok::memory::doug_lea_allocator *)&s_ai_allocator,
    thread_id_const_true,
    1,
    0,
    1);
  _InterlockedExchange(&s_ai_allocator.m_initialized, 1);
  vostok::memory::base_allocator::do_register(
    (vostok::memory::base_allocator *)&s_ai_allocator.m_initialized,
    (int)s_ai_allocator.m_variable,
    (unsigned int)&loc_20000,
    "ai");
  vostok::memory::doug_lea_allocator::doug_lea_allocator(
    (vostok::memory::doug_lea_allocator *)&s_game_allocator,
    thread_id_const_true,
    1,
    0,
    1);
  _InterlockedExchange(&s_game_allocator.m_initialized, 1);
  vostok::memory::base_allocator::do_register(v1, (int)s_game_allocator.m_variable, 0xA00000u, "survarium");
  result = s_game_allocator.m_variable;
  survarium::g_allocator = s_game_allocator.m_variable;
  return result;
}
