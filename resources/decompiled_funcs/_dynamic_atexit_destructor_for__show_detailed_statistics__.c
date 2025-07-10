void __cdecl dynamic_atexit_destructor_for__show_detailed_statistics__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  show_detailed_statistics.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( show_detailed_statistics.m_on_change_event.vtable )
  {
    if ( ((int)show_detailed_statistics.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)show_detailed_statistics.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&show_detailed_statistics.m_on_change_event.functor, &show_detailed_statistics.m_on_change_event.functor, 2);
    }
    show_detailed_statistics.m_on_change_event.vtable = 0;
  }
}
