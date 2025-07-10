void __thiscall vostok::console_commands::cc_bool::status(vostok::console_commands::cc_bool *this, char (*dest)[512])
{
  survarium::keyboard_key_descr **m_keyboard; // eax

  m_keyboard = stru_95AF78.m_key_bindings[4].m_keyboard;
  if ( !*this->m_value )
    m_keyboard = &stru_95AF78.m_key_bindings[5].m_keyboard[1];
  vostok::sprintf<512>(dest, "%s", (const char *)m_keyboard);
}
