void __thiscall vostok::console_commands::cc_string::info(vostok::console_commands::cc_string *this, char (*dest)[512])
{
  vostok::sprintf<512>(dest, "string value.");
}
