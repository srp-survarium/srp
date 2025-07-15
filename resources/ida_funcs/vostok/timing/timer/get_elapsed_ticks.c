unsigned __int64 __thiscall vostok::timing::timer::get_elapsed_ticks(vostok::timing::timer *this)
{
  LARGE_INTEGER v2; // rax
  unsigned __int64 v3; // rax
  LARGE_INTEGER PerformanceCount; // [esp+4h] [ebp-8h] BYREF

  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    v2.QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    v2 = PerformanceCount;
  }
  v3 = v2.QuadPart - this->m_start_time;
  PerformanceCount.QuadPart = v3 & 0x8000000000000000uLL;
  return this->m_current_time + (unsigned __int64)((double)v3 * this->m_time_factor);
}
