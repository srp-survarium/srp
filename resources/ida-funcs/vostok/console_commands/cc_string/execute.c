void __thiscall vostok::console_commands::cc_string::execute(vostok::console_commands::cc_string *this, char *args)
{
  vostok::console_commands::console_command *v3; // ecx

  vostok::strings::copy_n(this->m_value, this->m_size, args, this->m_size);
  vostok::console_commands::console_command::on_changed(
    v3,
    (int)this,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)args);
}
