void __usercall vostok::timing::timer::start(vostok::timing::timer *this@<ecx>, LARGE_INTEGER *a2@<esi>)
{
  LARGE_INTEGER v2; // rax
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    v2.QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    v2 = PerformanceCount;
  }
  a2[1] = v2;
  a2->LowPart = 0;
  a2->HighPart = 0;
}
