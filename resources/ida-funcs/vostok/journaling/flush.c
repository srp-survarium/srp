void __thiscall vostok::journaling::flush(vostok::journaling::journal *this)
{
  if ( vostok::core::g_journal.m_initialized )
    vostok::journaling::journal::flush(this, (const char *const)vostok::core::g_journal.m_variable, 0);
}
