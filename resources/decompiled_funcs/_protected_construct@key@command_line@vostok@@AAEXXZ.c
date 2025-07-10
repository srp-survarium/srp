void __thiscall vostok::command_line::key::protected_construct(
        vostok::command_line::key *this,
        vostok::command_line::key *thisa)
{
  unsigned __int8 *m_short_name; // esi
  unsigned __int8 i; // al
  int v4; // eax
  unsigned __int8 *m_full_name; // esi
  unsigned __int8 j; // al
  int v7; // eax
  vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy> *v8; // esi
  _RTL_CRITICAL_SECTION *v9; // edi

  m_short_name = (unsigned __int8 *)thisa->m_short_name;
  for ( i = *m_short_name; i; i = *++m_short_name )
  {
    strchr(" \t=-", i);
    if ( v4 )
      break;
  }
  m_full_name = (unsigned __int8 *)thisa->m_full_name;
  for ( j = *m_full_name; j; j = *++m_full_name )
  {
    strchr(" \t=-", j);
    if ( v7 )
      break;
  }
  v8 = s_command_line_keys;
  if ( !s_command_line_keys )
  {
    if ( _InterlockedExchange(&s_command_line_keys_creation, 1) )
    {
      v8 = s_command_line_keys;
      while ( !s_command_line_keys )
        ;
    }
    else
    {
      *(_DWORD *)s_command_line_keys_buffer = 0;
      InitializeCriticalSectionAndSpinCount(&stru_4AAF220, 0x2710u);
      dword_4AAF23C = 0;
      dword_4AAF240 = 0;
      _InterlockedExchange((volatile __int32 *)&s_command_line_keys, (__int32)s_command_line_keys_buffer);
      v8 = s_command_line_keys;
    }
  }
  thisa->m_next_key = 0;
  if ( v8 )
    v9 = (_RTL_CRITICAL_SECTION *)&v8->vostok::threading::mutex_tasks_unaware;
  else
    v9 = 0;
  EnterCriticalSection(v9);
  ++v8->m_size;
  if ( v8->m_first )
    v8->m_last->m_next_key = thisa;
  else
    v8->m_first = thisa;
  v8->m_last = thisa;
  LeaveCriticalSection(v9);
  ++s_command_line_keys_count;
}
