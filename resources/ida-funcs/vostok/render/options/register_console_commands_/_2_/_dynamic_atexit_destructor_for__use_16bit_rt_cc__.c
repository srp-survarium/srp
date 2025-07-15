void __cdecl vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__use_16bit_rt_cc__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  use_16bit_rt_cc.vostok::console_commands::cc_bool::vostok::console_commands::cc_value<bool>::vostok::console_commands::console_command::__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( use_16bit_rt_cc.m_on_change_event.vtable )
  {
    if ( ((int)use_16bit_rt_cc.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)use_16bit_rt_cc.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&use_16bit_rt_cc.m_on_change_event.functor, &use_16bit_rt_cc.m_on_change_event.functor, 2);
    }
    use_16bit_rt_cc.m_on_change_event.vtable = 0;
  }
}
