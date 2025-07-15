void __thiscall vostok::console_commands::console_command::syntax(
        vostok::console_commands::console_command *this,
        char (*dest)[512])
{
  vostok::strings::copy<512>(dest, "(no arguments)");
}
