void __thiscall vostok::console_commands::cc_u32::syntax(vostok::console_commands::cc_u32 *this, char (*dest)[512])
{
  vostok::sprintf<512>(dest, (const char *)&stru_95AF78.m_key_bindings[16].m_keyboard[1], this->m_min, this->m_max);
}
