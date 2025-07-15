void __thiscall vostok::core::core_debug_engine::on_runtime_error(vostok::core::core_debug_engine *this)
{
  vostok::journaling::journal *v1; // ecx

  if ( vostok::core::g_log_file )
    vostok::logging::log_file::flush(0);
  if ( vostok::core::g_journal.m_initialized && vostok::core::journal_usage() == record_journal )
    vostok::journaling::journal::flush(v1, (const char *const)vostok::core::g_journal.m_variable, 0);
  if ( s_engine_0 )
    s_engine_0->on_crash(s_engine_0);
}
