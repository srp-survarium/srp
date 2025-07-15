void __thiscall vostok::console_commands::cc_bool::status(vostok::console_commands::cc_bool *this, char (*dest)[512])
{
  const char *v2; // eax

  v2 = "on";
  if ( !*this->m_value )
    v2 = "off";
  vostok::sprintf<512>(dest, (char *)&stru_7F9BE8.allocator, v2);
}
