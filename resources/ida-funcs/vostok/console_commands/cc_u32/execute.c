void __thiscall vostok::console_commands::cc_u32::execute(vostok::console_commands::cc_u32 *this, char *args)
{
  vostok::console_commands::console_command *v3; // ecx
  vostok::console_commands::console_command *m_value; // ecx
  unsigned int m_min; // [esp+4h] [ebp-4h] BYREF

  if ( sscanf_s(args, "%d", &m_min) == 1 && m_min >= this->m_min && m_min <= this->m_max )
  {
    m_value = (vostok::console_commands::console_command *)this->m_value;
    m_value->__vftable = (vostok::console_commands::console_command_vtbl *)m_min;
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
    m_value,
    (int)this,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)args);
}
