void __cdecl vostok::network::destroy_world(vostok::network::world **world)
{
  ((void (__thiscall *)(vostok::network::network_world *, _DWORD))s_world_2.m_variable->~vostok::network::network_world)(
    s_world_2.m_variable,
    0);
  s_world_2.m_initialized = 0;
  *world = 0;
}
