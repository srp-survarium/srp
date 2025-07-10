void __cdecl vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__gamma_correction_factor_cc__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  gamma_correction_factor_cc.vostok::console_commands::cc_float::vostok::console_commands::cc_value<float>::vostok::console_commands::console_command::__vftable = (vostok::console_commands::cc_float_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( gamma_correction_factor_cc.m_on_change_event.vtable )
  {
    if ( ((int)gamma_correction_factor_cc.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)gamma_correction_factor_cc.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(
          &gamma_correction_factor_cc.m_on_change_event.functor,
          &gamma_correction_factor_cc.m_on_change_event.functor,
          2);
    }
    gamma_correction_factor_cc.m_on_change_event.vtable = 0;
  }
}
