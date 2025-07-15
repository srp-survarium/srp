bool __usercall vostok::command_line::key_compare_predicate::operator()@<al>(
        const vostok::command_line::key *const left@<esi>,
        const vostok::command_line::key *const right@<edi>,
        vostok::command_line::key_compare_predicate *this)
{
  int v3; // eax
  const char *m_short_name; // eax
  const char *m_full_name; // ecx

  v3 = vostok::strings::compare(left->m_category, right->m_category);
  if ( !v3 )
  {
    m_short_name = left->m_short_name;
    if ( !*m_short_name )
      m_short_name = left->m_full_name;
    m_full_name = right->m_short_name;
    if ( !*m_full_name )
      m_full_name = right->m_full_name;
    v3 = vostok::strings::compare(m_short_name, m_full_name);
  }
  return v3 < 0;
}
