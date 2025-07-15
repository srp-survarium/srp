bool __userpurge vostok::console_commands::starts_from_predicate::operator()@<al>(
        vostok::console_commands::starts_from_predicate *this@<ecx>,
        unsigned __int8 **a2@<edi>,
        vostok::console_commands::console_command *const left,
        vostok::console_commands::console_command *const right)
{
  unsigned __int8 *m_name; // ebx
  int v5; // eax
  unsigned int v6; // esi
  unsigned __int8 *v7; // ebx
  int v8; // eax
  unsigned int v9; // eax

  m_name = (unsigned __int8 *)left->m_name;
  strstr(m_name, *a2);
  v6 = v5 - (_DWORD)m_name;
  v7 = (unsigned __int8 *)right->m_name;
  strstr(v7, *a2);
  v9 = v8 - (_DWORD)v7;
  if ( v6 < v9 )
    return 1;
  if ( v6 <= v9 )
    return vostok::strings::compare(left->m_name, right->m_name) < 0;
  return 0;
}
