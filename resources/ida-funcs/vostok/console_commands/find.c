vostok::console_commands::console_command *__cdecl vostok::console_commands::find(char *str)
{
  vostok::console_commands::console_command *i; // esi

  for ( i = vostok::console_commands::s_console_command_root; i && vostok::strings::compare(i->m_name, str); i = i->m_prev )
    ;
  return i;
}
