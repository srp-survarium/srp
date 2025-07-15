void __cdecl vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__lpv_disable_rsm_generating_cc__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  lpv_disable_rsm_generating_cc.vostok::console_commands::cc_bool::vostok::console_commands::cc_value<bool>::vostok::console_commands::console_command::__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( lpv_disable_rsm_generating_cc.m_on_change_event.vtable )
  {
    if ( ((int)lpv_disable_rsm_generating_cc.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)lpv_disable_rsm_generating_cc.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(
          &lpv_disable_rsm_generating_cc.m_on_change_event.functor,
          &lpv_disable_rsm_generating_cc.m_on_change_event.functor,
          2);
    }
    lpv_disable_rsm_generating_cc.m_on_change_event.vtable = 0;
  }
}
