void __cdecl survarium::_dynamic_atexit_destructor_for__cc_death_camera_distance__()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  cc_death_camera_distance.__vftable = (vostok::console_commands::cc_float_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  if ( cc_death_camera_distance.m_on_change_event.vtable )
  {
    if ( ((int)cc_death_camera_distance.m_on_change_event.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)cc_death_camera_distance.m_on_change_event.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&cc_death_camera_distance.m_on_change_event.functor, &cc_death_camera_distance.m_on_change_event.functor, 2);
    }
    cc_death_camera_distance.m_on_change_event.vtable = 0;
  }
}
