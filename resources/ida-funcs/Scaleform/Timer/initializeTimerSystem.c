void Scaleform::Timer::initializeTimerSystem()
{
  timeBeginPeriod(1u);
  InitializeCriticalSection(&Scaleform::WinAPI_GetTimeCS);
}
