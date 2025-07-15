void __cdecl dynamic_atexit_destructor_for__dispersion_magic_coef_cc__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  dispersion_magic_coef_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( dispersion_magic_coef_cc.m_on_change_event.vtable )
  {
    if ( ((int)dispersion_magic_coef_cc.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)dispersion_magic_coef_cc.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&dispersion_magic_coef_cc.m_on_change_event.functor, &dispersion_magic_coef_cc.m_on_change_event.functor, 2);
    }
    dispersion_magic_coef_cc.m_on_change_event.vtable = 0;
  }
}
