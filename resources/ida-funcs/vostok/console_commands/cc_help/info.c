void __thiscall vostok::console_commands::cc_help::info(vostok::console_commands::cc_help *this, char (*dest)[512])
{
  vostok::strings::copy<512>(dest, "[command] - displays help information on that command.");
}
