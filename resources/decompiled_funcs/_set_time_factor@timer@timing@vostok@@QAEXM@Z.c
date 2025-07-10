void __thiscall vostok::timing::timer::set_time_factor(vostok::timing::timer *this, float time_factor)
{
  unsigned __int64 QuadPart; // rax
  LARGE_INTEGER PerformanceCount; // [esp+4h] [ebp-8h] BYREF

  this->m_current_time = vostok::timing::timer::get_elapsed_ticks(this);
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    QuadPart = PerformanceCount.QuadPart;
  }
  this->m_start_time = QuadPart;
  this->m_time_factor = time_factor;
}
