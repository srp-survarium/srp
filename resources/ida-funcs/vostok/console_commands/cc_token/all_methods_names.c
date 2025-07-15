void __userpurge vostok::console_commands::cc_token::all_methods_names(
        char *names@<eax>,
        const char *a2@<esi>,
        vostok::console_commands::cc_token *this)
{
  unsigned int m_num_commands; // ebp
  unsigned int v5; // ebx
  const char *v6; // [esp-4h] [ebp-44h]
  vostok::strings::detail::tuples v7; // [esp+Ch] [ebp-34h] BYREF

  *names = 0;
  m_num_commands = this->m_num_commands;
  v5 = 0;
  if ( m_num_commands )
  {
    v6 = a2;
    do
    {
      vostok::strings::detail::tuples::tuples(&v7, names, this->m_commands[v5].name, v6);
      vostok::strings::detail::tuples::concat(names, &v7);
      ++v5;
    }
    while ( v5 < m_num_commands );
  }
}
