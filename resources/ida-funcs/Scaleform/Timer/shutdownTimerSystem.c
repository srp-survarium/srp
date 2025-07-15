MMRESULT Scaleform::Timer::shutdownTimerSystem()
{
  DeleteCriticalSection(&Scaleform::WinAPI_GetTimeCS);
  return timeEndPeriod(1u);
}
