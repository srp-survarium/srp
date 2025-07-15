void __cdecl survarium::game_module::destroy_world(vostok::engine_user::world **world)
{
  ((void (__thiscall *)(survarium::game *, _DWORD))s_game.m_variable->~survarium::game)(s_game.m_variable, 0);
  s_game.m_initialized = 0;
  *world = 0;
}
