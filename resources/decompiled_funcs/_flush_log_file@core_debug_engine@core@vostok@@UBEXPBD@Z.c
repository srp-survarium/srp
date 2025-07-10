void __thiscall vostok::core::core_debug_engine::flush_log_file(vostok::core::core_debug_engine *this, char *file_name)
{
  if ( vostok::core::g_log_file )
  {
    vostok::logging::log_file::flush(vostok::core::g_log_file, 0);
    if ( file_name )
      vostok::logging::log_file::flush(vostok::core::g_log_file, file_name);
    if ( s_engine_0 )
      s_engine_0->on_crash(s_engine_0);
  }
}
