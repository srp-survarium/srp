void __usercall vostok::timing::timer::resume(vostok::timing::timer *this@<ecx>, int a2@<esi>)
{
  int v2; // [esp+0h] [ebp-Ch]
  LARGE_INTEGER PerformanceCount; // [esp+4h] [ebp-8h] BYREF

  v2 = *(_DWORD *)(a2 + 20);
  *(_QWORD *)a2 = vostok::timing::timer::get_elapsed_ticks((vostok::timing::timer *)a2);
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    *(_QWORD *)(a2 + 8) = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    *(LARGE_INTEGER *)(a2 + 8) = PerformanceCount;
  }
  *(_DWORD *)(a2 + 16) = v2;
}
