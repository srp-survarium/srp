void __usercall vostok::memory::monitor::on_free(
        void **deallocation_address@<edi>,
        vostok::command_line::key *a2@<ecx>)
{
  vostok::threading::mutex *v2; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *v3; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *p_m_device; // esi
  vostok::fs_new::device_file_system_no_watcher_proxy *v5; // ecx
  int v6; // [esp+Ch] [ebp-4h] BYREF

  if ( vostok::memory::monitor::enabled(a2) && s_initialized_2 )
  {
    vostok::threading::mutex::lock(v2, (_RTL_CRITICAL_SECTION *)s_mutex.m_variable);
    if ( *deallocation_address )
    {
      p_m_device = &s_core_synchronous_device.m_variable->m_device;
      v6 = 0;
      vostok::fs_new::device_file_system_no_watcher_proxy::write(
        v3,
        &s_core_synchronous_device.m_variable->m_device.m_device_file_system,
        s_file,
        &v6,
        4u);
      vostok::fs_new::device_file_system_no_watcher_proxy::write(v5, p_m_device, s_file, deallocation_address, 4u);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)s_mutex.m_variable);
  }
}
