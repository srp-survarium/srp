void __thiscall vostok::console_commands::cc_string::syntax(
        vostok::console_commands::cc_string *this,
        char (*dest)[512])
{
  vostok::sprintf<512>(dest, (const char *)&stru_95AF78.m_key_bindings[1].m_keyboard[1], this->m_size);
}
