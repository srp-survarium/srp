bool __thiscall Scaleform::GFx::AMP::ViewStats::IsDebugPaused(Scaleform::GFx::AMP::ViewStats *this)
{
  return !this->DebugEvent.IsSignaled(&this->DebugEvent);
}
