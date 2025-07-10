BOOL __cdecl vostok::core::is_logging_initialized()
{
  return vostok::core::g_log_filter_tree != 0;
}
