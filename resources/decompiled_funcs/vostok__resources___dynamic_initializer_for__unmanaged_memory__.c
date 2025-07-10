int vostok::resources::_dynamic_initializer_for__unmanaged_memory__()
{
  unsigned __int64 QuadPart; // rax
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

  InitializeCriticalSectionAndSpinCount(
    (LPCRITICAL_SECTION)&vostok::resources::unmanaged_memory.queue.vostok::threading::mutex,
    0x2710u);
  vostok::resources::unmanaged_memory.queue.m_first = 0;
  vostok::resources::unmanaged_memory.queue.m_last = 0;
  vostok::resources::unmanaged_memory.listen_type = listen_none;
  vostok::resources::unmanaged_memory.listen_all_timer.m_current_time = 0;
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    QuadPart = PerformanceCount.QuadPart;
  }
  vostok::resources::unmanaged_memory.listen_all_timer.m_start_time = QuadPart;
  LODWORD(vostok::resources::unmanaged_memory.listen_all_timer.m_time_factor) = clear_value;
  LODWORD(vostok::resources::unmanaged_memory.listen_all_timer.m_backup_time_factor) = clear_value;
  return atexit(vostok::resources::_dynamic_atexit_destructor_for__unmanaged_memory__);
}
