void __cdecl survarium::_dynamic_atexit_destructor_for__set_mouse_sensitivity_cc__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  set_mouse_sensitivity_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( set_mouse_sensitivity_cc.m_on_change_event.vtable )
  {
    if ( ((int)set_mouse_sensitivity_cc.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)set_mouse_sensitivity_cc.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&set_mouse_sensitivity_cc.m_on_change_event.functor, &set_mouse_sensitivity_cc.m_on_change_event.functor, 2);
    }
    set_mouse_sensitivity_cc.m_on_change_event.vtable = 0;
  }
}
