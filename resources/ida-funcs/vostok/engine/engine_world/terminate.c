void __thiscall __noreturn vostok::engine::engine_world::terminate(vostok::engine::engine_world *this, int exit_code)
{
  vostok::journaling::journal *v2; // ecx

  if ( vostok::core::g_log_file )
    vostok::logging::log_file::flush(0);
  if ( vostok::core::journal_usage() == record_journal )
    vostok::journaling::flush(v2);
  vostok::debug::terminate(exit_code - 100000, (char *)uri);
}
