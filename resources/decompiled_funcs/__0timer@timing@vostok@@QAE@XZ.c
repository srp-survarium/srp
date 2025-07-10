void __thiscall vostok::timing::timer::timer(vostok::timing::timer *this)
{
  unsigned __int64 QuadPart; // rax
  const vostok::math::float4x4 *v3; // xmm0_4
  LARGE_INTEGER PerformanceCount; // [esp+4h] [ebp-8h] BYREF

  this->m_current_time = 0;
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    QuadPart = PerformanceCount.QuadPart;
  }
  v3 = clear_value;
  this->m_start_time = QuadPart;
  LODWORD(this->m_time_factor) = v3;
  LODWORD(this->m_backup_time_factor) = v3;
}
