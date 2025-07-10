void __thiscall vostok::console_commands::cc_help::cc_help(vostok::console_commands::cc_help *this)
{
  s_help_cmd.m_command_type = command_type_user_specific;
  s_help_cmd.m_execution_type = execution_filter_general;
  s_help_cmd.m_next = 0;
  s_help_cmd.m_prev = vostok::console_commands::s_console_command_root;
  s_help_cmd.m_name = "help";
  s_help_cmd.m_need_args = 0;
  s_help_cmd.m_serializable = 0;
  s_help_cmd.m_on_change_event.vtable = 0;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_help_cmd;
  vostok::console_commands::s_console_command_root = &s_help_cmd;
  s_help_cmd.__vftable = (vostok::console_commands::cc_help_vtbl *)stru_95AF78.m_key_bindings[61].m_keyboard;
}
