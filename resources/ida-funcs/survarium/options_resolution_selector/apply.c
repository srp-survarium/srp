void __thiscall survarium::options_resolution_selector::apply(survarium::options_resolution_selector *this)
{
  unsigned __int8 m_current_value; // dl
  vostok::console_commands::console_command *m_console_command; // ecx

  m_current_value = this->m_current_value;
  m_console_command = this->m_console_command;
  this->m_source_value = m_current_value;
  m_console_command->execute(m_console_command, this->m_values[m_current_value]);
}
