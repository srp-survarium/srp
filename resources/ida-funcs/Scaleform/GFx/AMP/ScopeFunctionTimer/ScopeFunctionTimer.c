void __thiscall Scaleform::GFx::AMP::ScopeFunctionTimer::ScopeFunctionTimer(
        Scaleform::GFx::AMP::ScopeFunctionTimer *this,
        Scaleform::GFx::AMP::ViewStats *viewStats,
        unsigned int swdHandle,
        unsigned int pc,
        Scaleform::AmpProfileLevel profileLevel)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v7; // eax
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AMP::ViewStats *Stats; // ecx

  this->Stats = viewStats;
  this->SwdHandle = swdHandle;
  this->PC = pc;
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
    this->StartTicks = ProfileTicks;
    Scaleform::GFx::AMP::ViewStats::PushCallstack(Stats, swdHandle, pc, ProfileTicks);
  }
  else
  {
    LODWORD(this->StartTicks) = 0;
    HIDWORD(this->StartTicks) = 0;
  }
}
