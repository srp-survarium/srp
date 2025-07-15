void __cdecl dynamic_atexit_destructor_for__bullet_tracers_max_count_cc__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  bullet_tracers_max_count_cc.__vftable = (vostok::console_commands::cc_u32_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( bullet_tracers_max_count_cc.m_on_change_event.vtable )
  {
    if ( ((int)bullet_tracers_max_count_cc.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)bullet_tracers_max_count_cc.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(
          &bullet_tracers_max_count_cc.m_on_change_event.functor,
          &bullet_tracers_max_count_cc.m_on_change_event.functor,
          2);
    }
    bullet_tracers_max_count_cc.m_on_change_event.vtable = 0;
  }
}
