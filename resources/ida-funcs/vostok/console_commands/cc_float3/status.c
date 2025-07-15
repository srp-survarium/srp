void __thiscall vostok::console_commands::cc_float3::status(
        vostok::console_commands::cc_float3 *this,
        char (*dest)[512])
{
  vostok::sprintf<512>(dest, "%3.5f,%3.5f,%3.5f", this->m_value->x, this->m_value->y, this->m_value->z);
}
