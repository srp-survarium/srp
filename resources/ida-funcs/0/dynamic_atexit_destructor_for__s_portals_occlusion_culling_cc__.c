void __cdecl dynamic_atexit_destructor_for__s_portals_occlusion_culling_cc__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  s_portals_occlusion_culling_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( s_portals_occlusion_culling_cc.m_on_change_event.vtable )
  {
    if ( ((int)s_portals_occlusion_culling_cc.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)s_portals_occlusion_culling_cc.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(
          &s_portals_occlusion_culling_cc.m_on_change_event.functor,
          &s_portals_occlusion_culling_cc.m_on_change_event.functor,
          2);
    }
    s_portals_occlusion_culling_cc.m_on_change_event.vtable = 0;
  }
}
