void __thiscall survarium::options_item_float::initialize(survarium::options_item_float *this)
{
  vostok::console_commands::console_command *m_console_command; // eax

  m_console_command = this->m_console_command;
  if ( m_console_command )
    this->m_source_value = *(float *)&m_console_command[1].~vostok::console_commands::console_command;
  else
    this->m_source_value = 0.0;
  this->m_current_value = this->m_source_value;
}
