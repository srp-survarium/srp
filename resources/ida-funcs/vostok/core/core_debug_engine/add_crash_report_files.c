void __thiscall vostok::core::core_debug_engine::add_crash_report_files(
        vostok::core::core_debug_engine *this,
        const _SYSTEMTIME *date_time,
        const char *report_id,
        boost::function<void __cdecl(char const *)> *add_file_callback)
{
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v5; // ecx
  vostok::journaling::journal *v6; // ecx
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v7; // ecx
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> in_file_name[5]; // [esp+10h] [ebp-210h] BYREF
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> a0; // [esp+118h] [ebp-108h] BYREF

  if ( vostok::core::g_log_file )
  {
    this->generate_debug_file_name(this, (char (*)[260])in_file_name, date_time, report_id, ".log");
    vostok::logging::log_file::flush((vostok::logging::log_file *)in_file_name);
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      v5,
      add_file_callback,
      in_file_name);
  }
  if ( vostok::core::g_journal.m_initialized )
  {
    this->generate_debug_file_name(this, (char (*)[260])&a0, date_time, report_id, ".journal");
    vostok::journaling::journal::flush(v6, (const char *const)vostok::core::g_journal.m_variable, (char *)&a0);
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(v7, add_file_callback, &a0);
  }
}
