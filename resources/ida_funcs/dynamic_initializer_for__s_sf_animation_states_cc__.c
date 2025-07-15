int dynamic_initializer_for__s_sf_animation_states_cc__()
{
  s_sf_animation_states_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_sf_animation_states_cc;
  vostok::console_commands::s_console_command_root = &s_sf_animation_states_cc;
  s_sf_animation_states_cc.m_value = &s_sf_animation_states_value;
  s_sf_animation_states_cc.m_min = 0;
  s_sf_animation_states_cc.m_max = 1;
  s_sf_animation_states_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_sf_animation_states_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_sf_animation_states_cc__);
}
