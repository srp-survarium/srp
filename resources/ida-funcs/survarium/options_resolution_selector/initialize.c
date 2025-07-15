void __thiscall survarium::options_resolution_selector::initialize(survarium::options_resolution_selector *this)
{
  vostok::console_commands::console_command_vtbl *v2; // ebp
  unsigned __int8 v3; // bl
  const char **m_values; // edi

  v2 = this->m_console_command[1].__vftable;
  v3 = 0;
  if ( this->m_values_count )
  {
    m_values = this->m_values;
    while ( vostok::strings::compare((const char *)v2, m_values[v3]) )
    {
      if ( ++v3 >= this->m_values_count )
        goto LABEL_7;
    }
    this->m_source_value = v3;
  }
LABEL_7:
  this->m_current_value = this->m_source_value;
}
