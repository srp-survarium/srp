int vostok::render::_dynamic_initializer_for__s_sun_moving__()
{
  s_sun_moving.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_sun_moving;
  vostok::console_commands::s_console_command_root = &s_sun_moving;
  s_sun_moving.m_value = &s_sun_moving_value;
  s_sun_moving.m_min = 0;
  s_sun_moving.m_max = 1;
  s_sun_moving.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_sun_moving.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_sun_moving__);
}
