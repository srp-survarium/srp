void __thiscall vostok::console_commands::cc_help::info(vostok::console_commands::cc_help *this, char (*dest)[512])
{
  strcpy_s((char *)dest, 0x200u, (const char *)stru_95AF78.m_key_bindings[32].m_keyboard);
}
