void __cdecl survarium::game::update_stats_::_7_::_dynamic_atexit_destructor_for__fps_graph__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  fps_graph.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( fps_graph.m_on_change_event.vtable )
  {
    if ( ((int)fps_graph.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)fps_graph.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&fps_graph.m_on_change_event.functor, &fps_graph.m_on_change_event.functor, 2);
    }
    fps_graph.m_on_change_event.vtable = 0;
  }
}
