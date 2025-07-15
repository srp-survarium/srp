void __thiscall vostok::console_commands::cc_delegate::info(
        vostok::console_commands::cc_delegate *this,
        char (*dest)[512])
{
  vostok::strings::copy<512>(dest, "function call");
}
