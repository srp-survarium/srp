void __cdecl vostok::render::_dynamic_atexit_destructor_for__s_dxt_env_probe_cc___0()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  s_dxt_env_probe_cc_0.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( s_dxt_env_probe_cc_0.m_on_change_event.vtable )
  {
    if ( ((int)s_dxt_env_probe_cc_0.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)s_dxt_env_probe_cc_0.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&s_dxt_env_probe_cc_0.m_on_change_event.functor, &s_dxt_env_probe_cc_0.m_on_change_event.functor, 2);
    }
    s_dxt_env_probe_cc_0.m_on_change_event.vtable = 0;
  }
}
