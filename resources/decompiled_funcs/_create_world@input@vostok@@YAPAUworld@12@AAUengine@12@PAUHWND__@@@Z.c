vostok::input::input_world *__fastcall vostok::input::create_world(
        vostok::input::input_world *engine,
        HWND__ *window_handle)
{
  *(_DWORD *)s_world_2.m_static_memory = &vostok::input::input_world::`vftable';
  *(_DWORD *)&s_world_2.m_static_memory[4] = 0;
  *(_DWORD *)&s_world_2.m_static_memory[8] = 0;
  *(_DWORD *)&s_world_2.m_static_memory[12] = 0;
  *(_DWORD *)&s_world_2.m_static_memory[16] = engine;
  *(_DWORD *)&s_world_2.m_static_memory[20] = 0;
  *(_DWORD *)&s_world_2.m_static_memory[24] = 0;
  *(_DWORD *)&s_world_2.m_static_memory[28] = 0;
  *(_DWORD *)&s_world_2.m_static_memory[32] = 0;
  *(_DWORD *)&s_world_2.m_static_memory[36] = 2;
  s_world_2.m_static_memory[40] = 0;
  vostok::input::input_world::create_devices(engine, window_handle);
  _InterlockedExchange(&s_world_2.m_initialized, 1);
  return s_world_2.m_variable;
}
