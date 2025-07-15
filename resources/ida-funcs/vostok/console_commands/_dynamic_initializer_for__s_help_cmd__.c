int __thiscall vostok::console_commands::_dynamic_initializer_for__s_help_cmd__(
        vostok::console_commands::cc_help *this)
{
  vostok::console_commands::cc_help::cc_help(this);
  return atexit(vostok::console_commands::_dynamic_atexit_destructor_for__s_help_cmd__);
}
