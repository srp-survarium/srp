void __cdecl vostok::memory::monitor::on_alloc(
        void **allocation_address,
        unsigned int *allocation_size,
        const char *previous_size)
{
  vostok::command_line::key *v3; // ecx
  vostok::threading::mutex *v4; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *p_m_device; // esi
  vostok::fs_new::device_file_system_no_watcher_proxy *v6; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *v7; // ecx
  unsigned int v8; // kr00_4
  vostok::fs_new::device_file_system_no_watcher_proxy *v9; // ecx
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  if ( vostok::memory::monitor::enabled(v3) && s_initialized_2 )
  {
    vostok::threading::mutex::lock(v4, (_RTL_CRITICAL_SECTION *)s_mutex.m_variable);
    v10 = (2 * *allocation_size) | 1;
    p_m_device = &s_core_synchronous_device.m_variable->m_device;
    vostok::fs_new::device_file_system_no_watcher_proxy::write(
      v6,
      &s_core_synchronous_device.m_variable->m_device.m_device_file_system,
      s_file,
      &v10,
      4u);
    vostok::fs_new::device_file_system_no_watcher_proxy::write(v7, p_m_device, s_file, allocation_address, 4u);
    v8 = strlen(previous_size);
    vostok::fs_new::device_file_system_no_watcher_proxy::write(v9, p_m_device, s_file, previous_size, v8 + 1);
    if ( flush )
      p_m_device->m_device_file_system->flush(p_m_device->m_device_file_system, s_file);
    LeaveCriticalSection((LPCRITICAL_SECTION)s_mutex.m_variable);
  }
}
