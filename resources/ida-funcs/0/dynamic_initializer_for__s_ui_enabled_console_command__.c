int __thiscall dynamic_initializer_for__s_ui_enabled_console_command__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_ui_enabled_console_command,
    "ui",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_ui_enabled_console_command.m_value = &s_ui_enabled;
  s_ui_enabled_console_command.m_min = 0;
  s_ui_enabled_console_command.m_max = 1;
  s_ui_enabled_console_command.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_ui_enabled_console_command.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_ui_enabled_console_command__);
}
