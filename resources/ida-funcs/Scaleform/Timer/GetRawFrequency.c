unsigned int __stdcall Scaleform::Timer::GetRawFrequency()
{
  LARGE_INTEGER v0; // rax
  LARGE_INTEGER Frequency; // [esp+0h] [ebp-8h] BYREF

  v0.QuadPart = perfFreq;
  if ( !perfFreq )
  {
    QueryPerformanceFrequency(&Frequency);
    v0 = Frequency;
    perfFreq = Frequency.QuadPart;
  }
  if ( TimerOverrideInstance )
    v0.LowPart = ((int (__thiscall *)(Scaleform::Timer::TimerOverride *, unsigned int, int))TimerOverrideInstance->GetRawFrequency)(
                   TimerOverrideInstance,
                   v0.LowPart,
                   v0.HighPart);
  return v0.LowPart;
}
