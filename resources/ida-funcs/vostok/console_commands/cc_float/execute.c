void __thiscall vostok::console_commands::cc_float::execute(vostok::console_commands::cc_float *this, char *args)
{
  vostok::console_commands::console_command *v3; // ecx
  float m_min; // [esp+4h] [ebp-4h] BYREF

  if ( sscanf_s(args, "%f", &m_min) == 1 && this->m_min <= m_min && m_min <= this->m_max )
  {
    *this->m_value = m_min;
  }
  else
  {
    vostok::console_commands::console_command::on_invalid_syntax(
      v3,
      (void (__thiscall ***)(const char **, char *))this,
      args);
    m_min = this->m_min;
  }
  vostok::console_commands::console_command::on_changed(
    v3,
    (int)this,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)args);
}
