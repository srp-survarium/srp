void __usercall vostok::command_line::key::protected_construct(
        vostok::command_line::key *this@<ecx>,
        vostok::command_line::key *a2@<edi>)
{
  unsigned __int8 *i; // esi
  unsigned __int8 *j; // esi
  vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy> *v4; // esi
  _RTL_CRITICAL_SECTION *v5; // ebp

  for ( i = (unsigned __int8 *)a2->m_short_name; *i && !vostok::command_line::is_delimiter(*i, " \t=-"); ++i )
    ;
  for ( j = (unsigned __int8 *)a2->m_full_name; *j && !vostok::command_line::is_delimiter(*j, " \t=-"); ++j )
    ;
  if ( !s_command_line_keys )
  {
    if ( _InterlockedExchange((volatile __int32 *)&s_command_line_keys_creation, 1) )
    {
      while ( !s_command_line_keys )
        ;
    }
    else
    {
      *(_DWORD *)s_command_line_keys_buffer = 0;
      vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
        &s_command_line_keys_creation,
        (_RTL_CRITICAL_SECTION *)&s_command_line_keys_buffer[8]);
      *(_DWORD *)&s_command_line_keys_buffer[36] = 0;
      *(_DWORD *)&s_command_line_keys_buffer[40] = 0;
      _InterlockedExchange((volatile __int32 *)&s_command_line_keys, (__int32)s_command_line_keys_buffer);
    }
  }
  v4 = s_command_line_keys;
  a2->m_next_key = 0;
  if ( v4 )
    v5 = (_RTL_CRITICAL_SECTION *)&v4->vostok::threading::mutex_tasks_unaware;
  else
    v5 = 0;
  EnterCriticalSection(v5);
  ++v4->m_size;
  if ( v4->m_first )
    v4->m_last->m_next_key = a2;
  else
    v4->m_first = a2;
  v4->m_last = a2;
  LeaveCriticalSection(v5);
  ++HIDWORD(s_command_line_keys_creation.m_mutex[0]);
}
