void __thiscall vostok::memory::monitor::finalize(vostok::command_line::key *this)
{
  if ( vostok::memory::monitor::enabled(this) && s_initialized_2 )
  {
    DeleteCriticalSection((LPCRITICAL_SECTION)s_mutex.m_variable);
    s_mutex.m_initialized = 0;
    s_core_synchronous_device.m_variable->m_device.m_device_file_system->close(
      s_core_synchronous_device.m_variable->m_device.m_device_file_system,
      s_file);
    s_file = 0;
    s_initialized_2 = 0;
  }
}
