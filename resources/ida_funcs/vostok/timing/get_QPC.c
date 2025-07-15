LARGE_INTEGER __cdecl vostok::timing::get_QPC()
{
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    return (LARGE_INTEGER)__rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    return PerformanceCount;
  }
}
