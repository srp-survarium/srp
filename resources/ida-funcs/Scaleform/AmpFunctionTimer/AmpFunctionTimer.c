void __thiscall Scaleform::AmpFunctionTimer::AmpFunctionTimer(
        Scaleform::AmpFunctionTimer *this,
        Scaleform::AmpStats *ampStats,
        const char *functionName,
        Scaleform::AmpProfileLevel profileLevel,
        Scaleform::AmpNativeFunctionId functionId)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v7; // eax
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats *Stats; // ecx
  int StartTicks; // [esp-8h] [ebp-Ch]

  this->StartTicks = 0;
  this->Stats = ampStats;
  Instance = Scaleform::AmpServer::GetInstance();
  if ( !Instance->IsProfiling(Instance)
    || (v7 = Scaleform::AmpServer::GetInstance(), v7->GetProfileLevel(v7) < profileLevel) )
  {
    this->Stats = 0;
  }
  if ( this->Stats )
  {
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    Stats = this->Stats;
    LODWORD(this->StartTicks) = ProfileTicks;
    StartTicks = this->StartTicks;
    HIDWORD(this->StartTicks) = HIDWORD(ProfileTicks);
    ((void (__thiscall *)(Scaleform::AmpStats *, const char *, Scaleform::AmpNativeFunctionId, int, _DWORD))Stats->NativePushCallstack)(
      Stats,
      functionName,
      functionId,
      StartTicks,
      HIDWORD(ProfileTicks));
  }
}
