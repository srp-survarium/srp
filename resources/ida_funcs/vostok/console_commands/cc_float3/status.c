void __thiscall vostok::console_commands::cc_float3::status(
        vostok::console_commands::cc_float3 *this,
        char (*dest)[512])
{
  vostok::sprintf<512>(
    dest,
    (const char *)&stru_95AF78.m_key_bindings[25],
    this->m_value->x,
    this->m_value->y,
    this->m_value->z);
}
