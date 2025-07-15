void __thiscall vostok::console_commands::cc_float::syntax(vostok::console_commands::cc_float *this, char (*dest)[512])
{
  vostok::sprintf<512>(dest, "range [%3.3f,%3.3f]", this->m_min, this->m_max);
}
