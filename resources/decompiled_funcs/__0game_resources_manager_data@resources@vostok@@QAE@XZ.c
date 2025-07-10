void __usercall vostok::resources::game_resources_manager_data::game_resources_manager_data(
        vostok::resources::game_resources_manager_data *this@<ecx>,
        int a2@<esi>)
{
  unsigned __int64 v2; // rax
  LARGE_INTEGER PerformanceCount; // [esp+8h] [ebp-8h] BYREF

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 8) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 16), 0x2710u);
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 60) = a2 + 56;
  *(_DWORD *)(a2 + 64) = a2 + 56;
  *(_DWORD *)(a2 + 68) = 0;
  *(_DWORD *)(a2 + 72) = 1;
  *(_DWORD *)(a2 + 76) = 0;
  vostok::timing::timer::timer((vostok::timing::timer *)(a2 + 80));
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    v2 = __rdtsc();
    *(_DWORD *)(a2 + 88) = v2;
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    HIDWORD(v2) = PerformanceCount.HighPart;
    *(_DWORD *)(a2 + 88) = PerformanceCount.LowPart;
  }
  *(_DWORD *)(a2 + 80) = 0;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 92) = HIDWORD(v2);
}
