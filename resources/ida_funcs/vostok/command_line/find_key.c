vostok::command_line::key *__fastcall vostok::command_line::find_key(char *key_name)
{
  char *m_buffer; // eax
  vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::command_line::command_line_key_finder> pred; // [esp+4h] [ebp-218h] BYREF
  vostok::command_line::command_line_key_finder finder; // [esp+8h] [ebp-214h] BYREF

  finder.key_name.m_max_end = (char *)&finder.result;
  m_buffer = finder.key_name.m_buffer;
  finder.key_name.m_begin = finder.key_name.m_buffer;
  finder.key_name.m_end = finder.key_name.m_buffer;
  finder.key_name.m_buffer[0] = 0;
  if ( key_name )
  {
    for ( ; *key_name; ++finder.key_name.m_end )
    {
      if ( m_buffer >= finder.key_name.m_max_end )
        break;
      *m_buffer = *key_name;
      m_buffer = finder.key_name.m_end + 1;
      ++key_name;
    }
    *m_buffer = 0;
  }
  pred.m_predicate_ref = &finder;
  finder.result = 0;
  vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::command_line::command_line_key_finder>>(
    (vostok::intrusive_list<vostok::command_line::key,vostok::command_line::key *,552,vostok::threading::mutex_tasks_unaware,vostok::size_policy,vostok::no_debug_policy> *)&pred,
    (int)s_command_line_keys,
    &pred);
  return finder.result;
}
