DWORD __stdcall Scaleform::Timer::GetTicksMs()
{
  DWORD result; // eax

  result = timeGetTime();
  if ( TimerOverrideInstance )
    return TimerOverrideInstance->GetTicksMs(TimerOverrideInstance, result);
  return result;
}
