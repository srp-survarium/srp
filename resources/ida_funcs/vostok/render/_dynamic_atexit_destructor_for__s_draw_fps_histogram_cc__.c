void __cdecl vostok::render::_dynamic_atexit_destructor_for__s_draw_fps_histogram_cc__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  s_draw_fps_histogram_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( s_draw_fps_histogram_cc.m_on_change_event.vtable )
  {
    if ( ((int)s_draw_fps_histogram_cc.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)s_draw_fps_histogram_cc.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&s_draw_fps_histogram_cc.m_on_change_event.functor, &s_draw_fps_histogram_cc.m_on_change_event.functor, 2);
    }
    s_draw_fps_histogram_cc.m_on_change_event.vtable = 0;
  }
}
