unsigned __int64 dynamic_initializer_for__vostok::resources::quality_increase_functionality::s_tick_timer__()
{
  unsigned __int64 result; // rax
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    result = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    result = PerformanceCount.QuadPart;
  }
  vostok::resources::quality_increase_functionality::s_tick_timer.m_start_time = result;
  LODWORD(vostok::resources::quality_increase_functionality::s_tick_timer.m_time_factor) = clear_value;
  LODWORD(vostok::resources::quality_increase_functionality::s_tick_timer.m_backup_time_factor) = clear_value;
  return result;
}
