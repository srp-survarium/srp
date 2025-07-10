void __thiscall vostok::console_commands::console_command::syntax(
        vostok::console_commands::console_command *this,
        char (*dest)[512])
{
  strcpy_s((char *)dest, 0x200u, "(no arguments)");
}
