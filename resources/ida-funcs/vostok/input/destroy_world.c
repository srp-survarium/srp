void __cdecl vostok::input::destroy_world(vostok::input::world **world)
{
  ((void (__thiscall *)(vostok::input::input_world *, _DWORD))s_world_2.m_variable->~vostok::input::input_world)(
    s_world_2.m_variable,
    0);
  s_world_2.m_initialized = 0;
  *world = 0;
}
