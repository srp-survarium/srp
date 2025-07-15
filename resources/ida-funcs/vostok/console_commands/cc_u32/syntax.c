void __thiscall vostok::console_commands::cc_u32::syntax(vostok::console_commands::cc_u32 *this, char (*dest)[512])
{
  vostok::sprintf<512>(dest, "range [%d,%d]", this->m_min, this->m_max);
}
