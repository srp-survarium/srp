vostok::console_commands::console_command *__usercall vostok::console_commands::find@<eax>(const char *str@<esi>)
{
  vostok::console_commands::console_command *result; // eax

  for ( result = vostok::console_commands::s_console_command_root; result; result = result->m_prev )
  {
    if ( !strcmp(result->m_name, str) )
      break;
  }
  return result;
}
