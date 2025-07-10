void __thiscall survarium::options_resolution_selector::initialize(survarium::options_resolution_selector *this)
{
  vostok::console_commands::console_command *m_console_command; // eax
  unsigned __int8 v3; // cl
  const char *v4; // edi

  m_console_command = this->m_console_command;
  v3 = 0;
  v4 = (const char *)m_console_command[1].__vftable;
  if ( this->m_values_count )
  {
    while ( strcmp(v4, this->m_values[v3]) )
    {
      if ( ++v3 >= this->m_values_count )
      {
        this->m_current_value = this->m_source_value;
        return;
      }
    }
    this->m_source_value = v3;
    this->m_current_value = v3;
  }
  else
  {
    this->m_current_value = this->m_source_value;
  }
}
