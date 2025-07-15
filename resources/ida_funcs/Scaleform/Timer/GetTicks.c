unsigned __int64 __stdcall Scaleform::Timer::GetTicks()
{
  DWORD Time; // eax
  DWORD v1; // ebx
  volatile unsigned int v2; // edi

  EnterCriticalSection(&Scaleform::WinAPI_GetTimeCS);
  Time = timeGetTime();
  if ( TimerOverrideInstance )
    Time = TimerOverrideInstance->GetTicksMs(TimerOverrideInstance, Time);
  v1 = Time;
  if ( Scaleform::WinAPI_OldTime > Time )
    ++Scaleform::WinAPI_WrapCounter;
  Scaleform::WinAPI_OldTime = Time;
  v2 = Scaleform::WinAPI_WrapCounter;
  LeaveCriticalSection(&Scaleform::WinAPI_GetTimeCS);
  return 1000 * __PAIR64__(v2, v1);
}
