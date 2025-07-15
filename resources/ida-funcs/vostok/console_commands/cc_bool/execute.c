void __thiscall vostok::console_commands::cc_bool::execute(vostok::console_commands::cc_bool *this, char *args)
{
  vostok::console_commands::console_command *v3; // ecx

  if ( vostok::console_commands::bool_from_string(args, this->m_value) )
    vostok::console_commands::console_command::on_invalid_syntax(
      v3,
      (void (__thiscall ***)(const char **, char *))this,
      args);
  else
    vostok::console_commands::console_command::on_changed(
      v3,
      (int)this,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)args);
}
