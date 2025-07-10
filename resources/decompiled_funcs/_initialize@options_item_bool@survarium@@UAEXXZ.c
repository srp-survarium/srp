void __thiscall survarium::options_item_bool::initialize(survarium::options_item_bool *this)
{
  vostok::console_commands::console_command *m_console_command; // eax
  char m_source_value; // dl

  m_console_command = this->m_console_command;
  if ( m_console_command )
  {
    m_source_value = (char)m_console_command[1].~vostok::console_commands::console_command;
    this->m_source_value = m_source_value;
  }
  else
  {
    this->m_source_value = 0;
    m_source_value = this->m_source_value;
  }
  this->m_current_value = m_source_value;
}
