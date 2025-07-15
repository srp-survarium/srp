const char *__usercall vostok::console_commands::cc_token::find_name@<eax>(
        vostok::console_commands::cc_token *this@<ecx>,
        unsigned int id@<edi>)
{
  unsigned int m_num_commands; // edx
  int v3; // eax
  const vostok::console_commands::command_token *m_commands; // esi
  const vostok::console_commands::command_token *i; // ecx

  m_num_commands = this->m_num_commands;
  v3 = 0;
  if ( !m_num_commands )
    return 0;
  m_commands = this->m_commands;
  for ( i = m_commands; i->id != id; ++i )
  {
    if ( ++v3 >= m_num_commands )
      return 0;
  }
  return m_commands[v3].name;
}
