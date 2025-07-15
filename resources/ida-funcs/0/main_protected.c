void __thiscall main_protected(guard *this)
{
  vostok::engine::engine_world *v1; // ecx
  survarium::application *m_variable; // eax
  survarium::application *v3; // edi
  guard guard; // [esp+1h] [ebp-1h] BYREF

  guard = (guard)HIBYTE(this);
  guard::guard(this, &guard);
  m_variable = s_application.m_variable;
  if ( !s_application.m_variable->m_exit_code )
  {
    v3 = s_application.m_variable;
    vostok::engine::engine_world::run(v1);
    v3->m_exit_code = s_world.m_variable->get_exit_code(s_world.m_variable);
    m_variable = s_application.m_variable;
  }
  s_exit_code = m_variable->m_exit_code;
  ((void (__thiscall *)(vostok::engine::engine_world *, _DWORD))s_world.m_variable->~vostok::engine::engine_world)(
    s_world.m_variable,
    0);
  s_world.m_initialized = 0;
  s_application.m_initialized = 0;
}
