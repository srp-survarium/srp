int survarium::_dynamic_initializer_for__s_first_person_animations_command__()
{
  s_first_person_animations_command.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_first_person_animations_command;
  vostok::console_commands::s_console_command_root = &s_first_person_animations_command;
  s_first_person_animations_command.m_value = (bool *)&survarium::g_allocator.l_.a2_;
  s_first_person_animations_command.m_min = 0;
  s_first_person_animations_command.m_max = 1;
  s_first_person_animations_command.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_first_person_animations_command.m_need_args = 1;
  return atexit(survarium::_dynamic_atexit_destructor_for__s_first_person_animations_command__);
}
