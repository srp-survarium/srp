void __thiscall vostok::console_commands::cc_u32::status(vostok::console_commands::cc_u32 *this, char (*dest)[512])
{
  vostok::sprintf<512>(dest, "%d", *this->m_value);
}
