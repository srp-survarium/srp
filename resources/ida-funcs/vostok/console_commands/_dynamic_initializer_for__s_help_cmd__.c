int __thiscall vostok::console_commands::_dynamic_initializer_for__s_help_cmd__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_help_cmd,
    "help",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_help_cmd.__vftable = (vostok::console_commands::cc_help_vtbl *)&vostok::console_commands::cc_help::`vftable';
  return atexit(vostok::console_commands::_dynamic_atexit_destructor_for__s_help_cmd__);
}
