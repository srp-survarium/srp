void __thiscall survarium::application::finalize(survarium::application *this)
{
  ((void (__thiscall *)(vostok::engine::engine_world *, _DWORD))s_world.m_variable->~vostok::engine::engine_world)(
    s_world.m_variable,
    0);
  s_world.m_initialized = 0;
}
