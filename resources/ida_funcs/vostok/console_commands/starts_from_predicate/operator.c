bool __thiscall vostok::console_commands::starts_from_predicate::operator()(
        vostok::console_commands::starts_from_predicate *this,
        const vostok::console_commands::starts_from_predicate *left,
        vostok::console_commands::console_command *const right,
        vostok::console_commands::console_command *righta)
{
  unsigned __int8 *m_name; // edi
  int v5; // eax
  unsigned int v6; // esi
  unsigned __int8 *v7; // edi
  int v8; // eax
  unsigned int v9; // eax
  int v11; // kr00_4

  m_name = (unsigned __int8 *)right->m_name;
  strstr(m_name, (unsigned __int8 *)left->starts_from);
  v6 = v5 - (_DWORD)m_name;
  v7 = (unsigned __int8 *)righta->m_name;
  strstr(v7, (unsigned __int8 *)left->starts_from);
  v9 = v8 - (_DWORD)v7;
  if ( v6 < v9 )
    return 1;
  if ( v6 > v9 )
    return 0;
  v11 = strcmp(right->m_name, righta->m_name);
  return v11 && -(v11 < 0) - ((v11 < 0) - 1) < 0;
}
