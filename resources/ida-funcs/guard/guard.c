guard *__thiscall guard::guard(guard *this, guard *thisa)
{
  survarium::application *v2; // ecx
  vostok::engine::engine_world *v3; // ecx

  *(_DWORD *)&s_application.m_static_memory[4] = &survarium::game_module_proxy::`vftable';
  _InterlockedExchange(&s_application.m_initialized, 1);
  vostok::debug::set_support_email("game_crash_reports@survarium.com");
  s_application.m_variable->m_exit_code = 0;
  survarium::application::preinitialize(v2);
  vostok::engine::engine_world::initialize(v3);
  PostMessageA(s_splash_screen, 2u, 0, 0);
  return thisa;
}
