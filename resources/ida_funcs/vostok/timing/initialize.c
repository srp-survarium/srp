void __cdecl vostok::timing::initialize()
{
  timeBeginPeriod(1u);
  __FUnloadDelayLoadedDLL2("winmm.dll");
  QueryPerformanceFrequency(&vostok::timing::g_qpc_per_second);
  vostok::timing::g_cpu_supports_time_stamp = 0;
}
