void __usercall vostok::resources::quality_increase_functionality::quality_increase_functionality(
        vostok::resources::quality_increase_functionality *this@<esi>,
        vostok::resources::game_resources_manager_data *data@<eax>)
{
  bool v2; // zf
  unsigned __int64 QuadPart; // rax
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

  v2 = !vostok::resources::quality_increase_functionality::s_started_tick_timer;
  this->m_data = data;
  if ( v2 )
  {
    vostok::resources::quality_increase_functionality::s_started_tick_timer = 1;
    if ( vostok::timing::g_cpu_supports_time_stamp )
    {
      QuadPart = __rdtsc();
    }
    else
    {
      QueryPerformanceCounter(&PerformanceCount);
      QuadPart = PerformanceCount.QuadPart;
    }
    vostok::resources::quality_increase_functionality::s_tick_timer.m_start_time = QuadPart;
    vostok::resources::quality_increase_functionality::s_tick_timer.m_current_time = 0;
  }
}
