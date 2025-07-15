unsigned int __stdcall Scaleform::Timer::GetRawTicks()
{
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

  QueryPerformanceCounter(&PerformanceCount);
  if ( TimerOverrideInstance )
    return ((int (__thiscall *)(Scaleform::Timer::TimerOverride *, unsigned int, int))TimerOverrideInstance->GetRawTicks)(
             TimerOverrideInstance,
             PerformanceCount.LowPart,
             PerformanceCount.HighPart);
  else
    return PerformanceCount.LowPart;
}
