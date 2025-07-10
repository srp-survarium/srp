void __thiscall vostok::console_commands::cc_float::status(vostok::console_commands::cc_float *this, char (*dest)[512])
{
  int v2; // ecx

  vostok::sprintf<512>(dest, (const char *)stru_95AF78.m_key_bindings[10].m_keyboard, *this->m_value);
  vostok::console_commands::trim_float_str(v2, dest);
}
