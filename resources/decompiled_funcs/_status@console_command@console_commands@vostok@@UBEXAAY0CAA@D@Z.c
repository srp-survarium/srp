void __thiscall vostok::console_commands::console_command::status(
        vostok::console_commands::console_command *this,
        char (*dest)[512])
{
  strcpy_s((char *)dest, 0x200u, "unknown");
}
