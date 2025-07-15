void __thiscall Scaleform::GFx::AMP::ScopeFunctionTimer::~ScopeFunctionTimer(
        Scaleform::GFx::AMP::ScopeFunctionTimer *this)
{
  unsigned __int64 ProfileTicks; // rax

  if ( this->Stats )
  {
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    Scaleform::GFx::AMP::ViewStats::PopCallstack(
      this->Stats,
      (Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>)this->SwdHandle,
      this->PC,
      ProfileTicks - this->StartTicks);
  }
}
