void __thiscall vostok::console_commands::cc_float2::syntax(
        vostok::console_commands::cc_float2 *this,
        char (*dest)[512])
{
  vostok::sprintf<512>(
    dest,
    (const char *)&stru_95AF78.m_key_bindings[21],
    this->m_min.x,
    this->m_min.y,
    this->m_max.x,
    this->m_max.y);
}
