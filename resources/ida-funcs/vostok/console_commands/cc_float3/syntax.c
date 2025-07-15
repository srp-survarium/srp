void __thiscall vostok::console_commands::cc_float3::syntax(
        vostok::console_commands::cc_float3 *this,
        char (*dest)[512])
{
  vostok::sprintf<512>(
    dest,
    "range [%3.3f,%3.3f,%3.3f]-[%3.3f,%3.3f,%3.3f]",
    this->m_min.x,
    this->m_min.y,
    this->m_min.z,
    this->m_max.x,
    this->m_max.y,
    this->m_max.z);
}
