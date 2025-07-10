void __thiscall vostok::console_commands::cc_token::status(vostok::console_commands::cc_token *this, char (*dest)[512])
{
  unsigned int m_num_commands; // edx
  int v3; // eax
  const vostok::console_commands::command_token *m_commands; // esi
  unsigned int v5; // edi
  const vostok::console_commands::command_token *i; // ecx
  const char *name; // eax

  m_num_commands = this->m_num_commands;
  v3 = 0;
  if ( m_num_commands )
  {
    m_commands = this->m_commands;
    v5 = *this->m_value;
    for ( i = m_commands; i->id != v5; ++i )
    {
      if ( ++v3 >= m_num_commands )
        return;
    }
    name = m_commands[v3].name;
    if ( name )
      strcpy_s((char *)dest, 0x200u, name);
  }
}
