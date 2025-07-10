void __cdecl vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__light_propagation_volumes_rsm_size_cc__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  light_propagation_volumes_rsm_size_cc.vostok::console_commands::cc_u32::vostok::console_commands::cc_value<unsigned int>::vostok::console_commands::console_command::__vftable = (vostok::console_commands::cc_u32_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( light_propagation_volumes_rsm_size_cc.m_on_change_event.vtable )
  {
    if ( ((int)light_propagation_volumes_rsm_size_cc.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)light_propagation_volumes_rsm_size_cc.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(
          &light_propagation_volumes_rsm_size_cc.m_on_change_event.functor,
          &light_propagation_volumes_rsm_size_cc.m_on_change_event.functor,
          2);
    }
    light_propagation_volumes_rsm_size_cc.m_on_change_event.vtable = 0;
  }
}
