vostok::journaling::journal_usage_enum __cdecl vostok::core::journal_usage()
{
  if ( vostok::core::g_journal.m_initialized )
    return vostok::core::g_journal.m_variable->m_usage;
  else
    return 0;
}
