int dynamic_initializer_for__s_attach_fingers_to_weapon_cc__()
{
  s_attach_fingers_to_weapon_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_attach_fingers_to_weapon_cc;
  vostok::console_commands::s_console_command_root = &s_attach_fingers_to_weapon_cc;
  s_attach_fingers_to_weapon_cc.m_value = &s_enable_finger_corrector_value;
  s_attach_fingers_to_weapon_cc.m_min = 0;
  s_attach_fingers_to_weapon_cc.m_max = 1;
  s_attach_fingers_to_weapon_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_attach_fingers_to_weapon_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_attach_fingers_to_weapon_cc__);
}
