void __cdecl Scaleform::Timer::shutdownTimerSystem()
{
  DeleteCriticalSection(&Scaleform::WinAPI_GetTimeCS);
  timeEndPeriod(1u);
}
