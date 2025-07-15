unsigned __int64 __stdcall Scaleform::Timer::GetProfileTicks()
{
  Scaleform::Timer::TimerOverride *v0; // ecx
  __int64 v1; // rax
  LARGE_INTEGER v2; // kr00_8
  int HighPart; // edi
  unsigned int LowPart; // esi
  __int64 v5; // kr20_8
  LARGE_INTEGER PerformanceCount; // [esp+10h] [ebp-10h] BYREF
  LARGE_INTEGER Frequency; // [esp+18h] [ebp-8h] BYREF

  QueryPerformanceCounter(&PerformanceCount);
  v0 = TimerOverrideInstance;
  if ( TimerOverrideInstance )
  {
    v1 = ((__int64 (__thiscall *)(Scaleform::Timer::TimerOverride *, unsigned int, int))TimerOverrideInstance->GetRawTicks)(
           TimerOverrideInstance,
           PerformanceCount.LowPart,
           PerformanceCount.HighPart);
    v0 = TimerOverrideInstance;
    v2.QuadPart = v1;
  }
  else
  {
    v2 = PerformanceCount;
  }
  HighPart = HIDWORD(perfFreq);
  LowPart = perfFreq;
  if ( !perfFreq )
  {
    QueryPerformanceFrequency(&Frequency);
    HighPart = Frequency.HighPart;
    LowPart = Frequency.LowPart;
    v0 = TimerOverrideInstance;
    perfFreq = Frequency.QuadPart;
  }
  if ( v0 )
  {
    v5 = ((__int64 (__thiscall *)(Scaleform::Timer::TimerOverride *, unsigned int, int))v0->GetRawFrequency)(
           v0,
           LowPart,
           HighPart);
    HighPart = HIDWORD(v5);
    LowPart = v5;
  }
  return v2.QuadPart * (unsigned __int64)(unsigned int)&loc_F4240 / __PAIR64__(HighPart, LowPart);
}
