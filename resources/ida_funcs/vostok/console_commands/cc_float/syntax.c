void __thiscall vostok::console_commands::cc_float::syntax(vostok::console_commands::cc_float *this, char (*dest)[512])
{
  vostok::sprintf<512>(dest, (const char *)&stru_95AF78.m_key_bindings[13], this->m_min, this->m_max);
}
