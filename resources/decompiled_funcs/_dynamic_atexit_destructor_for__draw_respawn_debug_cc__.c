void __cdecl dynamic_atexit_destructor_for__draw_respawn_debug_cc__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  draw_respawn_debug_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( draw_respawn_debug_cc.m_on_change_event.vtable )
  {
    if ( ((int)draw_respawn_debug_cc.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)draw_respawn_debug_cc.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&draw_respawn_debug_cc.m_on_change_event.functor, &draw_respawn_debug_cc.m_on_change_event.functor, 2);
    }
    draw_respawn_debug_cc.m_on_change_event.vtable = 0;
  }
}
