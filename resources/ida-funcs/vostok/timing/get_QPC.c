LARGE_INTEGER __cdecl vostok::timing::get_QPC()
{
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

  if ( BYTE3(s_command_line_keys_creation.m_mutex[1]) )
  {
    return (LARGE_INTEGER)__rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    return PerformanceCount;
  }
}
