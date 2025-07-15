void __thiscall vostok::console_commands::cc_bool::syntax(vostok::console_commands::cc_bool *this, char (*dest)[512])
{
  vostok::sprintf<512>(dest, "on/off, true/false, 1/0");
}
