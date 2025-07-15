void __thiscall vostok::core::core_debug_engine::on_terminate(vostok::core::core_debug_engine *this)
{
  if ( vostok::core::g_log_file )
    vostok::logging::log_file::close((vostok::logging::log_file *)this);
}
